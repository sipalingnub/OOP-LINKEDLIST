# 5-4 Latihan Linked List

## Dibuat Oleh

**5027241092 - Muhammad Khairul Yahya**

## Daftar Isi

- [Latihan 1 - Membuat Daftar Mahasiswa](#latihan-1)
- [Latihan 2 - Membuat Daftar Barang](#latihan-2)


# Latihan 1
_**Membuat Daftar Mahasiswa**_

## Deskripsi Soal
- Buat linked list yang elemennya adalah class Student, student memiliki data antara lain nama, email, dan phone.
- Tambahkan method: Sort berdasarkan nama.
- Tambahkan method: Search berdasarkan nama.
- Dsb.

## Jawaban: `linkedliststudent.cpp`
Pertama-tama saya menggunakan ANSI escape codes yang digunakan untuk hiasan warna.
```cpp
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define PURPLE  "\033[95m"
#define BROWN   "\033[33m"
```
Penjelasan:
- Semua fungsi di atas digunakan untuk mengubah warna teks di terminal.

Lalu untuk **Student Class** saya membuat sebuah class yang memiliki atribut nama, email, dan phone:
```cpp
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

    // Function to display student data
    void display() const {
        cout << CYAN << "Name: " << RESET << name << endl;
        cout << CYAN << "Email: " << RESET << email << endl;
        cout << CYAN << "Phone: " << RESET << phone << endl;
        cout << "---------------------" << endl;
    }
};
```
Penjelasan:
- `Student` **class** : Menampilkan murid dengan atribut `nama`, `email`, dan `phone`.
- **Constructor** : Inisialisasi murid dengan nama, email, dan nomor telepon yang disediakan.
- **Getter** : Menyediakan akses ke atribut `private`
- `display()` : Menampilkan informasi mahasiswa dengan atribut-atributnya.

Lalu saya membuat **Sequential Search Function** untuk mencari data mahasiswa berdasarkan nama, email, atau nomor telepon:
```cpp
Student* searchStudentByPhone(list<Student*> &students, string phone) {
    for (auto it = students.begin(); it != students.end(); it++) {
        if ((*it)->getPhone() == phone) {
            return *it;
        }
    }
    return nullptr;
}
```
Penjelasan:
- `searchStudentByPhone()` : Mencari data mahasiswa berdasarkan nomor telepon.
- `list<Student*>` : Daftar mahasiswa.
- string `phone` : Nomor telepon yang dicari.
- `return *it` : mengembalikan referensi ke mahasiswa yang ditemukan.
- `return nullptr` : mengembalikan `nullptr` jika tidak ada mahasiswa yang ditemukan.

Lalu disini untuk **UI/ Display Menu Function-nya** berbentuk seperti ini:
```cpp
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
```
Penjelasan:
- `displayMenu()` : Menampilkan menu dengan opsi untuk user berinteraksi dengan list mahasiswa.
- `cout` : Output ke layar.
- `YELLOW`, `MAGENTA`, `BLUE`, `RED` : Warna yang digunakan untuk hiasan, terutama untuk ASCII ART

**Add Student Function**, fungsi untuk menambahkan mahasiswa dalam list:
```cpp
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
```
Penjelasan:
- `addStudent(list<Student*> &students)` : Fungsi untuk menambahkan mahasiswa
- `cin.ignore()` : Membersihkan buffer input agar tidak ada masalah saat menggunakan `getlin

**Delete Student Function**, fungsi untuk menghapus mahasiswa dalam list:
```cpp
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
```
Penjelasan:
- `deleteStudent(list<Student*> &students)` : Fungsi untuk menghapus mahasiswa berdasarkan nomor telepon, dan menghapusnya dari list mahasiswa.
- `searchStudentByPhone(students, phone)` : Fungsi untuk mencari mahasiswa berdasarkan nomor telepon.

**Main Function**
```cpp
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
```
Penjelasan:
- `main()` : entry point dari program.
- `students` : linked list yang digunakan untuk menyimpan objek `Student`.
- `choice` : variabel yang digunakan untuk menyimpan pilihan pengguna.
- `student` : variabel yang digunakan untuk menyimpan objek `Student` yang sedang dicari.
- **Initialization** : Membuat list mahasiswa dan membuat 3 objek mahasiswa.
- **Menu Loop** : Menampilkan menu dan proses user dari pilihan-nya.
- **Switch-Case** : Menangani setiap pilihan pengguna dengan menggunakan switch-case.
- **Cleanup** : Menghapus semua objek student untuk membebaskan memori sebelum program berakhir.

## Dokumentasi Output:

**UI/ Display Menu Function**
![image alt](https://github.com/sipalingnub/OOP-LINKEDLIST/blob/61ce2183ea9cf76a98e9162ceb8af10593e86494/asetgambar/Screenshot%202025-03-23%20210004.png)

**List Mahasiswa**
![image alt](https://github.com/sipalingnub/OOP-LINKEDLIST/blob/61ce2183ea9cf76a98e9162ceb8af10593e86494/asetgambar/Screenshot%202025-03-24%20141105.png)

**Menambahkan Mahasiswa**
![image alt](https://github.com/sipalingnub/OOP-LINKEDLIST/blob/61ce2183ea9cf76a98e9162ceb8af10593e86494/asetgambar/Screenshot%202025-03-24%20141140.png)

di list mahasiswa setelah ditambahkan:
![image alt](https://github.com/sipalingnub/OOP-LINKEDLIST/blob/61ce2183ea9cf76a98e9162ceb8af10593e86494/asetgambar/Screenshot%202025-03-24%20141153.png)

**Menghapus Mahasiswa**
![image alt](https://github.com/sipalingnub/OOP-LINKEDLIST/blob/61ce2183ea9cf76a98e9162ceb8af10593e86494/asetgambar/Screenshot%202025-03-24%20141210.png)

di list mahasiswa setelah dihapus:
![image alt](https://github.com/sipalingnub/OOP-LINKEDLIST/blob/61ce2183ea9cf76a98e9162ceb8af10593e86494/asetgambar/Screenshot%202025-03-24%20141218.png)

**Mengurutkan mahasiswa berdasarkan nama (DESCENDING):**
![image alt](https://github.com/sipalingnub/OOP-LINKEDLIST/blob/61ce2183ea9cf76a98e9162ceb8af10593e86494/asetgambar/Screenshot%202025-03-24%20141836.png)

**Mengurutkan mahasiswa berdasarkan phone (ASCENDING):**
![image alt](https://github.com/sipalingnub/OOP-LINKEDLIST/blob/61ce2183ea9cf76a98e9162ceb8af10593e86494/asetgambar/Screenshot%202025-03-24%20141844.png)

**Mencari mahasiswa berdasarkan nomor telepon:**
![image alt](https://github.com/sipalingnub/OOP-LINKEDLIST/blob/61ce2183ea9cf76a98e9162ceb8af10593e86494/asetgambar/Screenshot%202025-03-24%20141901.png)

**Keluar dari Program**
![image alt](https://github.com/sipalingnub/OOP-LINKEDLIST/blob/61ce2183ea9cf76a98e9162ceb8af10593e86494/asetgambar/Screenshot%202025-03-24%20141227.png)

# Latihan 2
_**Membuat Daftar Barang**_

## Deskripsi Soal:
- Buat linked list yang elemennya adalah class Barang
- Class Barang memiliki data seperti pada gambar
- Tambah sejumlah kategori barang misalnya: ATK, Elektronik, Pakaian, dll
- Dst idem Latihan 1 dengan menambah fungsi Sort() dan Search()
- Tambah fungsi khusus, misalnya untuk menampilkan barang kategori tertentu

## Gambar untuk data class barang:
![image alt]()

## Jawaban: `linkedlistbarang.cpp`

Pertama-tama saya menggunakan library seperti berikut:
```cpp
#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>
using namespace std;
```
Penjelasan:
- `<iostream>` : menyediakan operasi input & output.
- `<list>` : menyediakan linked list.
- `<algorithm>` : menyediakan fungsi-fungsi algoritma.
- `<iomanip>` : menyediakan fungsi untuk mengatur format output.
- `using namespace std;` : mengimport semua nama dari namespace std.

Lalu saya menggunakan hiasan **ANSI Escape Codes** untuk hiasan warna pada code:
```cpp
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
```

Lalu untuk struktur class **Barang** seperti berikut:
```cpp
class Barang {
private:
    string tanggal;
    string namaBarang;
    string kodeBarang;
    string kategori;
    double hargajual;
    int qty;

public:
    // Constructor
    Barang(string tgl, string kode, string nama, string kat, double harga, int jumlah) 
    : tanggal(tgl), kodeBarang(kode), namaBarang(nama), kategori(kat), hargajual(harga), qty(jumlah) {}

    // Getters
    string getTanggal() const {
        return tanggal;
    }
    string getNamaBarang() const {
        return namaBarang;
    }
    string getKodeBarang() const {
        return kodeBarang;
    }
    string getKategori() const {
        return kategori;
    }
    double getHargaJual() const {
        return hargajual;
    }
    int getQty() const {
        return qty;
    }

    // Function to display item data
    void display() const {
        cout << CYAN << "Tanggal: " << RESET << tanggal << endl;
        cout << CYAN << "Kode Barang: " << RESET << kodeBarang << endl;
        cout << CYAN << "Nama Barang: " << RESET << namaBarang << endl;
        cout << CYAN << "Qty: " << RESET << qty << endl;
        cout << CYAN << "Harga Jual: " << RESET << "Rp" << fixed << setprecision(2) << hargajual << endl;
        cout << CYAN << "Kategori: " << RESET << kategori << endl;
        cout << "---------------------" << endl;
    }
};
```
Penjelasan:
- `Barang` **Class**: Mempresentasikan barang dengan atribut -atribut yang relevan seperti tanggal (`tanggal`), kode (`kodeBarang`), nama (`namaBarang`), kategori (`kategori`), harga jual (`hargajual`), dan quantity (`qty`).
- **Constructor**: inisialisasi atribut-atribut class `Barang` dengan parameter yang sesuai.
- **Getters**: fungsi yang digunakan untuk mengakses nilai atribut-atribut
- **display()**: fungsi yang digunakan untuk menampilkan data barang dalam format yang lebih rapi.

Lalu ada fungsi **Display Menu Function**, yang berfungsi untuk menampilkan UI/ tampilan utama dari program itu. Skripnya:
```cpp
void displayMenu() {
    cout << YELLOW << "===============================================================================================================================================================" << RESET << endl;
    cout << BLUE << "      :::    ::: ::::::::  :::::::::  :::::::::: :::::::::      :::      :::::::: :::::::::::           :::    ::: ::::::::  :::::::::  :::    ::: ::::::::: " << RESET << endl;
    cout << BLUE << "     :+:   :+: :+:    :+: :+:    :+: :+:        :+:    :+:   :+: :+:   :+:    :+:    :+:               :+:   :+: :+:    :+: :+:    :+: :+:    :+: :+:    :+: " << RESET << endl;
    cout << BLUE << "    +:+  +:+  +:+    +:+ +:+    +:+ +:+        +:+    +:+  +:+   +:+  +:+           +:+               +:+  +:+  +:+    +:+ +:+    +:+ +:+    +:+ +:+    +:+  " << RESET << endl;
    cout << BLUE << "   +#++:++   +#+    +:+ +#++:++#+  +#++:++#   +#++:++#:  +#++:++#++: +#++:++#++    +#+               +#++:++   +#+    +:+ +#++:++#:  +#+    +:+ +#++:++#+    " << RESET << endl;
    cout << BLUE << "  +#+  +#+  +#+    +#+ +#+        +#+        +#+    +#+ +#+     +#+        +#+    +#+               +#+  +#+  +#+    +#+ +#+    +#+ +#+    +#+ +#+           " << RESET << endl;
    cout << BLUE << " #+#   #+# #+#    #+# #+#        #+#        #+#    #+# #+#     #+# #+#    #+#    #+#               #+#   #+# #+#    #+# #+#    #+# #+#    #+# #+#            " << RESET << endl;
    cout << BLUE << "###    ### ########  ###        ########## ###    ### ###     ###  ######## ###########           ###    ### ########  ###    ###  ########  ###             " << RESET << endl;
    cout << YELLOW << "===============================================================================================================================================================" << RESET << endl;
    cout << CYAN << "1. Tampilkan Daftar Barang" << endl;
    cout << CYAN << "2. Urutkan Berdasarkan Nama (ASCENDING)" << endl;
    cout << CYAN << "3. Urutkan Berdasarkan Harga Jual (ASCENDING)" << endl;
    cout << CYAN << "4. Cari Barang Berdasarkan Kode Barang" << endl;
    cout << CYAN << "5. Tampilkan Barang Berdasarkan Kategori" << endl;
    cout << RED << "6. Keluar" << endl;
    cout << YELLOW << "=========================================" << RESET << endl;
    cout << "Pilih opsi: ";
}
```
Penjelasan:
ini berfungsi untuk menampilkan menu utama dari program, dengan menggunakan beberapa fungsi `cout` untuk menampilkan teks dan simbol-simbol khusus. Menu ini menampilkan beberapa opsi,
- Tampilkan Daftar Barang
- Urutkan Berdasarkan Nama (ASCENDING)
- Urutkan Berdasarkan Harga Jual (ASCENDING)
- Cari Barang Berdasarkan Kode Barang
- Tampilkan Barang Berdasarkan Kategori
- Keluar, **untuk mengakhiri program**

Lalu untuk fungsi menampilkan barang berdasarkan kategori, **Display Items by Categori Function**:
```cpp
void displayBarangbyKategori(const list<Barang*> &barangList, string kategori) {
    cout << "Barang dengan kategori " << kategori << ":" << endl;
    cout << "=================================" << endl;
    for (auto it = barangList.begin(); it != barangList.end(); it++) {
        if ((*it)->getKategori() == kategori) {
            (*it)->display();
        }
    }
}
```
Penjelasan:
ini berfungsi untuk menampilkan daftar barang yang memiliki kategori tertentu. Fungsi ini menerima dua parameter: `barangList` (daftar barang) dan `kategori` (kategori barang). Fungsi ini kemudian mencari barang yang memiliki kategori yang sesuai dan menampilkan kategori spesifik yang dicari.

Sehingga bentuk dari fungsi **Main**, yaitu:
```cpp
int main() {
    // Create a linked list of Barang objects
    list<Barang*> barangList;
    barangList.push_back(new Barang("03/01/2021", "A-000001", "Pulpen Pink", "ATK", 3500, 11));
    barangList.push_back(new Barang("05/01/2021", "B-000256", "Pulpen Blue", "ATK", 3500, 41));
    barangList.push_back(new Barang("08/01/2021", "C-565405", "Pulpen Yellow", "ATK", 3500, 60));
    barangList.push_back(new Barang("06/01/2021", "D-156433", "Pulpen Brown", "ATK", 3500, 50));
    barangList.push_back(new Barang("09/01/2021", "A-136435", "Pulpen Black", "ATK", 3500, 100));

    int choice;
    string kodeBarang, kategori;
    Barang* foundbarang = nullptr;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << YELLOW << "Daftar Barang:" << RESET << endl;
                cout << YELLOW << "=========================" << RESET << endl;
                // Display all items in the list
                for (auto it = barangList.begin(); it != barangList.end(); it++) {
                    (*it)->display();
                }
                break;

            case 2:
                // Sort by name (ASCENDING)
                barangList.sort([](Barang* a, Barang* b) {
                    return a->getNamaBarang() < b->getNamaBarang(); // ASCENDING
                });
                cout << GREEN << "Daftar Barang setelah diurutkan berdasarkan nama (ASCENDING):" << RESET << endl;
                cout << YELLOW << "=====================================================" << RESET << endl;
                for (auto it = barangList.begin(); it != barangList.end(); it++) {
                    (*it)->display();
                }
                break;

            case 3:
                // Sort by price (DESCENDING)
                barangList.sort([](Barang* a, Barang* b) {
                    return a->getHargaJual() > b->getHargaJual(); // DESCENDING
                });
                cout << GREEN << "Daftar Barang setelah diurutkan berdasarkan harga jual (DESCENDING):" << RESET << endl;
                cout << YELLOW << "=====================================================" << RESET << endl;
                for (auto it = barangList.begin(); it != barangList.end(); it++) {
                    (*it)->display();
                }
                break;

            case 4: {
                cout << "Masukkan kode barang yang dicari: ";
                cin >> kodeBarang;
                // Search for an item by its code
                foundbarang = searchBarangbyKode(barangList, kodeBarang);
                if (foundbarang != nullptr) {
                    cout << GREEN << "Barang ditemukan:" << RESET << endl;
                    foundbarang->display();
                } else {
                    cout << RED << "Barang tidak ditemukan, maafkan saya." << RESET << endl;
                }
                break;
            }

            case 5:
                cout << "Masukkan kategori barang yang ingin ditampilkan: ";
                cin >> kategori;
                // Display items by category
                displayBarangbyKategori(barangList, kategori);
                break;

            case 6:
                cout << GREEN << "Terima kasih telah menggunakan program ini." << RESET << endl;
                break;

            default:
                cout << RED << "Opsi tidak valid, silahkan coba lagi." << RESET << endl;
                break;
        }
    } while (choice != 6);

    // Clean up: Delete all Barang objects in the list
    for (auto it = barangList.begin(); it != barangList.end(); it++) {
        delete *it;
    }

    return 0;
}
```
Penjelasan:
- **Inisial**: Membuat list dari barang dan menambah kan beberapa contoh barang ke dalam list.
- **Menu Loop**: Menampilkan menu dan proses user input.
- **Switch-Case**: menangani pilihan user dengan menggunakan switch-case dari fitur yang tersedia.
- **Cleanup**: Menghapus semua objek Barang di dalam list setelah program selesai.

## Dokumentasi Output:

**Tampilan UI/Menu:**
![image alt]()

**Tampilan List Barang:**
![image alt]()






