#ifndef SETSEXMENU
#define SETSEXMENU
class SetSexMenu:public Menu
{
	private:
	string sex;
	
	public:
	SetSexMenu(string* str, string name):Menu(str,name)
	{
		menuText = "Wybierz p³eæ postaci:\n";
		menuText.append(options[i]);
		refreshConsole(menuText);
	}
	
	void executeOption()
	{
		switch(i)
		{
			case 0: sex = "M"; break;
			case 1: sex = "K";
		}
	}
	
	string getSex()
	{
		return sex;
	}
};
#endif
