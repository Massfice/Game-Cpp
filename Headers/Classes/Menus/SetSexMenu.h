#ifndef SETSEXMENU
#define SETSEXMENU
class SetSexMenu:public Menu
{
	private:
	string sex;
	bool cbool;
	
	public:
	SetSexMenu(string* str, string name):Menu(str,name)
	{
		menuText = "Wybierz p³eæ postaci (lub wróæ do Menu G³ównego):\n";
		menuText.append(options[i]);
		cbool = false;
		refreshConsole(menuText);
	}
	
	void executeOption()
	{
		switch(i)
		{
			case 0: sex = "M"; break;
			case 1: sex = "K"; break;
			case 2: cbool = true;
		}
	}
	
	bool getCBool()
	{
		return cbool;
	}
	
	string getSex()
	{
		return sex;
	}
};
#endif
