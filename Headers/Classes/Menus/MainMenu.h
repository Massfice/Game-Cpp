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
	AuthorMenu* authorMenu;
	void executeOption()
	{
		switch(i)
		{
			case 2:
			{	
				newFullfilArray(string,str2,"Aby powr�ci� do menu g��wnego, naci�nij Enter.");
				authorMenu = new AuthorMenu(awn(str2));
				authorMenu->setOption();
				break;
			}
			case 3: exit(0); break;
			default: cout << endl << endl << wrongOption << endl; system("pause");
		}
		
		isActive = true;
		refreshConsole(menuText);
	}
};
#endif
