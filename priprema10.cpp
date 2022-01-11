#include <iostream>
#include <cstdlib> // random numbers
#include <ctime>
#include <iomanip> 
#include <cstring>
#include <cmath>
using namespace std;

void zamjena(int &a,int &b){  // https://www.w3schools.com/cpp/cpp_function_reference.asp
    int pom = a;
    a = b;
    b = pom;
}
void prostiBrojevi(int a, int b){
    bool baremJedanProsti = false;
    
    for (int i = a; i <= b; i++){
        bool prost = true;
        for (int j = 2; j <= sqrt(i) && prost; j++){
            if(i%j == 0){
            prost = false;
            }
        }
        if(prost){
            cout << i << " ";
            baremJedanProsti = true;
        }
    }
    if(!baremJedanProsti) cout << "U zadanom rasponu nema prostih brojeva!" << endl;
}
int prostBroj(int broj){
    bool prost = true;
        for (int j = 2; j <= sqrt(broj) && prost; j++){
            if(broj%j == 0){
            prost = false;
            }
        }
        return prost;
}
bool jediniceVeceOdTisucice(int N){
    int tisucice = (N*N) / 1000;
    int jedinice = (N*N) % 1000;
    if(jedinice == tisucice + 1) return true;
    else return false;
}

double PI(int n){
    double Pi=0,E;
    int S = 1;
    for (int i = 1; i <= n; i++){
         E = (double)S / (2 * i -1);
         Pi += E;
         S *= -1;
    }
    Pi *= 4;
    return Pi;
    
}

int main(){

    int a,b;
    short izbor;
    int brojacIzbora[6] = {0,0,0,0,0,0}; // brojacIzbora[0] je brojac netocnih unosa
    do
    {   
        cout << endl << "Odaberite jednu od ponudjenih opcija:" << endl << 
        "1. Prosti brojevi u zadanom rasponu" << endl <<
        "2. Provjera prostog broja" << endl <<
        "3. Kvadrati s uzastopnim brojevima jedinica i tisucica" << endl <<
        "4. Ludolfov broj" << endl <<
        "9. Izlaz iz programa" << endl;

        cin >> izbor;

        // brojanje izbora
        if (izbor == 9) brojacIzbora[5]++;
        else if(izbor >= 1 && izbor <= 4) brojacIzbora[izbor]++;
        else brojacIzbora[0]++;
        
        switch (izbor){
        
            case 1:{
                
                do{
                    cout << "Unesite dva cijela broja:";
                    cin >> a >> b;
                }while (a<2 || b<2);
                if(a>b){
                    zamjena(a,b);
                    cout << "Vrijednosti a i b su zamjenjene!" << endl;
                }
                prostiBrojevi(a,b);
                break;
            }
            case 2:{
               if (brojacIzbora[1] == 0){
                   cout << "Potrebno je prvo odabrati mogucnost 1!" << endl;
                   break;
               };
                cout << "Uneseni brojevi su: " << a << " i " << b << endl;

                int prostA = prostBroj(a);
                int prostB = prostBroj(b);
                if(prostA && prostB) cout << a << " i " << b << " su prosti brojevi." << endl;
                else if(prostA) cout << a << " je prost broj." << endl;
                else if(prostB) cout << b << " je prost broj." << endl;
                else cout << "Ni " << a << " ni " << b << " nisu prosti brojevi." << endl;
                break;
            }
            case 3:{
                if (brojacIzbora[1] == 0){
                   cout << "Potrebno je prvo odabrati mogucnost 1!" << endl;
                   break;
               };

               cout << left << setw(4) << setfill(' ') << "N";
               cout << "Kvadrat" << endl;
               
                for (int i = a; i <= b; i++){
                    if(jediniceVeceOdTisucice(i)){
                        cout << i << "-" << i*i << endl;
                    };
                }

                break;
            }
            case 4:{
                if(brojacIzbora[1] == 0){ // ako izbor 1 nije bio prethodno odabran, unesi a i b
                    do{
                        cout << "Unesite dva cijela broja:";
                        cin >> a >> b;
                    }while (a<2 || b<2);
                    if(a>b){
                        zamjena(a,b);
                        cout << "Vrijednosti a i b su zamjenjene!" << endl;
                    }
                }
                double const pi = 3.14159265; // definiran u zadatku
                double piA = PI(a); // izracunat pi na temelju a
                double piB = PI(b); // izracunat pi na temelju b

                if(b == a+1){ // ukoliko su uzastopni brojevi
                    // racunanje aritmeticke sredine izracunatih pi vrijednosti iz a i b 
                    double piAS = (piA + piB)/2;
                    // odstupanje piAS od zadane konstante pi
                    cout << setprecision(6) << "Odstupanje pi aritmeticke sredine od pi konstante:" << abs(pi-piAS) << endl;
                }else{
                    // odstupanje pi na temelju a i pi na temelju b od konstante pi
                    cout << setprecision(6) << "Odstupanje pi dobivenog sa N=a iteracija:" << abs(pi-piA) << endl;
                    cout << setprecision(6) << "Odstupanje pi dobivenog sa N=b iteracija:" << abs(pi-piB) << endl;
                }
                break;
            }
            case 9: break;
            default: cout << "Neispravan unos, pokusajte ponovo!";    
        }

    } while (izbor != 9);
    cout << "Odabrali ste izlaz iz programa" << endl <<
    "Odabiri korisnika: " << endl;

    // trazenje max vrijednosti brojaca
     
    // ispis svih izbora 
    for (int i = 0; i < 6; i++)
    {
       
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
    
    system("pause");
    return 0;
}