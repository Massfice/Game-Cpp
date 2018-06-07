#include "Headers/mycppdef.h"
#include "Headers/Classes/PublicMechanics/PublicMechanics.h"
#include "Headers/Classes/Menus/Menu.h"
#include "Headers/Classes/Menus/ConfirmMenu.h"
#include "Headers/Classes/Menus/DeleteSavesMenu.h"
#include "Headers/Classes/Menus/SetSexMenu.h"
#include "Headers/Classes/Menus/ReplaceSaveMenu.h"
#include "Headers/Classes/Menus/NewGameMenu.h"
#include "Headers/Classes/Menus/AuthorMenu.h"
#include "Headers/Classes/Menus/ExitMenu.h"
#include "Headers/Classes/Menus/MainMenu.h"	

void hashSavesAtStart()
{
	fileList* tabz = dm->listOfFiles("Saves","gcpp");
	if(tabz->Size > 0)
	{
		string buff;
		string buff2 = "";
		string saves = "Saves/";
		ifstream ifs;
		ofstream ofs;
		splitedString* ss1;
		splitedString* ss2;
		splitedString* ss3;
		hashedString* hs;
		int ibuff;
		int i;
		int k;
		double sum = 0.0;
		int ave;
		for(i = 0; i < tabz->Size; i++)
		{
			GetSystemTime(sysTIME);
			try
			{	
				hs  = new hashedString;
				ss1 = new splitedString;
				ss2 = new splitedString;
				ss3 = new splitedString;
				saves.append(tabz->String[i]);
				ifs.open(saves.c_str(),ios::in);
				getline(ifs,buff,'\0');
				ss1 = dm->splitString(buff,'>');
				ibuff = atoi(ss1->String[0].c_str());
				ss2 = dm->splitString(ss1->String[1],'|');
				for(k = 0; k < ss2->Size; k++)
				{
					sum = sum + atof(ss2->String[k].c_str());
				}
				ave = sum / ss2->Size * 2;
				if(ave > 700 || ave < -700) ave = ave % 30;
				ss3 = dm->splitString(ss1->String[2],'|');
				hs->String = new string[ss2->Size];
				hs->Valid =  new int[ss3->Size];
				for(k = 0; k < ss2->Size; k++)
				{
					hs->String[k] = ss2->String[k];
					hs->Valid[k] = atoi(ss3->String[k].c_str());
				}
				buff = dm->myDeHash(hs,ss2->Size,ibuff,dm->multiplySTE(tabz->Dates[i]));
				ifs.close();
				if(dm->validGameString(buff))
				{
					hs = dm->myHash(buff,ave,dm->multiplySTE(sysTIME));
					buff2.append(dm->toString(ave));
					buff2.append(">");
					for(k = 0; k < buff.size(); k++)
					{
						buff2.append(hs->String[k]);
						if(k < buff.size() - 1) buff2.append("|");
					}
					buff2.append(">");
					for(k = 0; k < buff.size(); k++)
					{
						buff2.append(dm->toString(hs->Valid[k]));
						if(k < buff.size() - 1) buff2.append("|");
					}
					
					ofs.open(saves.c_str(),ios::out);
					ofs << buff2;
					ofs.close();	
					}
					else
					{
						string text = "Plik ";
						text.append(tabz->String[i]);
						text.append(" zosta³ uszkodzony. Czy chcesz rozpocz¹æ jego naprawê? Wybranie 'Nie' spowoduje jego usuniêcie.");
						ConfirmMenu* cm = new ConfirmMenu(text,false);
						cm->setOption();
						if(cm->getCBool())
						{
							long long xz = (long long)59 * (long long)23 * (long long)31;
							long long x = xz * (long long)12 * (long long)7 * (long long)atoi(dm->toString(sysTIME->wYear).c_str()) / 1000000; 
							long long x1;
							long long procent = x / 100 + 1;
							string procent2 = "\rPostêp: ";
							int procent3 = 0;
							for(x1 = 0; x1 <= x; x1++)
							{
								buff = dm->myDeHash(hs,ss2->Size,ibuff,x1);
								if(dm->validGameString(buff)) break;
								
								if(x1 % procent == 0)
								{
									procent3++;
									procent2.append(dm->toString(procent3));
									procent2.append(" %.                  ");
									cout << procent2;
									procent2 = "\rPostêp: ";
								}

							}
							
							cout << "\rPostêp: 100%.                  " << endl;
							
							if(dm->validGameString(buff))
							{
								GetSystemTime(sysTIME);
								hs = dm->myHash(buff,0,dm->multiplySTE(sysTIME));
				
								string buffer1 = "";
								string buffer2 = "";

								int iii;
								for(iii = 0; iii < buff.size(); iii++)
								{
									buffer1.append(hs->String[iii]);
									buffer2.append(dm->toString(hs->Valid[iii]));
									if(iii < buff.size() - 1)
									{
										buffer1.append("|");
										buffer2.append("|");
									}
								}
				
								string buffer3 = "0>";
								buffer3.append(buffer1);
								buffer3.append(">");
								buffer3.append(buffer2);
				
								string buffer4 = "Saves/";
								buffer4.append(tabz->String[i]);
				
								ofstream ofs;
								ofs.open(buffer4.c_str(),ios::out);
								ofs << buffer3;
								ofs.close();
								
								cout << "Uda³o siê naprawiæ plik!" << endl;;
								system("pause");
							}
							else
							{
								cout << "Niestety. Nie uda³o siê naprawiæ pliku... Plik zostanie usuniêty." << endl;
								string buffer5 = "Saves/";
								buffer5.append(tabz->String[i]);
								remove(buffer5.c_str());
								system("pause");
							}
							
						}
						else
						{
							string buffer6 = "Saves/";
							buffer6.append(tabz->String[i]);
							remove(buffer6.c_str());
						}
					}
					
					saves = "Saves/";
					buff ="";
					buff2 = "";
					
			}
			catch(exception e)
			{ 
				string cos = "Plik ";
				cos.append(tabz->String[i]);
				cos.append(" zosta³ krytycznie uszkodzony. Nast¹pi usuniêcie pliku.");
				cout << cos << endl;
				remove(buff2.c_str());
				system("pause");
			}	
		}
	}
}

int main()
{
	
	sysTIME = new SYSTEMTIME;
	
	setlocale(LC_ALL, "polish"); //polskie znaki
	
	hashSavesAtStart();
	
	newFullfilArray(string,str,"                             Nowa Gra",
	"                             Kontynuuj Grê",
	"                             Usuñ Zapis",
	"                             Autor",
	"                             WyjdŸ");
	MainMenu* menu = new MainMenu(awn(str));
	menu->setOption();
	
	return 0;
}
