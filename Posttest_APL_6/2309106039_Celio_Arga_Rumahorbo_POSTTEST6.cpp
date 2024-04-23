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
    cout << "5) Urutkan Data Klub" << endl;
    cout << "6) Cari Data Klub" << endl;
    cout << "7) Keluar" << endl;
}

int selisih_gol(const statistik *stats)
{
    return stats->gol - stats->bobol; // Menggunakan dereference operator -> untuk mengakses anggota statistik
}

int poin(const int *menang, const int *seri, const int *kalah) 
{
    int poin_menang = (*menang) * 3; // Dereference parameter untuk mengambil nilai yang ditunjuk
    int poin_seri = (*seri) * 1;
    int poin_kalah = (*kalah) * 0;
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
            << ", Selisih Gol : " << selisih_gol(&klub[i].stat) 
            << ", Menang : " << klub[i].stat.menang 
            << ", Seri : " << klub[i].stat.seri 
            << ", Kalah : " << klub[i].stat.kalah 
            << ", Poin : " << poin(&klub[i].stat.menang, &klub[i].stat.seri, &klub[i].stat.kalah) << endl;
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


// Sorting

void tukar(data_klub& a, data_klub& b) 
{
    data_klub temp = a;
    a = b;
    b = temp;
}

int partisi(data_klub arr[], int low, int high) 
{
    string pivot = arr[high].nama_klub;
    int i = low - 1;
    
    for (int j = low; j < high; j++) 
    {
        if (arr[j].nama_klub < pivot) 
        {
            i++;
            tukar(arr[i], arr[j]);
        }
    }
    
    tukar(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(data_klub arr[], int low, int high) 
{
    if (low < high) 
    {
        int pivot = partisi(arr, low, high);
        
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void quickSort_nama_klub(data_klub arr[], int isi_data) 
{
    quickSort(arr, 0, isi_data - 1);
}

void bubbleSort_selisih_gol(data_klub arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (selisih_gol(&arr[j].stat) < selisih_gol(&arr[j + 1].stat)) 
            {
                data_klub temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort_poin(data_klub arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int max_index = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (poin(&arr[j].stat.menang, &arr[j].stat.seri, &arr[j].stat.kalah) > poin(&arr[max_index].stat.menang, &arr[max_index].stat.seri, &arr[max_index].stat.kalah)) 
            {
                max_index = j;
            }
        }
        if (max_index != i) 
        {
            tukar(arr[i], arr[max_index]);
        }
    }
}


// Searching

void binarySearch_nama_klub(data_klub arr[], string nama, int low, int high, int &count, int indices[], int &index) {
    if (low <= high) 
    {
        int mid = low + (high - low) / 2;

        if (arr[mid].nama_klub == nama) 
        {
            indices[index++] = mid;
            count++;

            int left = mid - 1;
            while (left >= low && arr[left].nama_klub == nama) 
            {
                indices[index++] = left;
                count--;
                left--;
            }

            int right = mid + 1;
            while (right <= high && arr[right].nama_klub == nama) 
            {
                indices[index++] = right;
                count++;
                right++;
            }
        }

        if (arr[mid].nama_klub > nama)
            binarySearch_nama_klub(arr, nama, low, mid - 1, count, indices, index);

        if (arr[mid].nama_klub < nama)
            binarySearch_nama_klub(arr, nama, mid + 1, high, count, indices, index);
    }
}

void search_nama_klub(data_klub arr[], int isi_data) 
{
    string nama_klub;
    cin.ignore();
    cout << "Masukkan nama klub yang ingin dicari : ";
    getline(cin, nama_klub);

    quickSort_nama_klub(arr, isi_data);

    int count = 0;
    int indices[isi_data];
    int index = 0;

    binarySearch_nama_klub(arr, nama_klub, 0, isi_data - 1, count, indices, index);

    if (count > 0) 
    {
        cout << "Ditemukan " << count << " klub dengan nama " << nama_klub << ":" << endl;
        for (int i = 0; i < count; ++i) 
        {
            int result = indices[i];
            cout << "Nama Klub : " << arr[result].nama_klub
                << ", Jumlah Gol Masuk : " << arr[result].stat.gol
                << ", Jumlah Gol Kebobolan : " << arr[result].stat.bobol
                << ", Selisih Gol : " << (arr[result].stat.gol - arr[result].stat.bobol)
                << ", Menang : " << arr[result].stat.menang
                << ", Seri : " << arr[result].stat.seri
                << ", Kalah : " << arr[result].stat.kalah
                << ", Poin : " << (arr[result].stat.menang * 3 + arr[result].stat.seri) << endl;
        }
    } 
    else 
    {
        cout << "Klub " << nama_klub << " tidak ditemukan." << endl;
    }
}

void sequentialSearch_selisih_gol(data_klub arr[], int n, int cari_selisih) 
{
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (selisih_gol(&arr[i].stat) == cari_selisih) {
            found = true;
            cout << "Klub dengan selisih gol " << cari_selisih << " : " << arr[i].nama_klub << endl;
        }
    }
    if (!found) {
        cout << "Tidak ada klub dengan selisih gol " << cari_selisih << endl;
    }
}

void search_selisih_gol()
{
    system("cls");
    int cari_selisih;
    cout << "Masukkan selisih gol klub yang ingin dicari : ";
    cin.ignore();
    cin >> cari_selisih;
    bubbleSort_selisih_gol(klub, isi_data);
    sequentialSearch_selisih_gol(klub, isi_data, cari_selisih);
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
                    while (true)
                    {
                        cout << "Menu Sorting : " << endl;
                        cout << "1) Nama Klub " << endl;
                        cout << "2) Selisih Gol " << endl;
                        cout << "3) Jumlah Poin " << endl;
                        cout << "4) Keluar " << endl;
                        cout << "Pilihan (1/2/3/4) : ";
                        int pilihan2;
                        cin >> pilihan2;
                        if (pilihan2 == 1)
                        {
                            system("cls");
                            quickSort_nama_klub(klub, isi_data);
                            lihat_klub();
                        }
                        else if (pilihan2 == 2)
                        {
                            system("cls");
                            bubbleSort_selisih_gol(klub, isi_data);
                            lihat_klub();
                        }
                        else if (pilihan2 == 3)
                        {
                            system("cls");
                            selectionSort_poin(klub, isi_data);
                            lihat_klub();
                        }
                        else if (pilihan2 == 4)
                        {
                            system("cls");
                            break;
                        }
                        else
                        {
                            system("cls");
                            cout << "Pilihan tidak valid." << endl;
                        }
                    }
                }
                else if(pilihan == 6)
                {
                    while(true)
                    {
                        cout << "Menu Searching : " << endl;
                        cout << "1) Nama Klub " << endl;
                        cout << "2) Selisih Gol " << endl;
                        cout << "3) Keluar " << endl;
                        int opsi;
                        cout << "Pilihan (1/2/3) : ";
                        cin >> opsi;
                        if (opsi == 1)
                        {
                            system("cls");
                            search_nama_klub(klub, isi_data);
                        }
                        else if (opsi == 2)
                        {
                            system("cls");
                            search_selisih_gol();
                        }
                        else if (opsi == 3)
                        {
                            system("cls");
                            break;
                        }
                        else
                        {
                            system("cls");
                            cout << "Pilihan tidak valid." << endl;
                        }
                    }
                }
                else if(pilihan == 7)
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