#ifndef DELETESAVESMENU
#define DELETESAVESMENU
class DeleteSavesMenu:public Menu
{	
	private:
	string* f;
	
	public:
	DeleteSavesMenu(string* str, string name):Menu(str,name)
	{
		f = str;
		menuText = "Wybierz zapis do usuniêcia:\n";
		menuText.append(options[i]);
		refreshConsole(menuText);
	}
	
	void executeOption()
	{
		newFullfilArray(string,strs2,"Nie","Tak");
		ConfirmDeleteSaveMenu* cdsmenu = new ConfirmDeleteSaveMenu(awn(strs2));
		cdsmenu->setOption();
		
		string buff = "Saves/";
		
		if(cdsmenu->getCBool())
		{
			buff.append(f[i]);
			buff.append(".gcpp");
			if(remove(buff.c_str()) != 0) perror("Deleting Error: ");
			else
			{
				cout << endl << "Zapis usuniêty." << endl;	
			}
			system("pause");
		}
		
	}
};
#endif
