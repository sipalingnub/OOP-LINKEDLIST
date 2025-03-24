#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>
using namespace std;

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

//kelas barang
class Barang {
    private:
    string tanggal;
    string namaBarang;
    string kodeBarang;
    string kategori;
    double hargajual;
    int qty;

    public:
    //constructor
    Barang(string tgl, string kode, string nama, string kat, double harga, int jumlah) 
    : tanggal(tgl), kodeBarang(kode), namaBarang(nama), kategori(kat), hargajual(harga), qty(jumlah) {}

    //getter
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

    //fungsi untuk menampilkan data barang
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

    //fungsi sequential search berdasarkan kode barang
    Barang* searchBarangbyKode(list<Barang*> &barangList, string kode){
        for (auto it = barangList.begin(); it != barangList.end(); it++) {
            if ((*it)->getKodeBarang() == kode) {
                return *it;
            }
        }
        return nullptr;
    }

    //display menu
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

    void displayBarangbyKategori(const list<Barang*> &barangList, string kategori) {
        cout << "Barang dengan kategori " << kategori << ":" << endl;
        cout << "=================================" << endl;
        for (auto it = barangList.begin(); it != barangList.end(); it++) {
            if ((*it)->getKategori() == kategori) {
                (*it)->display();
            }
        }
    }

    int main() {
        //membuat linked list dari class barang
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

                //nampilin semua data barang dalam linked list
                for (auto it = barangList.begin(); it != barangList.end(); it++) {
                    (*it)->display();
                }
                break;

                case 2:
                //mengurutkan berdasarkan nama ASCENDING
                barangList.sort([](Barang* a, Barang* b) {
                    return a->getNamaBarang() < b->getNamaBarang(); //ASCENDING
                });
                cout << GREEN << "Daftar Barang setelah diurutkan berdasarkan nama (ASCENDING):" << RESET << endl;
                cout << YELLOW << "=====================================================" << RESET << endl;
                for (auto it = barangList.begin(); it != barangList.end(); it++) {
                    (*it)->display();
                }
                break;

                case 3:
                //mengurutkan harga jual DESCENDING
                barangList.sort([](Barang* a, Barang* b) {
                    return a->getHargaJual() > b->getHargaJual(); //DESCENDING
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
                //mencari barang berdasarkan kode barang
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
                //nampilin barang berdasarkan kategori
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
        //menghapus semua objek barang dalam linked list
        for (auto it = barangList.begin(); it != barangList.end(); it++) {
            delete *it;
        }

        return 0;
    }