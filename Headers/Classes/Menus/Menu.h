#ifndef MENU
#define MENU
class Menu
{
	protected:
	string * options;
	string menuText = "";
	int size;
	int i;
	string wrongOption;
	bool isActive;
	virtual void executeOption() = 0;
	void refreshConsole(string TextToRefresh)
	{
		system("cls");
		cout << TextToRefresh;
	}
		
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
	
	Menu(string* str, string name)
	{
		i = 0;
		size = dm->sizeOfArray(name);
		options = new string[size];
		wrongOption = "\nOpcja nie zosta³a zaprogramowana.";
		isActive = true;
		setArrayOption(str);
	}
	
	void setOption()
	{
		char c;
		while(isActive)
		{
			c = _getch();
			if(c == 's')
			{
				i = i - 1;
				if(i < 0) i = size - 1;
			}
			else if(c == 'w')
			{
				i = i + 1;
				if(i > size - 1) i = 0;
			}
			else if((int)c == 13)
			{	
				isActive = false;
				executeOption();
			}
			cout << options[i];	
		}	
	}
};
#endif
