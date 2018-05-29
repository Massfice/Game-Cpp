#ifndef EXITMENU
#define EXITMENU
class ExitMenu:public Menu
{
	public:
	ExitMenu(string* str, string name):Menu(str,name)
	{	
		menuText= "\n\nCzy na pewno chcesz wyjœæ?\n";
		menuText.append(options[i]);
		refreshConsole(menuText);
	}
	
	private:
	void executeOption()
	{
		switch(i)
		{
			case 0: break;
			case 1: exit(0); break;
			default: cout << endl << endl << wrongOption << endl; system("pause");
		}
	}
};
#endif
