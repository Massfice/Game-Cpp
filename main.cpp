#include "Headers/mycppdef.h"
#include "Headers/Classes/PublicMechanics/PublicMechanics.h"
#include "Headers/Classes/Menus/Menu.h"
#include "Headers/Classes/Menus/MainMenu.h"
	
int main()
{
	setlocale(LC_ALL, "polish"); //polskie znaki
	
	newFullfilArray(string,str,"Nowa Gra", "Kontynuuj Gr�","Autor","Wyjd�");
	MainMenu* menu = new MainMenu(str);
	menu->setOption();
	
	return 0;
}
