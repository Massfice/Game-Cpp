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
		{
			case 2: goToAuthor(); break;
			case 3: goToExit(); break;
			default: wrongOptionDisplay();
		}
	}
	
	//Opcje Menu:
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
