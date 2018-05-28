#ifndef AUTHORMENU
#define AUTHORMENU
class AuthorMenu:public Menu
{
	public:
	AuthorMenu(string* str, string name):Menu(str,name)
	{	
		menuText= "Autor: Adrian Larysz\n";
		menuText.append(options[i]);
		refreshConsole(menuText);
	}
	
	private:
	void executeOption()
	{
		switch(i)
		{
			case 0: break;
			default: cout << endl << endl << wrongOption << endl; system("pause");
		}
	}
};
#endif
