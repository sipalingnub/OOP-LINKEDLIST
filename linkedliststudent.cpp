#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define PURPLE  "\033[95m"
#define BROWN   "\033[33m"

// Class Student
class Student {
private:
    string name;
    string email;
    string phone;
public:
    // Constructor
    Student(string n, string e, string p) : name(n), email(e), phone(p) {}

    // Getter name
    string getName() const {
        return name;
    }

    // Getter phone
    string getPhone() const {
        return phone;
    }

    // Getter email
    string getEmail() const {
        return email;
    }

    // Fungsi untuk menampilkan data Student
    void display() const {
        cout << CYAN << "Name: " << RESET << name << endl;
        cout << CYAN << "Email: " << RESET << email << endl;
        cout << CYAN << "Phone: " << RESET << phone << endl;
        cout << "---------------------" << endl;
    }
};

// Fungsi Sequential Search berdasarkan Phone
Student* searchStudentByPhone(list<Student*> &students, string phone) {
    for (auto it = students.begin(); it != students.end(); it++) {
        if ((*it)->getPhone() == phone) {
            return *it;
        }
    }
    return nullptr;
}

// Fungsi untuk menampilkan menu
void displayMenu() {
    cout << YELLOW << "============================================================================================================================" << RESET << endl;
    cout << MAGENTA << ".%%...%%..%%%%..%%..%%..%%%%...%%%%..%%%%%%..%%%%..%%...%%..%%%%..........%%%%...%%%%..%%..%%.%%..%%.%%%%%%..%%%%..%%%%%%." << RESET << endl;
    cout << MAGENTA << ".%%%.%%%.%%..%%.%%..%%.%%..%%.%%.......%%...%%.....%%...%%.%%..%%........%%..%%.%%..%%.%%%.%%.%%%.%%.%%.....%%..%%...%%..." << RESET << endl;
    cout << MAGENTA << ".%%.%.%%.%%%%%%.%%%%%%.%%%%%%..%%%%....%%....%%%%..%%.%.%%.%%%%%%........%%.....%%..%%.%%.%%%.%%.%%%.%%%%...%%.......%%..." << RESET << endl;
    cout << MAGENTA << ".%%...%%.%%..%%.%%..%%.%%..%%.....%%...%%.......%%.%%%%%%%.%%..%%........%%..%%.%%..%%.%%..%%.%%..%%.%%.....%%..%%...%%..." << RESET << endl;
    cout << MAGENTA << ".%%...%%.%%..%%.%%..%%.%%..%%..%%%%..%%%%%%..%%%%...%%.%%..%%..%%.........%%%%...%%%%..%%..%%.%%..%%.%%%%%%..%%%%....%%..." << RESET << endl;
    cout << MAGENTA << ".........................................................................................................................." << RESET << endl;
    cout << YELLOW << "============================================================================================================================" << RESET << endl;
    cout << BLUE << "1. Tampilkan Daftar Mahasiswa" << RESET << endl;
    cout << BLUE << "2. Urutkan Berdasarkan Nama (DESCENDING)" << RESET << endl;
    cout << BLUE << "3. Urutkan Berdasarkan Phone (ASCENDING)" << RESET << endl;
    cout << BLUE << "4. Cari Mahasiswa Berdasarkan Phone" << RESET << endl;
    cout << BLUE << "5. Tambahkan Mahasiswa Baru" << RESET << endl;
    cout << RED << "6. Hapus Mahasiswa" << RESET << endl;
    cout << RED << "7. Keluar" << RESET << endl;
    cout << YELLOW << "============================================================================================================================" << RESET << endl;
    cout << "Pilih opsi: " << endl;
}

//fungsi menambahkan mahasiswa
void addStudent(list<Student*> &students) {
    string name, email, phone;
    cout << "Masukkan nama mahasiswa: ";
    cin.ignore(); //clear input buffer
    getline(cin, name);
    cout << "Masukkan email mahasiswa: ";
    getline(cin, email);
    cout << "Masukkan nomor telepon mahasiswa: ";
    getline(cin, phone);

    students.push_back(new Student(name, email, phone));
    cout << GREEN << "Mahasiswa berhasil ditambahkan! horray" << RESET << endl;
}

//fungsi menghapus mahasiswa
void deleteStudent(list<Student*> &students) {
    string phone;
    cout << "Masukkan nomor telepon mahasiswa yang ingin dihapus: ";
    cin >> phone;

    Student* student = searchStudentByPhone(students, phone);
    if (student != nullptr) {
        students.remove(student);
        delete student;
        cout << GREEN << "Mahasiswa berhasil dihapus! horray" << RESET << endl;
    } else {
        cout << RED << "Mahasiswa tidak ditemukan, maafkan saya." << RESET << endl;
    }
}

int main() {
    // Membuat linked list dari class Student
    list<Student*> students;

    // Menambahkan objek Student ke linked list
    students.push_back(new Student("Budi Tartanto", "buditart@gmail.com", "08123456789"));
    students.push_back(new Student("Ani Suparman", "anitamaxwin@gmail.com", "08123456788"));
    students.push_back(new Student("Joko Susilo", "jokosilat@gmail.com", "08123456787"));
    students.push_back(new Student("Dewi Lestari", "dewilettari@gmail.com", "08123456786"));
    students.push_back(new Student("Rizki Ramadhan", "rizkisumpahan@gmail.com", "08123456785"));
    students.push_back(new Student("Khairul Yahya", "khairulyahya@gmail.com", "08123456784"));

    int choice;
    string phoneNumber;
    Student* student = nullptr; // Deklarasi variabel di luar switch-case

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Student List:" << endl;
                cout << "=================================" << endl;
                // Menampilkan semua data Student dalam linked list
                for (auto it = students.begin(); it != students.end(); it++) {
                    (*it)->display();
                }
                break;

            case 2:
                // Mengurutkan berdasarkan nama DESCENDING
                students.sort([](Student* a, Student* b) {
                    return a->getName() > b->getName(); // DESCENDING
                });
                cout << "Student List setelah diurutkan berdasarkan nama (DESCENDING):" << endl;
                cout << "======================" << endl;
                for (auto it = students.begin(); it != students.end(); it++) {
                    (*it)->display();
                }
                break;

            case 3:
                // Mengurutkan berdasarkan phone ASCENDING
                students.sort([](Student* a, Student* b) {
                    return a->getPhone() < b->getPhone(); // ASCENDING
                });
                cout << "Student List setelah diurutkan berdasarkan phone (ASCENDING):" << endl;
                cout << "======================" << endl;
                for (auto it = students.begin(); it != students.end(); it++) {
                    (*it)->display();
                }
                break;

            case 4:
                cout << "Masukkan nomor telepon yang ingin dicari: ";
                cin >> phoneNumber;
                // Mencari Student berdasarkan phone number
                student = searchStudentByPhone(students, phoneNumber); // Gunakan variabel yang sudah dideklarasikan
                if (student != nullptr) {
                    cout << "Mahasiswa ditemukan:" << endl;
                    student->display();
                } else {
                    cout << "Mahasiswa tidak ditemukan, maafkan saya." << endl;
                }
                break;

            case 5:
                //tambah mahasiswa
                addStudent(students);
                break;
            
            case 6:
                //hapus mahasiswa
                deleteStudent(students);
                break;
            
            case 7:
                cout << GREEN << "Terima kasih telah menggunakan program ini!" << RESET << endl;
                break;

            default:
                cout << RED << "Opsi tidak valid, silakan coba lagi." << RESET << endl;
                break;
        }
    } while (choice != 7);
    // Menghapus semua objek Student dalam linked list
    for (auto it = students.begin(); it != students.end(); it++) {
        delete *it;
    }
    return 0;
}