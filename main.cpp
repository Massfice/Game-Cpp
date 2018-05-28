#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <sstream>
#include <windows.h> // Sleep(int milisekundy) - usypia program na x milisekund, 1 sekunda = 1000 milisekund
#include <conio.h>
#include <cstddef>
#include <iterator>
#include <ctime>

#define tab(a) a,sizeof(a)/sizeof(a[0])


using namespace std;

class defaultMech {
	public:
	defaultMech(){}
	bool b = false; //wy�wietlanie ID opcji
	bool b2 = true; //dost�p do standardowego dzia�ania
	bool b3 = false; //powr�t do poprzedniego menu
	string password_id = "12345"; //has�o do menu ID Opcji
	
	string intToString (int a) { //funkcja skopiowana z internetu
    ostringstream temp;
    temp << a;
    return temp.str();
	}
};

defaultMech* dm = new defaultMech();

class Menu {
	protected:
	int i;
	string * str;
	string * options;
	int size;
	string wrongOption;
		
	public:
	void setArrayOption(bool showID) {
		int buff = 0;
		string * buff2 = new string[size];
		int k;
		int p;
		
		for(k = 0; k < size; k++) {
			buff2[k] = str[k];
			options[k] = "\r";
			if(showID) {
				buff2[k].append(" [ ID opcji = ");
				buff2[k].append(dm->intToString(k));
				buff2[k].append(" ]");
			}
			 
			if(buff < buff2[k].size()) buff = buff2[k].size();
		}
		
		for(k = 0; k < size; k++) {
			options[k].append(buff2[k]);
			for(p = 0; p < buff - buff2[k].size(); p++) {
			options[k].append(" ");
			}
			
		}
	}
		
	Menu(string str[], int size) {
		i = 0;
		this->size = size;
		this->str = str;
		options = new string[size];
		wrongOption = "\nOpcja nie zosta�a zaprogramowana.";
		
		setArrayOption(dm->b);
	}
	
	void setOption(bool next) {
		if(dm->b2) {
			if(next) {
				i = i - 1;
				if(i < 0) i = size - 1;
			} else {
				i = i + 1;
				if(i > size - 1) i = 0;
			}
		
			cout << options[i];
	}	
		}
	
	virtual void executeOption() = 0;
};

/*class GameMenu:public Menu {
	public:
	GameMenu(string str[],int size):Menu(str,size) {
		cout << endl << endl << "                                MENU GRY" << endl;
		cout << "     (wybierz pozycj� za pomoc� W|S, a nast�pnie kliknij Enter)" << endl << endl;	
		cout << options[i];
	}
	
	void executeOption() {
		switch(i) {
			
			default: cout << "\nOpcja nie zosta�a zaprogramowana. ID opcji = " << i << "." << endl << endl << options[i];
		}
	}
};*/

class idOptionsMenu:public Menu {
	
	public:
	idOptionsMenu(string str[], int size):Menu(str,size) {
		system("cls");
		dm->b2 = false;
		string access;
		
		cout << "Dost�p do tego menu jest chroniony has�em administratora. Podaj has�o: ";
		cin >> access;
		
		if(access == dm->password_id) {
			dm->b2 = true;
		} else {
			cout << endl << endl << "B��dne has�o. Naci�nij 'Enter', by wr�ci� do menu g��wnego.";
		}
		
		if(dm->b2) {
			system("cls");
			cout << endl << endl <<"Identyfikatory opcji oznaczaj� numer opcji jaki nale�y wpisa� we switchu/ifie w metodzie " <<
			"executeOption()." << endl << "Co chcesz zrobi�"
			<< "(wybierz pozycj� za pomoc� W|S, a nast�pnie kliknij Enter)?" << endl << options[i];	
		}
		
	}
	
	void executeOption() {
		switch(i) {
			case 0: dm->b = false; dm->b3 = true; break;
			case 1: dm->b = true; dm->b3 = true; break;
			case 2: changePassword(); dm->b3 = true; break;
			case 3: dm->b3 = true; break;
			default: cout << wrongOption << endl << endl << options[i];
		}	
	}
	
	void changePassword() {
		string s1;
		string s2;
		
		while(1) {
			cout << endl << endl << "Podaj nowe has�o. Je�li chcesz przerwa� proces wpisz 'exit'." << endl << "Nowe has�o: ";
			cin >> s1;
			if(s1 == "exit") {
				break;
			} else {
				dm->password_id = s1; //w przysz�o�ci has�o b�dzie zapisywane w pliku/bazie danych, a tre�� has�a b�dzie ukryta (string s2 - 
				               //dodatkowe zabezpieczenie)
				break;
			}
		}
	}
};

class MainMenu:public Menu {
	public:	
	MainMenu(string str[], int size):Menu(str,size) {
		cout << endl << endl << "                             MENU G��WNE" << endl;
		cout << "     (wybierz pozycj� za pomoc� W|S, a nast�pnie kliknij Enter)" << endl << endl;	
		cout << options[i];
	}
	
	void executeOption() {
		switch(i) {
			case 0: cout << endl << "Tutaj mia�a by� gra, ale p�ki co pokazuje tylko obecny czas. Przepraszam. "
			<< "Nie zd��y�em. Obecny czas = " << time(0) << "."
			<< endl << endl << options[i]; break; 
			case 2: idOptions(); break;
			case 4: exit(0); break;
			default: cout << wrongOption << endl << endl << options[i];
		}
	}
	
	private:
	void idOptions() {
		string s[] = {"Wy��cz widoczno�� ID","W��cz widoczno�� ID","Zmie� has�o","Wr��"};
		idOptionsMenu* idomenu = new idOptionsMenu(tab(s));
		char c;
		while(1) {
			c = _getch();
			if(c == 's') { //w d�
			idomenu->setOption(false);
			} else if(c == 'w') { //w g�r�
			idomenu->setOption(true);
			} else if((int)c == 13) {
			idomenu->executeOption();
			if(dm->b3) {
				dm->b3 = false;
				break;
			}
			}
		}
		
		setArrayOption(dm->b);
		
		system("cls");
		cout << endl << endl << "                             MENU G��WNE" << endl;
		cout << "     (wybierz pozycj� za pomoc� W|S, a nast�pnie kliknij Enter)" << endl << endl;
		cout << options[i];
		
	}
};
	
int main() {

	setlocale(LC_ALL, "polish"); //polskie znaki
	string str[] = {"Nowa Gra", "Kontynuuj Gr�", "Identyfikatory Opcji","Autor","Wyjd�"};
	MainMenu* menu = new MainMenu(tab(str));
	char c;
	while(1) {
		dm->b2 = true;
		c = _getch();
		if(c == 's') { //w d�
			menu->setOption(false);
		} else if(c == 'w') { //w g�r�
			menu->setOption(true);
		} else if((int)c == 13) {
			menu->executeOption();
		}
	}
	
	return 0;
}
