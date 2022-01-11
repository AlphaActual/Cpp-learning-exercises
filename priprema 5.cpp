#include <iostream>
#include <cstdlib> // za random brojeve
#include <ctime>
#include <cmath>
using namespace std;

int main(){

    short ispravni=0,neispravni=0,odabir;
    do
    {
        
        cout << "Odaberite jednu od opcija:" << endl <<
        "1. Pogadjanje broja" << endl <<
        "2. Pogadjanje koordinata" << endl <<
        "3. Povrsina trokuta" << endl <<
        "9. Izlaz iz programa" << endl;
        cin >> odabir;
        
        if ((odabir > 0 && odabir < 4) || odabir == 9) ispravni++; // brojimo ispravne odabire: 1,2,3 ili 9
        
        switch (odabir)
        {
        case 1: {
            // Postavljanje seeda
            srand(time(0));
            rand();

            int randBroj = rand()/(RAND_MAX / 99) + 1; 
            int broj;
            
            cout << "Pogadjajte broj od 0 do 100:";
            cin >> broj;
            
            if(randBroj == broj){ 
                cout << "Pogodili ste u prvom pokusaju!" << endl;
            }
            else {
                short brPokusaja = 2; // krecemo od drugog pokusaja
                bool pogođen = false;
                while (brPokusaja <= 10)
                {
                    
                    if (broj < randBroj) {
                        
                        cout << "Uneseni broj je manji od trazenog.Pokusajte ponovo:";
                        cin >> broj;
                    }
                    else{ 

                        cout << "Uneseni broj je veci od trazenog.Pokusajte ponovo:";
                        cin >> broj;
                    }

                    // nakon unosa potrebno je provjeriti je li broj pogođen u trenutnom broju pokusaja
                    if(broj == randBroj){ 

                        cout << "Pogodili ste broj u " << brPokusaja << " pokusaja!";
                        pogođen = true;
                    // ako je broj pogodjen zaustavi petlju    
                        break;
                    }
                    // ako nije pogodjen povecaj broj pokusaja
                    brPokusaja++;
                    
                    
                }
                if(!pogođen) cout << "Niste pogodili broj u 10 pokusaja.";
                
            }
            break;
        }
        
        case 2 : {
            // Postavljanje seeda
            srand(time(0));
            rand();

            // postavljanje kordinata pocetne tocke
            int x = rand()/(RAND_MAX / 999) + 1,y = rand()/(RAND_MAX / 999) + 1,x1,y1;

            int i; // deklariranje brojaca "i" izvan for petlje kako bi ga mogli koristiti u if funkciji odmah iza petlje
            float sumaD=0;
            for (i = 1; i <= 10; i++)
            {
               float D; 
               do
               {
                   cout << "Unesite kordinate x1 i y1 unutar raspona 0-1000:";
                   cin >> x1 >> y1;
               } while (x1 < 0 || x1 > 1000 || y1 < 0 || y1 > 1000);

               D = sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
               sumaD += D;
               cout << "Udaljenost od pocetne tocke je: " << D << endl;
               if(D < 50) {cout << "Tocka je pogodjena u " << i << " pokusaja." << endl; break;} // ako je tocka pogodjena u 10. pokusaju, zbog naredbe break "i" se nece uvecati za jedan vec ces ostati 10
            }
            if(i>10){ // ako je i>10 znaci da smo izasli iz for petlje bez tocnog pogotka (nakon zadnjeg izvrsenja u 10. pokusaju i se povecao na 11)
            cout << "Tocka nije pogodjena u 10 pokusaja!";
            cout << "Prosjecna vrijednost udaljenosti D je:" << sumaD/10 << endl;
            }
            
            break;
        }

        case 3: {
            float a,b,c,P,x,s,Pmax=0,iMax=1;
            int brojacTrokuta=0; // broje se samo broje se samo unosi gdje stranice čine trokut
            do
            {   
                // 1. Unos stranica trokuta
                cout << "Unesite stranice trokuta:";
                cin >> a >> b >> c;

                if (a == 0 && b == 0 && c == 0) break; // izlazimo iz petlje odmah bez potrebe da se ulazi u unutrasnju petlju
                
                do
                {
                    // 2. racunanje je li stranice tvore trokut (x>0)
                    s = (a+b+c)/2;
                    x = s*(s-a)*(s-b)*(s-c); 
                    

                    // 3. ako ne tvore trokut zatrazi ponovni unos stranica
                    // ako je pojedina unesena str. <= 0 onda ponovi unos te stranice
                    if( x <= 0 ){
                        cout << "Stranice ne tvore trokut!Ponovite unos!";

                        cout << "Unos a:";
                        cin >> a;
                         while (a<=0){
                            cout << "Stranica mora biti veca od nule. Unos a:";
                            cin >> a;
                        };
                        cout << "Unos b:";
                        cin >> b;
                         while (b<=0){
                            cout << "Stranica mora biti veca od nule. Unos b:";
                            cin >> b;
                        };
                        cout << "Unos c:";
                        cin >> c;
                         while (c<=0){
                            cout << "Stranica mora biti veca od nule. Unos c:";
                            cin >> c;
                        };
                       
                        
                        
                    } // 4. ako tvore trokut povecaj brojac i ispisi broj unosa 
                    else{
                        brojacTrokuta++;
                        cout << "Redni broj unosa je:" << brojacTrokuta << endl;
                    }
                    
                    
                } while (x <= 0);

                // 5. izlaskom iz unutarnje petlje racunamo povrsinu unesenog trokuta
                P = sqrt(x);
                cout << "Povrsina unesenog trokuta je: " << P << endl;

                // ako je izracunata povrsina veca od prijasnje najvece povrsine stavi Pmax = P
                if(P>Pmax) {
                    Pmax = P;
                    iMax = brojacTrokuta;
                }

                
            } while (!(a==0 && b==0 && c==0));
            // 6. izlaskom iz velike petlje ispisi P najveceg trokuta i redni broj njegovog upisa
            cout << "Povrsina najveceg trokuta je: " << Pmax << endl << "Redni broj unosa je: " << iMax << endl;

            break;
        }
        case 9: break;    
        default: {
            cout << "Neispravan unos!" << endl;
            neispravni++;    
        }
        }


    } while (odabir!=9);

    // 7. izlaskom iz programa ispisi broj ispravnih i neispravnih odabira korisnika
    cout << "Broj ispravnih odabira: " << ispravni << endl << "Broj neispravnih odabira: " << neispravni << endl;
    
    system("pause");
    return 0;
}
