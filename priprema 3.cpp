// MD5:5P2g38fB2shlIPIab59M/A==
using namespace std;

// pocetak izvodenja programa
int main(){

unsigned short int odabir;
cout << "Odaberite opciju:" << endl;
cout << "1. Ispis brojeva slovima" << endl;
cout << "2. Slijedni brojevi" << endl;
cout << "3. Da li je broj u intervalu" << endl;
cin >> odabir;

switch(odabir){

	case 1 : {
		unsigned short int broj;
		do{
			cout << "Unesite cijeli broj u rasponu od 1 do 5: " << endl;
			cin >> broj;
			}
		while(broj<1 || broj > 5);
	
		cout << "Uneseni broj je broj ";
		if(broj == 1) cout << "jedan." << endl;
		else if(broj == 2) cout << "dva." << endl;
		else if(broj == 3) cout << "tri." << endl;
		else if(broj == 4) cout << "cetiri." << endl;
		else cout << "pet." << endl;
		break;
		
	}
	case 2 : {
		unsigned short int broj;
		cout << "Unesite broj izmedju 1 i 10: " << endl;
		cin >> broj;
		
		switch(broj){
		case 1: cout << "1, ";
		case 2: cout << "2, ";
		case 3: cout << "3, ";
		case 4: cout << "4, ";
		case 5: cout << "5, ";
		case 6: cout << "6, ";
		case 7: cout << "7, ";
		case 8: cout << "8, ";
		case 9: cout << "9, ";
		case 10: {cout << "10";break;}
		default : cout << "Niste unijeli broj izmedju 1 i 10!";
		}
		cout << endl;
		break;
	}
	case 3 : {
		float broj;
		int cijeliDio;
		cout << "Unesite jedan decimalan broj: ";
		cin >> broj;
		cijeliDio = broj;
		if(broj>=10 && broj <=20) cout << "Uneseni broj " << broj << " nalazi se u intervalu izmedju 10 i 20." << endl;
		else {
			cout << "Uneseni broj nije u rasponu izmedju 10 i 20." << endl;
			cout << "Cijeli dio broja u:" << endl <<"1.)dekadskom sustavu: " << cijeliDio << endl;
			cout << "2.)heksadekadskom sustavu: " << hex << cijeliDio << endl;
			cout << "3.)oktalnom sustavu: " << oct << cijeliDio << endl;
		}
		break; 
	}
	default : cout << "Neispravan unos izbora!" << endl;

}
	system("PAUSE");
	return 0;
}
  