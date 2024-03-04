#include <iostream>
#include <string>
using namespace std;

string nama, nim;
int ulang = 3;
double rupiah, yen, euro, dollar;

void menu()
{
    cout << "Pilihan Menu : " << endl;
    cout << "1) Konversi Rupiah ke (Dollar, Euro, Yen)" << endl;
    cout << "2) Konversi Dollar ke (Rupiah, Euro, Yen)" << endl;
    cout << "3) Konversi Euro ke (Rupiah, Dollar, Yen)" << endl;
    cout << "4) Konversi Yen ke (Rupiah, Dollar, Euro)" << endl;
    cout << "5) Keluar" << endl;
}
 
void kurs_rupiah()
{
    cout << "Inputan Rupiah : " << rupiah << endl;
    dollar = rupiah / 15701.95;
    cout << "Dollar : " << dollar << endl;
    euro = rupiah / 17043.68;
    cout << "Euro : " << euro << endl;
    yen = rupiah / 104.61;
    cout << "Yen : " << yen << endl;
}

void kurs_dollar()
{
    cout << "Inputan Dollar : " << dollar << endl;
    rupiah = dollar * 15701.95;
    cout << "Rupiah : " << rupiah << endl;
    euro = dollar * 0.92;
    cout << "Euro : " << euro << endl;
    yen = dollar * 150.09;
    cout << "Yen : " << yen << endl;
}

void kurs_euro()
{
    cout << "Inputan Euro : " << euro << endl;
    rupiah = euro * 17037.71;
    cout << "Rupiah : " << rupiah << endl;
    dollar = euro * 1.09;
    cout << "Dollar : " << dollar << endl;
    yen = euro * 162.86;
    cout << "Yen : " << yen << endl;
}

void kurs_yen()
{
    cout << "Inputan Yen : " << yen << endl;
    rupiah = yen * 104.61;
    cout << "Rupiah : " << rupiah << endl;
    dollar = yen / 150.10;
    cout << "Dollar : " << dollar << endl;
    euro = yen / 162.86;
    cout << "Euro : " << euro << endl;
}

int main()
{
    while(true)
    {
        cout << "Nama : "; 
        getline(cin, nama);
        cout << "NIM : ";
        cin >> nim;
        system("cls");
        cin.ignore();
        if(nama == "celio" && nim == "39")
        {
            cout << "Anda berhasil login." << endl;
            while(true)
            {
                menu();
                int pilihan;
                cout << "Pilih (1/2/3/4/5) : ";
                cin >> pilihan;
                system("cls");
                if(pilihan == 1)
                {
                    cout << "Input nilai Rupiah : ";
                    cin >> rupiah;
                    system("cls");
                    kurs_rupiah();
                }
                else if(pilihan == 2)
                {
                    cout << "Input nilai Dollar : ";
                    cin >> dollar;
                    system("cls");
                    kurs_dollar();
                }
                else if(pilihan == 3)
                {
                    cout << "Input nilai Euro : ";
                    cin >> euro;
                    system("cls");
                    kurs_euro();
                }
                else if(pilihan == 4)
                {
                    cout << "Input nilai Yen : ";
                    cin >> yen;
                    system("cls");
                    kurs_yen();
                }
                else if(pilihan == 5){
                    system("cls");
                    cout << "Anda berhasil keluar." << endl;
                    break;
                }
                else
                {
                    cout << "Pilihan tidak valid." << endl;
                }
            }
            break;
        }
        else
        {
            ulang--;
            system("cls");
            cout << "Nama atau NIM anda salah. Kesempatan sisa : " << ulang << endl;
        }
        if(ulang == 0)
        {
            system("cls");
            cout << "Kesempatan Anda telah habis.";
            break;
        }
    }
    return 0;
}