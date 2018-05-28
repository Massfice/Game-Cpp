#ifndef MAINMENU
#define MAINMENU
class MainMenu:public Menu
{
	public:
	MainMenu(string* str):Menu(str)
	{	
		menuTextToRefresh = "\n\n                             MENU G��WNE\n     (Wybierz pozycj� za pomoc� W|S, a nast�pnie kliknij Enter)\n\n";
		menuTextToRefresh.append(options[i]);
		refreshMenu();
	}
	
	private:
	void executeOption()
	{
		switch(i)
		{
			case 3: exit(0); break;
			default: cout << endl << endl << wrongOption << endl; system("pause");
		}
		
		isActive = true;
		refreshMenu();
	}
};
#endif
