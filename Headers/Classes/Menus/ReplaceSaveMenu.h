#ifndef REPLACESAVEMENU
#define REPLACESAVEMENU
class ReplaceSaveMenu:public Menu
{
	private:
	bool shouldReplace;
	bool cbool;
	
	public:
	ReplaceSaveMenu(string* str, string name):Menu(str,name)
	{
		shouldReplace = false;
		cbool = true;
		menuText = "Niestety. Wybrany profil ju¿ istnieje. Co chcesz zrobiæ?\n";
		menuText.append(options[i]);
	}
	
	void setOption()
	{
		refreshConsole(menuText);
		Menu::setOption();
	}
	
	void executeOption()
	{
		switch(i)
		{
			case 0: break;
			case 1: shouldReplace = true; break;
			case 2: cbool = false;
		}
	}
	
	bool getShouldReplace()
	{
		return shouldReplace;
	}
	
	void setShouldReplace(bool shouldReplace)
	{
		this->shouldReplace = shouldReplace;
	}
	
	bool getCBool()
	{
		return cbool;
	}
	
	void setCBool(bool cbool)
	{
		this->cbool = cbool;
	}
	
	void active()
	{
		isActive = true;
	}
};
#endif
