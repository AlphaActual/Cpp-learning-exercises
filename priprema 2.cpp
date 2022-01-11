

/*
ZADATAK 1 Napišite program u programskom jeziku C++ koji ce:
Za 1 bod:
Zatražiti od korisnika unos cijelog broja, a zatim taj broj ispisati u heksadekadskom, oktalnom
i dekadskom brojevnom sustavu.
*/

#include <iostream>
using namespace std;

int main(){
	
	cout<<4371%100;
// zadatak 1
cout << "ZADATAK 1" << endl;
int a;
cout << "Unesite jedan cijeli broj:";
cin >> a;

cout << "Uneseni broj u heksadekadskom sustavu: " << hex << a << endl;
cout << "Uneseni broj u oktalnom sustavu: " << oct << a << endl;
cout << "Uneseni broj u dekadskom sustavu: " << dec << a << endl << endl;

// zadatak 2
cout << "ZADATAK 2" << endl;

float x,y;

cout << "Unesite dva realna broja:" << endl;
cin >> x >> y;
cout << "Zbroj: " << x << "+" << y << " = " << x+y << endl;
cout << "Razlika: " << x << "-" << y << " = " << x-y << endl;
cout << "Umnozak: " << x << "*" << y << " = " << x*y << endl;
cout << "Kvocjent: " << x << "/" << y << " = " << x/y << endl << endl;

// zadatak 3
cout << "ZADATAK 3" << endl;

int s,m,h;
cout << "Unesite broj sekundi:";
cin >> s;
cout << s << " sekundi je: " << endl;

m=s/60;
cout << m << endl;
h=s/60/60;
cout << h << endl;

cout << h << " sati, " << m%60 << " minuta i " << s%60 << " sekundi.";


system("pause");
return 0;	
};


