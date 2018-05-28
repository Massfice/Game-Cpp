#ifndef MAINMENU
#define MAINMENU
class MainMenu:public Menu
{
	public:
	MainMenu(string* str):Menu(str)
	{	
		menuTextToRefresh = "\n\n                             MENU G£ÓWNE\n     (Wybierz pozycjê za pomoc¹ W|S, a nastêpnie kliknij Enter)\n\n";
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
