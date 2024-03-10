#include <iostream>
#include <string>
using namespace std;


struct data_klub
{
    string nama_klub, stadion, pelatih, kapten;
};

string nama, nim, nama_baru, hapus_nama;
const int maks = 20;
data_klub klub[maks];
int ulang = 3, pilihan, isi_data = 0, i, j;


void menu()
{
    cout << "Pilihan Menu : " << endl;
    cout << "1) Tambah Data Klub" << endl;
    cout << "2) Baca Data Klub" << endl;
    cout << "3) Perbarui Data Klub" << endl;
    cout << "4) Hapus Data Klub" << endl;
    cout << "5) Keluar" << endl;
}

void tambah_klub()
{
    if(isi_data < maks)
    {
        cout << "Nama Klub : ";
        cin.ignore();
        getline(cin, klub[isi_data].nama_klub);
        cout << "Nama Stadion : ";
        getline(cin, klub[isi_data].stadion);
        cout << "Nama Pelatih : ";
        getline(cin, klub[isi_data].pelatih);
        cout << "Nama Kapten : ";
        getline(cin, klub[isi_data].kapten);
        system("cls");
        cout << "Data Klub berhasil ditambahkan." << endl;
        cin.clear();
        isi_data++;
    }
    else
    {
        system("cls");
        cout << "Data Klub sudah penuh. Silahkan menghapus data jika ingin menambah data baru." << endl;
    }
}

void baca_klub()
{
    if (isi_data == 0) 
    {
        cout << "Data klub masih kosong." << endl;
    } 
    else 
    {
        cout << "Data Klub:" << endl;
        for (i = 0; i < isi_data; i++) {
            cout << "Nama Klub : " << klub[i].nama_klub
            << ", Nama Stadion : " << klub[i].stadion
            << ", Nama Pelatih : " << klub[i].pelatih
            << ", Nama Kapten : " << klub[i].kapten << endl;
        }
    }
}

void perbarui_klub()
{
    if(isi_data == 0)
    {
        system("cls");
        cout << "Data klub masih kosong." << endl;
        return;
    }
    baca_klub();
    cout << "Masukkan nama Klub yang ingin diganti : ";
    cin.ignore();
    getline(cin, nama_baru);
    cin.clear();
    for(i = 0; i < isi_data; i++)
    {
        if(nama_baru == klub[i].nama_klub)
        {
            cout << "Nama Klub : ";
            getline(cin, klub[i].nama_klub);
            cout << "Nama Stadion : ";
            getline(cin, klub[i].stadion);
            cout << "Nama Pelatih : ";
            getline(cin, klub[i].pelatih);
            cout << "Nama Kapten : ";
            getline(cin, klub[i].kapten);
            system("cls");
            cout << "Data Klub " << nama_baru << " berhasil diperbaharui menjadi " << klub[i].nama_klub << endl;
            cin.clear();
            return;
        }
    }
    system("cls");
    cout << "Data Klub tidak ditemukan." << endl;
}

void hapus_klub()
{
    if(isi_data == 0)
    {
        cout << "Data klub masih kosong." << endl;
        return;
    }
    baca_klub();
    cout << "Masukkan nama Klub yang ingin dihapus : ";
    cin.ignore();
    getline(cin, hapus_nama);
    bool found = false;
    for(i = 0; i < isi_data; i++)
    {
        if(hapus_nama == klub[i].nama_klub)
        {
            for (int j = i; j < isi_data - 1; j++) 
            {
                klub[j] = klub[j + 1];
            }
            isi_data--;
            system("cls");
            cout << "Data Klub " << hapus_nama << " berhasil dihapus." << endl;
            found = true;
        }
    }
    if(!found)
    {
        system("cls");
        cout << "Data Klub tidak ditemukan.";
    }
}

int main()
{
    while(true)
    {
        cout << "Nama : ";
        getline(cin, nama);
        cout << "NIM : ";
        cin >> nim;
        cin.ignore();
        if(nama == "celio" && nim == "39")
        {
            system("cls");
            cout << "Login berhasil. Selamat datang " << nama << "!" << endl;
            while(true)
            {   
                menu();
                cout << "Pilih (1/2/3/4/5) : ";
                cin >> pilihan;
                cin.clear();
                system("cls");
                if(pilihan == 1)
                {
                    tambah_klub();
                }
                else if(pilihan == 2)
                {
                    baca_klub();
                }
                else if(pilihan == 3)
                {
                    perbarui_klub();
                }
                else if(pilihan == 4)
                {
                    hapus_klub();
                }
                else if(pilihan == 5)
                {
                    break;
                }
                else
                {
                    system("cls");
                    cout << "Pilihan tidak valid. Silahkan coba lagi." << endl;
                }
            }
            system("cls");
            cout << "Anda telah keluar." << endl;
            break;
        }
        else if(ulang == 0)
        {
            system("cls");
            cout << "Kesempatan Anda telah habis." << endl;
            break;
        }
        else
        {
            system("cls");
            ulang--;
            cout << "Nama atau NIM Anda salah. Kesempatan sisa : " << ulang << endl;
        }
    }
    return 0;
}