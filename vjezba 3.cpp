#include <iostream>
using namespace std;

// pocetak izvodenja programa
int main(){
// zad 1
int br;
cout << "Unesite jedan cijeli broj:";
cin >> br;
if(br < 100 || br > 999) cout << "Upisani broj nije troznamenkast." << endl;
else cout << "Upisani broj je troznamenkast" << endl; 
if(br%2) cout << "Broj je neparan" << endl;
else cout << "Broj je paran" << endl;

// zad 2

int a,b,counter=0;
cout << "Upisite dva cijela broja:";
cin >> a >> b;
if((a+b)%2) cout << "Zboj upisanih brojeva je neparan" << endl;
if(a%2) counter++;
if(b%2) counter++;
cout << "Broj neparnih upisanih brojeva je: " << counter << endl;

// zad 3

int x,y,z,max,min,mid;
cout << "Upisite 3 cijela broja:";
cin >> x >> y >> z;

min=x;
mid=x;
max=x;
if(y<min) min=y;
if(z<min) min=z;
if(y>max) max=y;
if(z>max) max=z;
if(y>min && y<max) mid=y;
if(z>min && z<max) mid=z;

cout << min << ", " << mid << ", " << max << endl;


	system("PAUSE");
	return 0;
}
 
