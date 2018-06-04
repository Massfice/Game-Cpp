#ifndef MAINMENU
#define MAINMENU
class MainMenu:public Menu
{
	public:  
	MainMenu(string* str, string name):Menu(str,name)
	{	
		menuText= "\n\n                             MENU G��WNE\n     (Wybierz pozycj� za pomoc� W|S, a nast�pnie kliknij Enter)\n\n";
		menuText.append(options[i]);
		refreshConsole(menuText);
	}
	
	private:
	void executeOption()
	{
		switch(i)
		{	case 0: goToNewGame(); break;
			case 2: goToDeleteSaves(); break;
			case 3: goToAuthor(); break;
			case 4: goToExit(); break;
			default: wrongOptionDisplay();
		}
	}
	
	//Opcje Menu:
	void goToNewGame()
	{
		newFullfilArray(string,str3,"                 Stw�rz nowy profil i zacznij now� gr�!",
		                            "                             Powr�t");
		NewGameMenu* ngmenu = new NewGameMenu(awn(str3));
		ngmenu->setOption();
		isActive = true;
		refreshConsole(menuText);
	}
	
	void goToDeleteSaves()
	{
		fileList* fl = dm->listOfFiles("Saves/","gcpp");
		if(fl->Size != 0)
		{
			splitedString* ss;
			int i;
			newEmptyArray(string,strs1,fl->Size);
			for(i = 0; i < arraySize(strs1); i++)
			{
				ss = dm->splitString(fl->String[i],'.');
				strs1[i] = ss->String[0];
			}
		
			DeleteSavesMenu* dsmmenu = new DeleteSavesMenu(awn(strs1));
			dsmmenu->setOption();
			refreshConsole(menuText);
			
	
		}
		else
		{
			system("cls");
			cout << "Brak zapis�w." << endl;
			system("pause");
		}
		
		refreshConsole(menuText);
		isActive = true;		
	}
	
	void goToAuthor()
	{
		newFullfilArray(string,str2,"Aby powr�ci� do menu g��wnego, naci�nij Enter.");
		AuthorMenu* authorMenu = new AuthorMenu(awn(str2));
		authorMenu->setOption();
		isActive = true;
		refreshConsole(menuText);
	}
	
	void goToExit()
	{
		newFullfilArray(string,str3,"Nie","Tak");
		ExitMenu* exitMenu = new ExitMenu(awn(str3));
		exitMenu->setOption();
		isActive = true;
		refreshConsole(menuText);
	}
};
#endif
