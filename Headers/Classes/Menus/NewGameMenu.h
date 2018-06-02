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
		bool b2 = false;
		fileList* fl = dm->listOfFiles("Saves/","gcpp");
		string pname;
		int i;
		int counter = 0;
		newFullfilArray(string,str5,"Wybierz inn� nazw�","Zast�p istniej�cy profil","Powr�t");
		ReplaceSaveMenu* rsmenu = new ReplaceSaveMenu(awn(str5));
		
		while(rsmenu->getCBool())
		{
			system("cls");
			cout << "Podaj nazw� nowego profilu: ";
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
				counter = 0;
				system("pause");
				
			}
			
			if(rsmenu->getShouldReplace())
			{	
				newFullfilArray(string,str6,"M�czyzna","Kobieta","Powr�t");
				SetSexMenu* ssmenu = new SetSexMenu(awn(str6));
				ssmenu->setOption();
				if(ssmenu->getCBool()) break;
				menuText = "Odmie� swoje imi� przez przypadki:\n";
				refreshConsole(menuText);
   				string* cases = new string[7];
				
				cout << "Mianownik (Kto? Co?): ";
				cinp(cases[0]);
				cout <<"Dope�niacz (Kogo? Czego?): ";
				cinp(cases[1]);
				cout << "Celownik (Komu? Czemu?): ";
				cinp(cases[2]);
				cout << "Biernik (Kogo? Co?): ";
				cinp(cases[3]);
				cout << "Narz�dnik (Z kim? Z czym?): ";
				cinp(cases[4]);
				cout << "Miejscownik (O kim? O czym?): ";
				cinp(cases[5]);
				cout << "Wo�acz (O m�j! O moja!): ";
				cinp(cases[6]);
				
				string buff1 = "";
				string buff2 = "";
				string buff3 = "";
				
				buff1.append(ssmenu->getSex()); //P�e� - split[0]
				buff1.append("|");
				buff1.append(cases[0]); //Mianownik - split[1]
				buff1.append("|");
				buff1.append(cases[1]); //Dope�niacz - split[2]
				buff1.append("|");
				buff1.append(cases[2]); //Celownik - split[3]
				buff1.append("|");
				buff1.append(cases[3]); //Biernik - split[4]
				buff1.append("|");
				buff1.append(cases[4]); //Narz�dnik - split[5]
				buff1.append("|");
				buff1.append(cases[5]); //Miejscownik - split[6]
				buff1.append("|");
				buff1.append(cases[6]); //Wo�acz - split[7]
				buff1.append("|");
				buff1.append("1"); //Poziom fabularny - split[8]
				buff1.append("|");
				buff1.append("1"); //Poziom postaci - split[9]
				buff1.append("|");
				buff1.append("1"); //Wytrzyma�o�� postaci - split[10]
				buff1.append("|");
				buff1.append("1"); //Si�a postaci - split[11]
				buff1.append("|");
				buff1.append("1"); //Szybko�� postaci - split[12]
				buff1.append("|");
				buff1.append("1"); //Inteligencja postaci - split[13]
				buff1.append("|");
				buff1.append("1"); //Charyzma/Perswazja (Umiej�tno�ci Spo�eczne) postaci - split[14]
				buff1.append("|");
				buff1.append(""); //Przedmioty w "przy sobie", oddzielane za pomoc� plusa ("+") - split[15]
				buff1.append("|");
				buff1.append(""); //Przedmioty w sakiewce, oddzielane za pomoc� plusa ("+") - split[16]
				buff1.append("|");
				buff1.append(""); //Przedmioty w domu/skarbcu, oddzielane za pomoc� plusa ("+") - split[17]
				
				hashedString* hs = dm->myHash(buff1,0,2000000);
				
				int i;
				for(i = 0; i < buff1.size(); i++)
				{
					buff2.append(hs->String[i]);
					buff3.append(dm->toString(hs->Valid[i]));
					if(i < buff1.size() - 1)
					{
						buff2.append("|");
						buff3.append("|");
					}
				}
				
				buff1 = "0>";
				buff1.append(buff2);
				buff1.append(">");
				buff1.append(buff3);
				
				buff2 = "Saves/";
				buff2.append(pname);
				
				ofstream ofs;
				ofs.open(buff2.c_str(),ios::out);
				ofs << buff1;
				ofs.close();
				
				cout << "Gratulacje. Utworzy�e�/�a� profil." << endl;
				
				rsmenu->setCBool(false);
				system("pause");
			}
			
			rsmenu->setShouldReplace(false);
			
		}
		
		refreshConsole(menuText);
	}
};
#endif
