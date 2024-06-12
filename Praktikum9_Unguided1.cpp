#include <iostream> 
#include <iomanip> 
using namespace std;//Arif Pramudia Wardana_2211102149 
 
const int MAX_SIMPUL = 10; 
 
void tampilGraph(string simpul[], int busur[][MAX_SIMPUL], int 
jumlahSimpul) 
{ 
    cout << setw(15) << " "; 
    for (int kolom = 0; kolom < jumlahSimpul; kolom++) { 
        cout << setw(15) << simpul[kolom]; 
    } 
    cout << endl; 
 
    for (int baris = 0; baris < jumlahSimpul; baris++) { 
        cout << setw(15) << simpul[baris] << " "; 
        for (int kolom = 0; kolom < jumlahSimpul; kolom++) { 
            cout << setw(15) << busur[baris][kolom]; 
        } 
        cout << endl; 
    } 
} 
 
void inputGraph(string simpul[], int busur[][MAX_SIMPUL], int& 
jumlahSimpul) 
{ 
    cout << "Silahkan masukkan jumlah simpul: "; 
    cin >> jumlahSimpul; 
 
    cout << "Silahkan masukkan nama simpul:\n"; 
    for (int i = 0; i < jumlahSimpul; i++) { 
        cout << "Simpul " << i + 1 << ": "; 
        cin >> simpul[i]; 
    } 
 
    cout << "Silahkan masukkan bobot simpul:\n"; 
    for (int i = 0; i < jumlahSimpul; i++) { 
        for (int j = 0; j < jumlahSimpul; j++) { 
            cout << simpul[i] << " -> " << simpul[j] << " : "; 
            cin >> busur[i][j]; 
        } 
    } 
} 
 
int main() 
{ 
    string simpul[MAX_SIMPUL]; 
    int busur[MAX_SIMPUL][MAX_SIMPUL]; 
    int jumlahSimpul; 
 
    inputGraph(simpul, busur, jumlahSimpul); 
    tampilGraph(simpul, busur, jumlahSimpul); 
 
    return 0; 
} 