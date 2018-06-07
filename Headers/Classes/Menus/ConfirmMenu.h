#ifndef CONFIRMMENU
#define CONFIRMMENU
class ConfirmMenu:public Menu
{
	public:
	ConfirmMenu(string text, bool noAtFirst):Menu(text,noAtFirst)
	{
		menuText = text;
		menuText.append("\n");
		menuText.append(options[i]);
		refreshConsole(menuText);
	}
	
	void executeOption()
	{
		if(noAtFirst)
		{
			switch(i)
			{
				case 0: cbool = false; break;
				case 1: break; 
			}
		}
		else
		{
			switch(i)
			{
				case 0: break;
				case 1: cbool = false; break; 
			}
		}
	}
};
#endif
