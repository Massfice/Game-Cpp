#ifndef NEWGAMEMENU
#define NEWGAMEMENU
class NewGameMenu:public Menu
{
	public:
	NewGameMenu(string* str, string name):Menu(str,name)
	{	
		menuText= "\n\n                              NOWA GRA\n     (Wybierz pozycj� za pomoc� W|S, a nast�pnie kliknij Enter)\n\n";
		menuText.append(options[i]);
		refreshConsole(menuText);
	}
	
	private:
	void executeOption()
	{
		switch(i)
		{
			case 0:
			{
				createNewProfile();
				break;
			}
			case 1: break;	
		}	
	}
	
	//Opcje Menu:
	void createNewProfile()
	{
		bool b = true;
		fileList* fl = dm->listOfFiles("Saves/","gcpp");
		string pname;
		int i;
		int counter = 0;
		
		while(b)
		{
			system("cls");
			cout << "Podaj nazw� nowego profilu: ";
			cin >> pname;
			pname.append(".gcpp");
			for(i = 0; i < fl->Size; i++)
			{
				if(fl->String[i] == pname) counter++;
			}
			
			if(counter == 0)
			{
				cout << "Gratulacje. Utworzy�e� profil." << endl;
				b = false;
				system("pause");
			}
			else
			{
				cout << "Niestety. Wybrany profil ju� istnieje. Kontynuuj i popraw b��dy... ";
				counter = 0;
				system("pause");
				
			}
			
		}
		
		isActive = true;
		refreshConsole(menuText);
	}
};
#endif
