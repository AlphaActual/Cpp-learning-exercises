#include <iostream>
#include <cstdlib> // za random brojeve
#include <ctime> // za vrijeme
#include <cmath> // za matematicke funkcije
using namespace std;

int main(){

    short unsigned int odabir;
    srand(time(0)); // postavljanje seeda
    rand(); 
    
    for (int i = 0; i < 3; i++) // 3. pokusaja
    {
        cout << "Odaberite jednu od ponudjenih opcija:" << endl;
        cout << "1. Prosjecna ocjena"<< endl <<"2. Bacanje novcica"<< endl <<"3. Prosti brojevi"<< endl <<"4. Najveci i najmanji broj"<< endl <<"5. Izlaz iz programa"<< endl;
        cin >> odabir;
        if (odabir == 5) break; // odabirom 5 program zavrsava
        
        
        switch (odabir)
        {
            case 1 : 
            {
                float n,suma=0,prosjek;
                cout << "Unesite broj ocjena za unos:";
                cin >> n;
                cout << "Unesite ocjene:";
                for (int i = 0; i < n; i++)
                {
                    float a;
                    cin >> a;
                    suma+=a; 
                }
                prosjek = suma/n;
                cout << "Prosjek unesenih ocjena je: " << prosjek << endl;

                break;
            }
            case 2 : 
            {
                int pisma=0,glave=0;
                
                for (int i = 0; i < 100; i++)
                {
                    if(rand()%2) glave++; // rand()%2 rezultira jedinicom ili nulom
                    else pisma++;
                }
                cout << "Pismo je izabrano " << pisma << " puta, a glava " << glave << " puta." << endl << endl;
                
                break;
            }
            case 3 : 
            {
                int N;
                cout << "Upisite jedan cijeli broj N:";
                cin >> N;

                for (int i = N-10; i <= N+10; i++) // definiranje raspona
                {
                    bool prost = true;
                    for(int k = 2; k <= sqrt(i); k++) { // Objasnjenje:Predavanje varijable i tipovi podataka slide 43
                        if(i%k == 0) prost = false;
                    }

                if(prost) cout << i << " ";
                }
                cout << endl;

                break;
            }
            case 4 : 
            {
                int min=0,max=0,broj;
                
                for (int i = 0; i < 10; i++)
                {
                    broj = rand()/(RAND_MAX / 99) + 1;
                    if(i==0){  // postavljanje prvog generiranog broja kao minimum i maximum, treba se izvesti samo na prvoj iteraciji
                        min=broj;
                        max=broj;
                    }
                    // ispitivanje
                    if (broj<min) min=broj; 
                    if (broj>max) max=broj;
                    
                    
                    cout << broj << " ";
                }
                cout << "Najmanji broj je broj " << min << " a najveci broj " << max << endl;
                
                break;
            }
            
            
            default: cout << "Nepostojeci unos! Odaberite jednu od ponudjenih opcija:";
                
        }
    
    }

    system("pause");
    return 0;
}