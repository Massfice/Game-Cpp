#ifndef NEWGAMEMENU
#define NEWGAMEMENU
class NewGameMenu:public Menu
{	
	public:
	NewGameMenu(string* str, string name):Menu(str,name)
	{	
		menuText= "\n\n                              NOWA GRA\n     (Wybierz pozycjê za pomoc¹ W|S, a nastêpnie kliknij Enter)\n\n";
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
		bool b2 = false;
		fileList* fl = dm->listOfFiles("Saves/","gcpp");
		string pname;
		int i;
		int counter = 0;
		newFullfilArray(string,str5,"Wybierz inn¹ nazwê","Zast¹p istniej¹cy profil");
		ReplaceSaveMenu* rsmenu = new ReplaceSaveMenu(awn(str5));
		
		while(b)
		{
			system("cls");
			cout << "Podaj nazwê nowego profilu: ";
			cin >> pname;
			pname.append(".gcpp");
			for(i = 0; i < fl->Size; i++)
			{
				if(fl->String[i] == pname) counter++;
			}
			
			if(counter == 0)
			{
				rsmenu->setShouldReplace(true);
			}
			else
			{
				rsmenu->active();
				rsmenu->setOption();
				cout << endl;
				counter = 0;
				system("pause");
				
			}
			
			if(rsmenu->getShouldReplace())
			{
				newFullfilArray(string,str6,"Mê¿czyzna","Kobieta");
				SetSexMenu* ssmenu = new SetSexMenu(awn(str6));
				ssmenu->setOption();
				menuText = "Odmieñ swoje imiê przez przypadki:\n";
				refreshConsole(menuText);
				string* cases = new string[7];
				cout << "Mianownik (Kto? Co?): ";
				cin >> cases[0];
				cout << "Dope³niacz (Kogo? Czego?): ";
				cin >> cases[1];
				cout << "Celownik (Komu? Czemu?): ";
				cin >> cases[2];
				cout << "Biernik (Kogo? Co?): ";
				cin >> cases[3];
				cout << "Narzêdnik (Z kim? Z czym?): ";
				cin >> cases[4];
				cout << "Miejscownik (O kim? O czym?): ";
				cin >> cases[5];
				cout << "Wo³acz (O mój! O moja!): ";
				cin >> cases[6];
				string buff = "";
				cout << "Gratulacje. Utworzy³eœ/³aœ profil." << endl;
				b = false;
				system("pause");
			}
			
			rsmenu->setShouldReplace(false);
			
		}
		
		refreshConsole(menuText);
	}
};
#endif
