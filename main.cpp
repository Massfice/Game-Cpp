#include "Headers/mycppdef.h"
#include "Headers/Classes/PublicMechanics/PublicMechanics.h"
#include "Headers/Classes/Menus/Menu.h"
#include "Headers/Classes/Menus/AuthorMenu.h"
#include "Headers/Classes/Menus/MainMenu.h"
	
int main()
{
	setlocale(LC_ALL, "polish"); //polskie znaki
	
	newFullfilArray(string,str,"Nowa Gra", "Kontynuuj Grê","Autor","WyjdŸ");
	MainMenu* menu = new MainMenu(awn(str));
	menu->setOption();
	
	//newFullfilArray(string,str,"Aby powróciæ do menu g³ównego, naciœnij Enter.");
	//			AuthorMenu* authorMenu = new AuthorMenu(str);
	//			authorMenu->setOption();
	
	return 0;
}
