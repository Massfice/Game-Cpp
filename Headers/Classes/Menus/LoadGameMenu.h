#ifndef LOADGAMEMENU
#define LOADGAMEMENU
class LoadGameMenu:public Menu
{
	private:
	string* f;
	fileList* fl;
	int counter;
	
	public:
	LoadGameMenu(string* str, string name):Menu(str,name)
	{
		f = str;
		menuText = "Wczytaj zapis:\n";
		menuText.append(options[i]);
		refreshConsole(menuText);
	}
	
	void setFL(fileList* fl, int counter)
	{
		this->fl = fl;
		this->counter = counter;
	}
	
	void executeOption()
	{
		string buff = "Saves/";
		buff.append(f[i]);
		buff.append(".gcpp");
		ifstream ifs;
		ifs.open(buff.c_str(), ios::in);
		string gamestring;
		getline(ifs,gamestring,'\0');
		ifs.close();
		
		hashedString* hs2  = new hashedString;
		splitedString* ss1 = new splitedString;
		splitedString* ss2 = new splitedString;
		splitedString* ss3 = new splitedString;
		ss1 = dm->splitString(gamestring,'>');
		ss2 = dm->splitString(ss1->String[1],'|');
		ss3 = dm->splitString(ss1->String[2],'|');

		hs2->String = new string[ss2->Size];
		hs2->Valid =  new int[ss3->Size];
		int k;
		for(k = 0; k < ss2->Size; k++)
		{
			hs2->String[k] = ss2->String[k];
			hs2->Valid[k] = atoi(ss3->String[k].c_str());
		}
		
		int y = 0;
		
		cout << dm->myDeHash(hs2,ss2->Size,atoi(ss1->String[0].c_str()),dm->multiplySTE(fl->Dates[counter - 1])) << endl;
		
		system("pause");
	}	
};
#endif
