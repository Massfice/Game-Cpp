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
		newFullfilArray(string,str5,"Wybierz inn¹ nazwê ","Zast¹p istniej¹cy profil ","Powrót ");
		ReplaceSaveMenu* rsmenu = new ReplaceSaveMenu(awn(str5));
		
		while(rsmenu->getCBool())
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
				counter = 0;
				system("pause");
				
			}
			
			if(rsmenu->getShouldReplace())
			{	
				newFullfilArray(string,str6,"Mê¿czyzna","Kobieta","Powrót");
				SetSexMenu* ssmenu = new SetSexMenu(awn(str6));
				ssmenu->setOption();
				if(ssmenu->getCBool()) break;
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
				string buff3 = "";
				
				buff1.append(ssmenu->getSex()); //P³eæ - split[0]
				buff1.append("|");
				buff1.append(cases[0]); //Mianownik - split[1]
				buff1.append("|");
				buff1.append(cases[1]); //Dope³niacz - split[2]
				buff1.append("|");
				buff1.append(cases[2]); //Celownik - split[3]
				buff1.append("|");
				buff1.append(cases[3]); //Biernik - split[4]
				buff1.append("|");
				buff1.append(cases[4]); //Narzêdnik - split[5]
				buff1.append("|");
				buff1.append(cases[5]); //Miejscownik - split[6]
				buff1.append("|");
				buff1.append(cases[6]); //Wo³acz - split[7]
				buff1.append("|");
				buff1.append("1"); //Poziom fabularny - split[8]
				buff1.append("|");
				buff1.append("1"); //Poziom postaci - split[9]
				buff1.append("|");
				buff1.append("1"); //Wytrzyma³oœæ postaci - split[10]
				buff1.append("|");
				buff1.append("1"); //Si³a postaci - split[11]
				buff1.append("|");
				buff1.append("1"); //Szybkoœæ postaci - split[12]
				buff1.append("|");
				buff1.append("1"); //Inteligencja postaci - split[13]
				buff1.append("|");
				buff1.append("1"); //Charyzma/Perswazja (Umiejêtnoœci Spo³eczne) postaci - split[14]
				buff1.append("|");
				buff1.append(""); //Przedmioty w "przy sobie", oddzielane za pomoc¹ plusa ("+") - split[15]
				buff1.append("|");
				buff1.append(""); //Przedmioty w sakiewce, oddzielane za pomoc¹ plusa ("+") - split[16]
				buff1.append("|");
				buff1.append(""); //Przedmioty w domu/skarbcu, oddzielane za pomoc¹ plusa ("+") - split[17]
				
				sysTIME = new SYSTEMTIME;
				GetSystemTime(sysTIME);
				
				hashedString* hs = dm->myHash(buff1,0,dm->multiplySTE(sysTIME));
				
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
				
				cout << "Gratulacje. Utworzy³eœ/³aœ profil." << endl;
				
				rsmenu->setCBool(false);
				system("pause");
			}
			
			rsmenu->setShouldReplace(false);
			
		}
		
		refreshConsole(menuText);
	}
};
#endif
