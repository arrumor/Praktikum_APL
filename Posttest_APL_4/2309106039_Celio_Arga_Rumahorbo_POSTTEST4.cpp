#include <iostream>
#include <string>
using namespace std;

struct statistik
{
    int gol, bobol, menang, seri, kalah;
};

struct data_klub
{
    string nama_klub; 
    statistik stat;
};

string nama, nim, nama_baru, hapus_nama;
const int maks = 20;
data_klub klub[maks];
int ulang = 3, pilihan, isi_data = 0, i, j;


void menu()
{
    cout << "Pilihan Menu : " << endl;
    cout << "1) Tambah Data Klub" << endl;
    cout << "2) Lihat Data Klub" << endl;
    cout << "3) Perbarui Data Klub" << endl;
    cout << "4) Hapus Data Klub" << endl;
    cout << "5) Keluar" << endl;
}

int selisih(int gol, int bobol)
{
    int hasil = gol-bobol;
    return hasil;
}

int poin(int menang, int seri, int kalah)
{
    int poin_menang = menang * 3;
    int poin_seri = seri * 1;
    int poin_kalah = kalah * 0;
    int jumlah_poin = poin_menang + poin_seri + poin_kalah;
    return jumlah_poin;
}

void tambah_klub()
{
    if(isi_data < maks)
    {   

        cout << "Nama Klub : ";
        cin.ignore();
        getline(cin, klub[isi_data].nama_klub);
        cout << "Jumlah Gol Masuk : ";
        if(!(cin >> klub[isi_data].stat.gol))
        {
            system("cls");
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Jumlah gol masuk harus berupa angka." << endl;
            return;
        }
        cout << "Jumlah Gol Kebobolan : ";
        if(!(cin >> klub[isi_data].stat.bobol))
        {
            system("cls");
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Jumlah gol kebobolan harus berupa angka." << endl;
            return;
        }
        cout << "Jumlah Menang : ";
        if(!(cin >> klub[isi_data].stat.menang))
        {
            system("cls");
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Jumlah menang harus berupa angka." << endl;
            return;
        }
        cout << "Jumlah Seri : ";
        if(!(cin >> klub[isi_data].stat.seri))
        {
            system("cls");
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Jumlah seri harus berupa angka." << endl;
            return;
        }
        cout << "Jumlah Kalah : ";
        if(!(cin >> klub[isi_data].stat.kalah))
        {
            system("cls");
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Jumlah kalah harus berupa angka." << endl;
            return;
        }
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

void lihat_klub()
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
            << ", Jumlah Gol Masuk : " << klub[i].stat.gol
            << ", Jumlah Gol Kebobolan : " << klub[i].stat.bobol 
            << ", Selisih Gol : " << selisih(klub[i].stat.gol, klub[i].stat.bobol) 
            << ", Menang : " << klub[i].stat.menang 
            << ", Seri : " << klub[i].stat.seri 
            << ", Kalah : " << klub[i].stat.kalah 
            << ", Poin : " << poin(klub[i].stat.menang, klub[i].stat.seri, klub[i].stat.kalah) << endl;
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
    lihat_klub();
    cout << "Masukkan nama Klub yang ingin diganti : ";
    cin.ignore();
    getline(cin, nama_baru);
    cin.clear();
    for(i = 0; i < isi_data; i++)
    {
        if(nama_baru == klub[i].nama_klub)
        {
            cout << "Nama Klub : ";
            cin.ignore();
            getline(cin, klub[isi_data].nama_klub);
            cout << "Jumlah Gol Masuk : ";
            if(!(cin >> klub[isi_data].stat.gol))
            {
                system("cls");
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Jumlah gol masuk harus berupa angka." << endl;
                return;
            }
            cout << "Jumlah Gol Kebobolan : ";
            if(!(cin >> klub[isi_data].stat.bobol))
            {
                system("cls");
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Jumlah gol kebobolan harus berupa angka." << endl;
                return;
            }
            cout << "Jumlah Menang : ";
            if(!(cin >> klub[isi_data].stat.menang))
            {
                system("cls");
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Jumlah menang harus berupa angka." << endl;
                return;
            }
            cout << "Jumlah Seri : ";
            if(!(cin >> klub[isi_data].stat.seri))
            {
                system("cls");
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Jumlah seri harus berupa angka." << endl;
                return;
            }
            cout << "Jumlah Kalah : ";
            if(!(cin >> klub[isi_data].stat.kalah))
            {
                system("cls");
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Jumlah kalah harus berupa angka." << endl;
                return;
            }
        }
    }
    system("cls");
    cout << "Data Klub tidak ditemukan." << endl;
}

void hapus_klub_rekursif(int indeks)
{
    if(indeks == isi_data) 
    {
        cout << "Data Klub tidak ditemukan." << endl;
        return;
    }
    if(hapus_nama == klub[indeks].nama_klub) 
    {
        for(int j = indeks; j < isi_data - 1; j++) 
        {
            klub[j] = klub[j + 1];
        }
        isi_data--;
        system("cls");
        cout << "Data Klub " << hapus_nama << " berhasil dihapus." << endl;
        return;
    }
    hapus_klub_rekursif(indeks + 1);
}

void hapus_klub() 
{
    if(isi_data == 0) 
    {
        system("cls");
        cout << "Data klub masih kosong." << endl;
        return;
    }
    lihat_klub();
    cout << "Masukkan nama Klub yang ingin dihapus : ";
    cin.ignore();
    getline(cin, hapus_nama);
    hapus_klub_rekursif(0);
}


int main()
{
    while(ulang >= 0)
    {
        cout << "Nama : ";
        getline(cin, nama);
        cout << "NIM : ";
        getline(cin, nim);
        if((nama == "celio") && (nim == "39"))
        {
            system("cls");
            cout << "Login berhasil. Selamat datang " << nama << "!" << endl;
            while(true)
            {   
                menu();
                cout << "Pilih (1/2/3/4/5) : ";
                if(!(cin >> pilihan))
                {
                    system("cls");
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Pilihan harus berupa angka." << endl;
                    continue;
                }
                system("cls");
                if(pilihan == 1)
                {
                    tambah_klub();
                }
                else if(pilihan == 2)
                {
                    lihat_klub();
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