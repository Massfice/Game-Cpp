#include "Headers/mycppdef.h"
#include "Headers/Classes/PublicMechanics/PublicMechanics.h"
#include "Headers/Classes/Menus/Menu.h"
#include "Headers/Classes/Menus/NewGameMenu.h"
#include "Headers/Classes/Menus/AuthorMenu.h"
#include "Headers/Classes/Menus/ExitMenu.h"
#include "Headers/Classes/Menus/MainMenu.h"
	
int main()
{
	setlocale(LC_ALL, "polish"); //polskie znaki
	
	dm->hashSavesAtStart();
	
	newFullfilArray(string,str,"                             Nowa Gra",
	"                             Kontynuuj Grê",
	"                             Autor",
	"                             WyjdŸ");
	MainMenu* menu = new MainMenu(awn(str));
	menu->setOption();
	
	return 0;
}
