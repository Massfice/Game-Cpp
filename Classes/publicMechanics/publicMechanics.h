#ifndef PUBLICMECHANICS_H
#define PUBLICMECHANICS_H

struct tab
{
	int	size;
	std::string name;
};

tab** tabs  = new tab*;

class publicMechanics
{
	public:
		
	bool b = false; //wy�wietlanie ID opcji
	bool b2 = true; //dost�p do standardowego dzia�ania
	bool b3 = false; //powr�t do poprzedniego menu
	std::string password_id = "12345"; //has�o do menu ID Opcji
	
	std::string intToString (int a)
	{
    	std::ostringstream temp;
    	temp << a;
    	return temp.str();
	}
	
	int sizeOfArray(std::string name)
	{
		int i;
		for(i = 0; i <= l; i++)
		{
			if(tabs[i]->name==name) return tabs[i]->size;
		}
		return -1;
	}
};

publicMechanics* dm = new publicMechanics();

#endif
