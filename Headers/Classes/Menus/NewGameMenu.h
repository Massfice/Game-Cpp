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
			cinp(pname);
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
				cinp(cases[0]);
				cout <<"Dope³niacz (Kogo? Czego?): ";
				cinp(cases[1]);
				cout << "Celownik (Komu? Czemu?): ";
				cinp(cases[2]);
				cout << "Biernik (Kogo? Co?): ";
				cinp(cases[3]);
				cout << "Narzêdnik (Z kim? Z czym?): ";
				cinp(cases[4]);
				cout << "Miejscownik (O kim? O czym?): ";
				cinp(cases[5]);
				cout << "Wo³acz (O mój! O moja!): ";
				cinp(cases[6]);
				
				string buff1 = "";
				string buff2 = "";
				
				buff1.append(ssmenu->getSex());
				buff1.append("|");
				buff1.append(cases[0]);
				buff1.append("|");
				buff1.append(cases[1]);
				buff1.append("|");
				buff1.append(cases[2]);
				buff1.append("|");
				buff1.append(cases[3]);
				buff1.append("|");
				buff1.append(cases[4]);
				buff1.append("|");
				buff1.append(cases[5]);
				buff1.append("|");
				buff1.append(cases[6]);
				
				hashedString* hs = dm->myHash(buff1,0);
				
				cout << dm->myDeHash(hs,buff1.size(),0) << endl;
				
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
