#ifndef CONFIRMDELETESAVEMENU
#define CONFIRMDELETESAVEMENU
class ConfirmDeleteSaveMenu:public Menu
{
	public:
	ConfirmDeleteSaveMenu(string* str, string name):Menu(str,name)
	{
		menuText = "Czy rzezczywi�cie chcesz usun�� ten plik?\n";
		menuText.append(options[i]);
		refreshConsole(menuText);
	}
	
	void executeOption()
	{
		switch(i)
		{
			case 0: cbool = false; break;
			case 1: break; 
		}
	}
};
#endif
