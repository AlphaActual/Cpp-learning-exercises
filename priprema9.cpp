#include <iostream>
#include <cstdlib> // random numbers
#include <ctime>
#include <iomanip> // za manipulirannje ispisom znamenki
#include <cstring>

using namespace std;


int main(){

    
    short izbor,prijasnjiIzbor = 0;
    do
    {   
        cout << endl << "Odaberite jednu od ponudjenih opcija:" << endl << 
        "1. Dinamicko polje" << endl <<
        "2. Sortiranje polja prebrojavanjem" << endl <<
        "3. Vezana lista" << endl <<
        "9. Izlaz iz programa" << endl;

        cin >> izbor;

        if(izbor == prijasnjiIzbor){
        	cout << "Odaberite drugi izbor!";
			continue;	
		} 
        
        switch (izbor){
        
            case 1:{
            	int N,Amax;
            	float AritSred = 0,Bmin;
            	struct data{
            		int A;
            		float B;
            		int C;
				};
				srand(time(0));
				rand();
				rand();
				cout << "Unesite velicinu polja N:";
				cin >> N;
				
				data polje[N]; // ili ovako preko pointera-->  data *polje = new data [N]
				
				// popunjavanje polja
				for(int i=0;i<N;i++){
					//polje[i].A = rand()%51 + 50; nacin sa vjezbi
					polje[i].A = rand()/(RAND_MAX/50) + 50; // 50-100 
					polje[i].B = rand()/(RAND_MAX/100.00) + 100; // 100-200
					polje[i].C = rand()/(RAND_MAX/200) + 100; // 200-300
				}
				
				// trazenje min max i avg
				Amax = polje[0].A;
				Bmin = polje[0].B;
				
				for(int i=0;i<N;i++){
					AritSred+=polje[i].C;
					if(polje[i].A > Amax) Amax = polje[i].A;
					if(polje[i].B < Bmin) Bmin = polje[i].B;
				}
                AritSred/=N;
                
                cout << "Najveci A je:" << Amax << endl;
                cout << "Najmanji B je:" << Bmin << endl;
                cout << "Aritmeticka sredina C je:" << AritSred << endl;
                prijasnjiIzbor = izbor;
                break;
            }
            case 2:{
				int n;
				struct predmet {
					int sifra;
					char naziv[40];
				};
				
				cout << "Unesite velicinu polja n:";
				cin >> n;
				

				predmet predmeti[n];
				predmet sortirani[n]; 
				int P[1000];// raspon sifri je 0-999
				for(int i=0;i<1000;i++) P[i]=0; // stavljanje pomocnog polja na nulu
				
				

				//unos podataka
				for(int i=0;i<n;i++){
					do{
						cout << "Sifra predmeta " << i+1 << ":";
						cin >> predmeti[i].sifra;
					}while(predmeti[i].sifra < 100 || predmeti[i].sifra > 999);
					// dodavanje sifre u pomocno polje
					P[predmeti[i].sifra]++; // vrijednost sifre se stavlja na index te vrijednosti pomocnog polja
					cin.ignore();
					cout << "Ime predmeta " << i+1 << ":";
					cin.getline(predmeti[i].naziv,40);
					cout << endl;
					
				}

				
				// sortiranje prebrojavanjem
				int c = 0;
				for(int i=0;i<1000;i++){
					
					for(int j=1;j<=P[i];j++){
						// trzenje po sifri
						for(int a=0;a<n;a++){
							if(predmeti[a].sifra == i){
								sortirani[c] = predmeti[a];
								break;
							}
						}
						cout << sortirani[c].sifra << " " << sortirani[c].naziv << endl;				
						c++;
					}
				}
				// 3. Sada se u polju sortirani nalaze predmeti sortirani po sifri
				
				
			
				prijasnjiIzbor = izbor;
                break;
            }
            case 3:{
				int A;
				float AS=0;
                struct element {
					int broj;
					element *sljedeci;
				};
				element *l = NULL;
				element *el;
				int brojac=0;
				do{
					cout << "Unesite broj:";
					cin >> A;
					if(A == 999) break;

					
					el = new element;
					(*el).broj = A;
					(*el).sljedeci = l;
					l = el;

					brojac++;
					AS+=A;
				} while (true);
				AS/=brojac;
				// ispis brojeva
				while (l != NULL){	
					cout << (*l).broj << " ";
					el = l;
					l = (*l).sljedeci;
					delete el;
				}
				cout << endl << "Broj unosa:" << brojac << endl <<
				"Aritmeticka sredina:" << AS << endl;
				
				
				prijasnjiIzbor = izbor;
                break;
            }
            
            case 9: cout << "Odabrali ste izlaz iz programa" << endl; break;
            default: cout << "Neispravan unos, pokusajte ponovo!";    
        }

    } while (izbor != 9);
    
    
    
    system("pause");
    return 0;
}
