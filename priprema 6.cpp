#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <cstring>
using namespace std;

int main(){
    short brojac[6] = {0, 0, 0, 0, 0, 0}; // prvi brojac "brojac[0]" broji krive unose
    short odabir = 0;
    do
    {
        cout << "Odaberite jednu od opcija:" << endl << 
        "1. Loto" << endl <<
        "2. Dekadsko-oktalna konverzija" << endl <<
        "3. Konverzija broja iz dekadskog u zadanu bazu" << endl <<
        "4. Broj pojava slova u recenici" << endl <<
        "5. Izlaz iz programa" << endl;
        cin >> odabir;

        if (odabir >= 1 && odabir <= 5) brojac[odabir]++; // dobar unos
        else brojac[0]++;                                 // krivi unos
        
        

       switch (odabir)
       {
            case 1: { 
                srand(time(0));
                rand();


                int polje[39];
                int randomBroj;
                

                // inicijalizacija polja, postavljanje na 0 - ako se preskoči ovaj korak nastaje bug(ovi).
                for (int x = 0; x < 39; x++)
                {
                    polje[x] = 0;
                }
                
        
                for (int i = 0; i < 7; i++)  // odabir 7 random brojeva
                {
                    bool ponovi = true;
                    do{
                        // odaberi random broj
                        randomBroj = rand() / (RAND_MAX/38) + 1;
                        // ako na toj lokaciji nije upisan 1, upiši 1 i zaustavi petlju (break treba izbjegavati - bolje je sa pomocnom varijablom)
                        // ako nije, odabiranje broja ce se ponoviti
                        if(polje[randomBroj - 1] != 1){
                            polje[randomBroj - 1] = 1;
                            ponovi = false;
                        } 
                    }
                    while(ponovi);
                }
                cout << "LOTO:Izabrani brojevi u uzlaznom redosljedu: ";
                for (int i = 0; i < 39; i++)
                {
                    if(polje[i] == 1) cout << i + 1 << " "; // potrebno je dodati 1 s obzirom da je npr. broj 1 spremljen u polje[0]
                };
                cout << endl;

                break;
            }
            case 2: {
                
                int octal[10];
                int Dbroj, i=0, origBroj, brojacElemenata=0;
                cout << "Unesite broj u dekadskom sustavu: ";
                cin >> Dbroj;
                origBroj = Dbroj;
                
                do{
                    octal[i++] = Dbroj % 8;
                    brojacElemenata++;
                    Dbroj /= 8;
                } while (Dbroj > 0);

                cout << origBroj << "(10) = ";

                // ispis obrnutim redosljedom
                for (int i = brojacElemenata - 1; i >= 0; i--) 
                {
                    cout << octal[i];
                }
                cout << "(8)" << endl;
                
                break;
            }
            case 3: {
               
                int D,b;
                char rezultat[100];
                cout << "Unesite jedan dekadski broj:";
                cin >> D;

                
                do
                {
                    cout << "Unesite bazu za konverziju 2-15:";
                    cin >> b;
                    
                } while (b < 2 || b > 15);

                int i = 0,brojacElem = 0;
                
                do
                {
                    int ostatak = D % b;
                    if (ostatak >= 0 && ostatak <= 9) // 0-9 u ASCII od char '0'...'9'
                    {
                       ostatak += 48;
                    }
                    else {
                        ostatak += 55; // 10-15 u ASCII od char 'A'...'F'
                    }
            
                    // spremanje broja tipa int (ostatak) u polje char(rezultat) ce ga pretvoriti u tip char
                    rezultat[i++] = ostatak;
                    
                    brojacElem++;
                    D /= b;
                } while (D > 0);

                // ispis ostataka u obrnutom redosljedu = broj po zadanoj bazi
                for (int i = brojacElem - 1; i >= 0; i--)
                {
                    cout << rezultat[i];
                }
                cout << endl;

                break;
            }
            case 4: {
                
                int brojac[26];

                // iniciranje svih brojaca na 0
                for (int i = 0; i < 26; i++){
                    brojac[i] = 0;
                }
                
                char recenica[1000];
                cout << "Unesite recenicu:";
                cin.ignore();
                cin.getline(recenica, 1000);

                //duzina stringa
                int L = strlen(recenica);
                
                for (int i = 0; i < L; i++)
                {
                    if (recenica[i] >= 'A' && recenica[i] <= 'Z') // ako je slovo u ovom rangeu oduzmi 65. S time dobivamo da je slovo A na poziciji brojac[0]...Z na brojac[25]
                    {
                        brojac[recenica[i]-65]++;
                    }
                    else if (recenica[i] >= 'a' && recenica[i] <= 'z') // ako je u ovom rangeu -97
                    {
                        brojac[recenica[i]-97]++;
                    }
                    
                }
                
                
                int max;
                max = brojac[0];
                for (int i = 0; i < 26; i++)
                {
                    // ispis svih brojaca
                    cout << (char)(i + 65) << " = " << brojac[i] << endl;

                    // trazenje max vrijednosti
                    if(brojac[i] > max){
                        max = brojac[i];
                    }

                }
                cout << "Slova koja su se pojavila najvise puta:" << endl;
                for (int i = 0; i < 26; i++)
                {
                    if(brojac[i] == max) {
                        cout << (char)(i + 65) << " = " << brojac[i] << endl;
                    }
                }
                
                

                break;
            }
            case 5: {
                // izlaz iz programa
                break;
            }
            default: {
                   cout << "Neispravan unos!" << endl;
                break;
            }
           
       }
       
    } while (odabir != 5);

    cout << "Broj poziva pojedinih opcija:" << endl <<
    "1. Loto: " << brojac[1] << endl <<
    "2. Dekadsko-oktalna konverzija: " << brojac[2] << endl <<
    "3. Konverzija broja iz dekadskog u zadanu bazu: " << brojac[3] << endl <<
    "4. Broj pojava slova u recenici: " << brojac[4] << endl <<
    "5. Izlaz iz programa: " << brojac[5] << endl <<
    "Neispravan unos: " << brojac[0] << endl;
    
    system("pause");
    return 0;
}

