#include <iostream>
#include <cstdlib> // random numbers
#include <ctime>
#include <iomanip> // za manipulirannje ispisom znamenki
#include <cstring>

using namespace std;

int main(){

    short izbor;
    int brojacIzbora[6] = {0,0,0,0,0,0}; // brojacIzbora[0] je brojac netocnih unosa
    do
    {   
        cout << endl << "Odaberite jednu od ponudjenih opcija:" << endl << 
        "1. Pretrazivanje polja." << endl <<
        "2. Sortiranje polja brojeva metodom Bubble sort" << endl <<
        "3. Sortiranje polja brojeva metodom izbora (Selection sort)" << endl <<
        "4. Sortiranje polja prezimena i imena metodom umetanja (Insertion sort)" << endl <<
        "9. Izlaz iz programa" << endl;

        cin >> izbor;

        if (izbor == 9) brojacIzbora[5]++;
        else if(izbor >= 1 && izbor <= 4) brojacIzbora[izbor]++;
        else brojacIzbora[0]++;
        
        switch (izbor){
        
            case 1:{
                int polje[1000];
                int N,A,brojacA=0;
                do
                {
                    cout << "Unesite broj elemenata polja N:";
                    cin >> N;
                } while (N < 1 || N > 1000);
                do
                {
                    cout << "Unesite broj koji se trazi u polju (1-100):";
                    cin >> A;
                } while (A < 1 || N > 100);

                srand(time(0));
                rand();

                for (int i = 0; i < N; i++)
                {
                    int randomBroj = rand()/(RAND_MAX/99) +1; //1-100
                    polje[i] = randomBroj;
                    // ispis random brojeva
                    cout << randomBroj << " ";
                    if(randomBroj == A) brojacA++;
                }
                cout << endl;
                if (brojacA == 0){
                    cout << "Broj " << A << " se ne pojavljuje u polju.";
                }else{
                    cout << "Broj " << A << " se pojavljuje u polju " << brojacA << " puta.";
                };
                cout << endl;
                break;
            }
            case 2:{
                int N;
                float polje[1000];
                do
                {
                    cout << "Unesite broj elemenata polja N:";
                    cin >> N;
                } while (N < 1 || N > 1000);

                // popunjavanje polja
                for (int i = 0; i < N; i++)
                {
                    float randomBroj = (rand()/(RAND_MAX/50.00) + 50); //1-100
                    polje[i] = randomBroj;
                    // ispis random brojeva 50-100 prikazanih sa 2 decimale
                    cout << setprecision(2) << fixed <<  randomBroj << endl; // sa fixed postizemo da je npr 50 cijeli, zapisan kao 50.00    
                }
                cout << endl;
                // sortiranje bubble metodom
                bool zamjena = true;
                int brojUsporedbi =0,brojZamjena=0;
                for (int i = N-1; i > 0 && zamjena; i--){
                    zamjena = false;
                    for (int j = 0; j < i; j++){
                        brojUsporedbi++;
                        if (polje[j]>polje[j+1]){
                            float pom = polje[j];
                            polje[j] = polje[j+1];
                            polje[j+1] = pom;
                            zamjena = true;
                            brojZamjena++;
                        } 
                    }
                }
                // Na kraju treba ispisati broj usporedbi elemenata polja i broj njihovih zamjena u postupku sortiranja.
                cout << endl << "Sortirano polje:" << endl;
                for (int i = 0; i < N; i++)
                {
                    cout << polje[i] << endl;
                }
                cout << "Broj usporedbi elemenata polja: " << brojUsporedbi << endl <<
                "Broj zamjena elemenata polja: " << brojZamjena << endl;

                break;
            }
            case 3:{

                char slova[100];
                int N,usporedbe=0,zamjene=0;
                // unos broja elemenata
                do
                {
                    cout << "Unesite broj elemenata polja (1-100):";
                    cin >> N;

                } while (N < 1 || N > 100);
                // generiranje random brojeva, ispunjavanje arraya pripadajucim ASCII znakovima i ispis
                srand(time(0));
                rand();
                int maximum = 90,minimum = 65; //A-Z
                for (int i = 0; i < N; i++){
                    int randomASCII = rand()/(RAND_MAX/(maximum - minimum)) + minimum; // [minimum,maximum] tj. [65,90];
                    slova[i] = randomASCII;
                    cout << slova[i] << endl;
                }
                // sortiranje metodom izbora
                for (int i = N; i > 1; i--){
                    int MAX = 0;
                    for (int j = 1; j < i; j++){
                        usporedbe++;
                        if (slova[j]> slova[MAX]) MAX = j;
                    }
                    char pom = slova[i-1];
                         slova[i-1] = slova[MAX];
                         slova[MAX] = pom;
                         zamjene++; 
                    
                }
                // ispis sortiranog polja
                cout << endl << "Sortirano polje:" << endl;
                for (int i = 0; i < N; i++){
                    cout << slova[i] << endl;
                }
                // ispis broja usporedbi i zamjena
                cout << "Broj usporedbi: " << usporedbe << endl << "Broj zamjena: " << zamjene << endl;

                break;
            }
            case 4:{
                int N;
                char podaci[100][40];
                do{
                    cout << "Koliko unosa zelite napraviti (1-100)? :";
                    cin >> N;
                    if(N < 1 || N > 100) cout << "Unos izvan zadanog opsega!" << endl;
                } while (N < 1 || N > 100);

                cin.ignore(1000,'\n');
                // unos podataka
                for (int i = 0; i < N; i++){
                        cout << "Podatak[" << i << "]= ";
                        cin.getline(podaci[i],40);
                }
                // test tocnog unosa - ispis nesortiranog polja
                cout << endl << "ispis nesortiranog polja:" << endl;
                for (int i = 0; i < N; i++) {
                    cout << podaci[i] << endl;
                };
                // sortiranje metodom insertion sort
                for (int i = 1; i < N; i++){
                    int j = i-1;
                    char pom[40];
                    strcpy(pom,podaci[i]);
                    while (j>=0 && strcmp(podaci[j], pom) > 0){
                        strcpy(podaci[j+1],podaci[j]);
                        j--;
                    }
                    strcpy(podaci[j+1], pom);
                }
                // ispis polja
                cout << endl << "Sortirano polje:" << endl;
                for (int i = 0; i < N; i++) {
                    cout << podaci[i] << endl;
                };

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