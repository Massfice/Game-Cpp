#include "Headers/mycppdef.h"
#include "Headers/Classes/publicMechanics/publicMechanics.h"

class Menu
{
	protected:
	int i;
	string * options;
	int size;
	string wrongOption;
		
	public:
	void setArrayOption(string* str)
	{
		int buff = 0;
		int k;
		int p;
		for(k = 0; k < size; k++)
		{
			options[k] = "\r";
			 if(buff < str[k].size()) buff = str[k].size();
		}
		
		for(k = 0; k < size; k++)
		{
			options[k].append(str[k]);
			for(p = 0; p < buff - str[k].size(); p++)
			{
			options[k].append(" ");
			}
			
		}
	}
	
	Menu(string* str)
	{
		i = 0;
		size = arraySize(str);
		options = new string[size];
		wrongOption = "\nOpcja nie zosta³a zaprogramowana.";
		setArrayOption(str);
	}
	
	void setOption(bool next)
	{
		if(next)
		{
			i = i - 1;
			if(i < 0) i = size - 1;
		}
		else
		{
			i = i + 1;
			if(i > size - 1) i = 0;
		}
		
		cout << options[i];	
	}
	
	virtual void executeOption() = 0;
};

class MainMenu:public Menu {
	public:
	MainMenu(string* str):Menu(str)
	{
		cout << endl << endl << "                             MENU G£ÓWNE" << endl;
		cout << "     (wybierz pozycjê za pomoc¹ W|S, a nastêpnie kliknij Enter)" << endl << endl;	
		cout << options[i];
	}
	
	void executeOption()
	{
		switch(i)
		{
			case 3: exit(0); break;
			default: cout << wrongOption << endl << endl << options[i];
		}
	}
	
	private:
};
	
int main()
{
	setlocale(LC_ALL, "polish"); //polskie znaki
	
	newFullfilArray(string,str,"Nowa Gra", "Kontynuuj Grê","Autor","WyjdŸ");
	MainMenu* menu = new MainMenu(str);
	char c;
	while(1)
	{
		c = _getch();
		if(c == 's')
		{ //w dó³
			menu->setOption(false);
		}
		else if(c == 'w')
		{ //w górê
			menu->setOption(true);
		}
		else if((int)c == 13)
		{
			menu->executeOption();
		}
	}
	
	return 0;
}
