#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int brojacCase2 = 0;
int odabir(){
    int izbor;
    cout << "Odaberite jednu od ponudjenih opcija:"<< endl <<
    "1. Sortiranje polja postupkom Bubble sort"<< endl <<
    "2. Povrsina trokuta"<< endl <<
    "3. Eratostenovo sito"<< endl <<
    "4. Elementi niza"<< endl <<
    "5. Izlaz iz programa"<< endl;
    cin >> izbor;
    if(izbor>0 && izbor<6) return izbor;
    else return 0;
}
float sortBubble(int n,float polje[]){
    // 1. ispis nesortiranog polja
    cout << "Ispis nesotiranog polja:" << endl;
    for (int i = 0; i < n; i++){
        cout << polje[i] << " ";
    }
    // 2. sortiranje polja silazno
    bool zamjena = true;
    for (int i = n-1; i > 0 && zamjena; i--){
        zamjena = false;
        for (int j = 0; j < i; j++){
            if(polje[j] < polje[j+1]){
                float pom = polje[j];
                polje[j] = polje[j+1];
                polje[j+1] = pom;
                zamjena = true;
            } 
        }  
    }
    // vrati najveci element polja(to je nakon sortiranja silazno prvi element polja)
    return polje[0];
}
void povrsinaTrokuta(float& a,float& b,float& c,float& P){
    float s = (a+b+c)/2;
    float podKorjenom = s*(s-a)*(s-b)*(s-c);
    if(podKorjenom > 0){
        P = sqrt(podKorjenom);
    }else 
    // brojac je globalna varijabla kako bi "prezivio" pozive funkcije
    if(podKorjenom <= 0 && brojacCase2 < 5){ // ako stranice ne cine trokut
        a+=1;
        b+=1;
        c+=1;
        P = -1;
        brojacCase2++;
        povrsinaTrokuta(a,b,c,P);
    }
}
int eratostenovoSito(int a, int b, int prost[]){
    int brojacProstih = 0;
    // postavljanje svih elemenata na true (1)
    for (int i = 0; i < b-a; i++){
        prost[i] = 1;
    }

    // sito
    for (int k = 2; k <= sqrt(b); k++){
        int l = 2;
        while (k * l <= b){
            if((k*l)>a){ // ako je višekratnik u rasponu <a-b] stavi ga na nulu.
                // buduci da je u prost[0] pohranjeno stanje za broj a+1 (a i b nisu oboje ukljuceni jer je u zadatku definirano da je
                // polje velicine B-A tako da nije moguce [a-b]) potrebno je od broja oduzeti a-1 da se dobije index za odgovarajuci broj cije stanje treba biti 0
                prost[(k * l)-a-1] = 0; 
            }
            l++;
        }
    }
    // prebrojavanje ukupnog broja prostih brojeva u rasponu
    for (int i = 0; i < b-a; i++){
        if(prost[i]) brojacProstih++;
    }
    return brojacProstih;
}
int racunNiza(int n){
    //F n = F (n-1) + 2 * F (n-2) - F (n-3)
    //F1 =1, F2 = 1, F3 = 1
    if (n == 1 || n == 2 || n == 3 ) return 1;
    unsigned int izracun = (racunNiza(n-1) + 2* racunNiza(n-2) - racunNiza(n-3));
    if (izracun > INT_MAX ) return -1;
    else return izracun;
}
bool selektorPrograma(int izbor){
    switch (izbor){
    case 1: {
        int n;
        cout << "Odaberite broje elemenata polja N:" << endl;
        cin >> n;
        if(n<10 || n>1000) return false;
        float *polje = new float [n];
        srand(time(0));
        rand();

        // popunjavanje polja random brojevima 50-100
        for (int i = 0; i < n; i++){
            polje[i]= rand()%51 + 50;
        }
        // sortiranje polja
        float maxValue = sortBubble(n,polje);

        // ispis sortiranog polja i najvece vrijednosti polja
        cout << endl << "Sortirano polja:" << endl;
        for (int i = 0; i < n; i++){
            cout << polje[i] << " ";
        }
        cout << endl << "Najveca vrijednost polja:" << maxValue << endl;
        
        return true;
        }
    case 2:{
        float a,b,c,P;
        // unos stranica trokuta
        cout << "Unesite stranice trokuta a,b,c." << endl << "a=";
        cin >> a;
        cout << "b=";
        cin >> b;
        cout << "c=";
        cin >> c;
        // racunanje povrsine trokuta u 5 pokusaja
        povrsinaTrokuta(a,b,c,P);
        // ako povrsina nije izracunata u 5 pokusaja return false inace ispisi rezultat
        if(P == -1) return false;
        // ispis
        cout << "Duljine stranica trokuta: a=" << a << " b=" << b << " c=" << c << endl <<
        "Povrsina trokuta:" << P << endl;
        return true;
        }
    case 3:{
        int A,B;
        cout << "Unesite donju granicu raspona:";
        cin >> A;
        cout << "Unesite gornju granicu raspona:";
        cin >> B;
        if(A > B || A < 2 || A > 1000 || B < 2 || B > 1000) return false;
        int *P = new int [B - A]; // uvjet zadatka
    
        // ispis broja prostih brojeva u rasponu A-B
        cout << "Broj prostih brojeva u rasponu " << A << "-" << B << ":" << eratostenovoSito(A,B,P) << endl;
        // ispis svih prostih brojeva u polju
        for (int i = 0; i < B-A; i++){
            if(P[i]) cout << i+A+1 << " ";
        }
        cout << endl;
        return true;
        }
    case 4: {
        int brojacN = 0;
        int prethodniN = -1;
        do{
            int n;
            cout << "Unesite velicinu niza n (upozorenje: veci brojevi uzrokuju dugo vrijeme izracuna, tip: pokusajte sa brojevima do 40):";
            cin >> n;
            int Fn = racunNiza(n);
            if(Fn == -1) cout << "Vrijednost n-tog clana prelazi maximalnu vrijednost tipa int od " << INT_MAX << endl;
            else cout << Fn << endl;
            
            if(n == prethodniN) brojacN++;
            else {
                prethodniN = n;
                brojacN = 0;
            }
            
        } while (brojacN < 2);
        
        // ispis svih clanova niza (za testiranje)
        // for (int i = 1; i <= n; i++){
        //      cout << racunNiza(i) << " ";
        // }
        return true;
    }
    case 5:
        cout << "Odabrali ste izlaz iz programa." << endl;
        return true;
    default:
        cout << "Krivi odabir, pokusajte ponovo." << endl;
        return false;
    
    }

}

void ispisOdabira(int brojac[]){
    cout << "Odabrane mogucnosti prema broju odabira: "<< endl <<
    "1. Sortiranje polja postupkom Bubble sort: " << brojac[0] << " puta" << endl <<
    "2. Povrsina trokuta: " << brojac[1] << " puta" << endl <<
    "3. Eratostenovo sito: " << brojac[2] << " puta" << endl <<
    "4. Elementi niza: " << brojac[3] << " puta" << endl <<
    "5. Izlaz iz programa: " << brojac[4] << " puta" << endl;
}

int main(){
    int izbor;
    bool izvrseno;
    int brojacIzbora[5] = {0,0,0,0,0};
    do{
        izbor = odabir();
        izvrseno = selektorPrograma(izbor);
        if(!izvrseno) cout << "Operacija nije uspjesno izvrsena!" << endl;
        else brojacIzbora[izbor -1]++;
        
    }while(izbor != 5);
    ispisOdabira(brojacIzbora);


    system("pause");
    return 0;
}