#include <iostream>
#include <cstdlib> // random numbers
#include <ctime>
#include <iomanip> // za manipulirannje ispisom znamenki
#include <cstring>
using namespace std;

struct zaposlenik{

    int identifikator;
    char prezime[20];
    char ime[20];
    char spol;
    char radno_mjesto[20];
    float placa;
    short radni_sati;
};
struct podaci{
    zaposlenik radnici[1000];
    int broj_radnika;
};

struct pomocna{
    char radno_mjesto[20];
    float placa;
    int kursor;
    char spol;
};


int main(){

    podaci S;
    pomocna P[1000];
    float prosjekM = 0,prosjekZ = 0,brojacM = 0,brojacZ = 0;
    short izbor;
    int brojacIzbora[6] = {0,0,0,0,0,0}; // brojacIzbora[0] je brojac netocnih unosa
    do
    {   
        cout << endl << "Odaberite jednu od ponudjenih opcija:" << endl << 
        "1. Upis radnika" << endl <<
        "2. Prekovremeni sati" << endl <<
        "3. Place po radnim mjestima" << endl <<
        "4. Place po spolu" << endl <<
        "9. Izlaz iz programa" << endl;

        cin >> izbor;

        // brojanje izbora
        if (izbor == 9) brojacIzbora[5]++;
        else if(izbor >= 1 && izbor <= 4) brojacIzbora[izbor]++;
        else brojacIzbora[0]++;
        
        switch (izbor){
        
            case 1:{
                do{
                    cout << "Koliko radnika zelite unijeti?:" << endl;
                    cin >> S.broj_radnika;
                }while(S.broj_radnika < 1 || S.broj_radnika > 1000);

                
                for (int i = 0; i < S.broj_radnika; i++)
                {
                    cout << endl <<  "Radnik " << i+1 << "." << endl;
                    cout << "Identifikator:";
                    cin >> S.radnici[i].identifikator;

                    cin.ignore();
                    cout << "Prezime:";
                    cin.getline(S.radnici[i].prezime,20); 
                    cout << "Ime:";
                    cin.getline(S.radnici[i].ime,20);
                    cout << "Spol(m/z):";
                    cin.get(S.radnici[i].spol);

                    cin.ignore();
                    cout << "Radno mjesto:";
                    cin.getline(S.radnici[i].radno_mjesto,20);
                    cout << "Placa:";
                    cin >> S.radnici[i].placa;
                    cout << "Radni sati:";
                    cin >> S.radnici[i].radni_sati;

                    // popunjavanje pomocnog polja - potrebno za sortiranje kasnije 
                    P[i].kursor = i;
                    P[i].placa = S.radnici[i].placa;
                    P[i].spol = S.radnici[i].spol;
                    strcpy(P[i].radno_mjesto,S.radnici[i].radno_mjesto); 

                    // sumiranje placa za muskarce i za zene
                    if (S.radnici[i].spol == 'm' || S.radnici[i].spol == 'M'){

                        prosjekM += S.radnici[i].placa;
                        brojacM++;
                    }
                    else {
                        prosjekZ += S.radnici[i].placa;
                        brojacZ++;
                    }
                    
                }
                // izracun prosjeka za muskarce i zene
                prosjekM /= brojacM;
                prosjekZ /= brojacZ;
                
                cout << endl << "Upis radnika uspjesno izvrsen!" << endl;
                
                
                break;
            }
            case 2:{
                int norma;
                cout << "Unesite zeljenu normu radnih sati:";
                cin >> norma;

                // ispis headera tablice
                cout << left << setw(20) << setfill(' ') << "Identifikator";
                cout << left << setw(20) << setfill(' ') << "Ime";
                cout << left << setw(20) << setfill(' ') << "Prezime";
                cout << left << setw(20) << setfill(' ') << "Prekovremeni sati" << endl; 

                // popunjavanje tablice radnicima sa radnim satima iznad norme
                for(int i = 0; i < S.broj_radnika; i++){
                    int sati = S.radnici[i].radni_sati;
                    if (sati > norma)
                    {
                        int prekovremeni = sati - norma;
                        cout << left << setw(20) << setfill('_') << S.radnici[i].identifikator;
                        cout << left << setw(20) << setfill('_') << S.radnici[i].ime;
                        cout << left << setw(20) << setfill('_') << S.radnici[i].prezime;
                        cout << left << setw(20) << setfill('_') << prekovremeni << endl;
                    }
                    
                }

                break;
            }
            case 3:{
                // Place po radnim mjestima

                // 1. sortiranje polja P - po radnom mjestu metodom insertion sort
                for(int i = 1; i < S.broj_radnika; i++){
                    int j = i-1;
                    pomocna pom = P[i];
                    while(j>=0 && strcmp(P[j].radno_mjesto,pom.radno_mjesto) > 0 ){
                        P[j+1] = P[j];
                        j--;
                    };
                    P[j+1] = pom;
                    
                }

                // 2. sortiranje polja P - po placi unutar radnog mjesta silazno metodom insertion sort
                for(int i = 1; i < S.broj_radnika; i++){
                    int j = i-1;
                    pomocna pom = P[i];
                    while(j>=0 && strcmp(P[j].radno_mjesto,pom.radno_mjesto) == 0 && P[j].placa < pom.placa ){
                        P[j+1] = P[j];
                        j--;
                    };
                    P[j+1] = pom;
                    
                }

                // ispis tablice radnika
                // ispis headera tablice
                cout << left << setw(20) << setfill(' ') << "Identifikator";
                cout << left << setw(20) << setfill(' ') << "Ime";
                cout << left << setw(20) << setfill(' ') << "Prezime";
                cout << left << setw(20) << setfill(' ') << "Radno mjesto";
                cout << left << setw(20) << setfill(' ') << "Placa" << endl; 
                // ispis sadrzaja tablice
                for(int i = 0; i < S.broj_radnika; i++){
                    int kursor = P[i].kursor;
            
                        
                        cout << left << setw(20) << setfill('_') << S.radnici[kursor].identifikator;
                        cout << left << setw(20) << setfill('_') << S.radnici[kursor].ime;
                        cout << left << setw(20) << setfill('_') << S.radnici[kursor].prezime;
                        cout << left << setw(20) << setfill('_') << S.radnici[kursor].radno_mjesto;
                        cout << left << setw(20) << setfill('_') << S.radnici[kursor].placa << endl;
                    
                    
                }


                break;
            }
            case 4:{
               
               // 1. sortiranje polja P - po spolu metodom insertion sort
                for(int i = 1; i < S.broj_radnika; i++){
                    int j = i-1;
                    pomocna pom = P[i];
                    while(j>=0 && P[j].spol > pom.spol ){
                        P[j+1] = P[j];
                        j--;
                    };
                    P[j+1] = pom;
                    
                }

                // 2. sortiranje polja P - po placi unutar spola silazno metodom insertion sort
                for(int i = 1; i < S.broj_radnika; i++){
                    int j = i-1;
                    pomocna pom = P[i];
                    while(j>=0 && P[j].spol == pom.spol && P[j].placa < pom.placa ){
                        P[j+1] = P[j];
                        j--;
                    };
                    P[j+1] = pom;
                    
                }

                // ispis tablice radnika
                // ispis headera tablice
                cout << left << setw(20) << setfill(' ') << "Identifikator";
                cout << left << setw(20) << setfill(' ') << "Ime";
                cout << left << setw(20) << setfill(' ') << "Prezime";
                cout << left << setw(20) << setfill(' ') << "Spol";
                cout << left << setw(20) << setfill(' ') << "Placa" << endl; 
                // ispis sadrzaja tablice
                for(int i = 0; i < S.broj_radnika; i++){
                    int kursor = P[i].kursor;
            
                        
                        cout << left << setw(20) << setfill('_') << S.radnici[kursor].identifikator;
                        cout << left << setw(20) << setfill('_') << S.radnici[kursor].ime;
                        cout << left << setw(20) << setfill('_') << S.radnici[kursor].prezime;
                        cout << left << setw(20) << setfill('_') << S.radnici[kursor].spol;
                        cout << left << setw(20) << setfill('_') << S.radnici[kursor].placa << endl;
                    
                    
                }
                cout << "Prosjek placa za muskarce je:" << prosjekM << endl;
                cout << "Prosjek placa za zene je:" << prosjekZ << endl;
                
                

                break;
            }
            case 9: break;
            default: cout << "Neispravan unos, pokusajte ponovo!";    
        }

    } while (izbor != 9);
    cout << "Odabrali ste izlaz iz programa" << endl <<
    "Najcesci odabiri korisnika: " << endl;

    // trazenje max vrijednosti brojaca
    int max = 0;
    for (int i = 0; i < 6; i++){
        if(brojacIzbora[i] > max) max = brojacIzbora[i];
    } 
    // ispis svih izbora ciji brojac odgovara max vrijednosti
    for (int i = 0; i < 6; i++)
    {
        if(brojacIzbora[i] == max){
            cout << "Izbor: ";

            switch (i)
            {
            case 0: {
                cout << "netocan ";
                break;}
            case 5: {
                cout << "izlaz iz programa";
                break;
            }
            default: cout << i;
        
            }

            cout << " = " << brojacIzbora[i] << " puta" << endl;
        };
    };
    
    system("pause");
    return 0;
}