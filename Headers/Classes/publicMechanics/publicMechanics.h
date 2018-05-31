#ifndef PUBLICMECHANICS_H
#define PUBLICMECHANICS_H

struct tab
{
	int	size;
	int an = 0;
	string name;
};

struct splitedString
{
	string* String;
	int Size;	
};

struct hashedString
{
	string* String;
	int* Valid;
};

struct fileList
{
	string* String;
	int Size;
};

tab** tabs  = new tab*;

class publicMechanics
{
	public:
	template <typename t>
	string toString (t a)
	{
    	ostringstream temp;
    	temp << a;
    	return temp.str();
	}
	
	splitedString* splitString(string str, char c)
	{
		string* r;
		splitedString* ss = new splitedString;
		int i;
		int counter = 0;
		string buff = "";
	
		for(i = 0; i < str.size(); i++)
		{
			if(str[i] == c) counter++;
		}
	
		r = new string[counter + 1];
	
		ss->Size = counter + 1;
	
		counter = 0;
	
		for(i = 0; i < str.size(); i++)
		{
			if(str[i] != c) buff.append(toString(str[i])); else
			{
				if(buff != "") r[counter] = buff; else r[counter] = " ";
				buff = "";
				counter++;
			}
		}
	
		r[counter] = buff;
	
		ss->String = r;
	
		return ss;
	}
	
	fileList* listOfFiles(string folder, string fileExtension)
	{
		fileList* fl = new fileList;
    	string* files = new string[9999];
    	string buff = "/*.";
    	int counter = 0;
    	buff.append(fileExtension);
    
    	string search_path = folder + buff;
    	WIN32_FIND_DATA fd;
    	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd); 
    
    	int i = 0;
    	if(hFind != INVALID_HANDLE_VALUE)
		{ 
        	do
			{
            	if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) )
				{	
                	files[i] = fd.cFileName;
                	i++;
            	}
        } while(::FindNextFile(hFind, &fd)); 
        ::FindClose(hFind); 
    	}
    	
    	for(i = 0; i < 9999; i++)
    	{
    		if(files[i] != "") counter++; else break;
		}
    	
    	fl->String = files;
    	fl->Size = counter;
    	
    	return fl;
	}
	
	hashedString* myHash(string str, int x)
	{
		hashedString* h = new hashedString;
		h->Valid = new int[str.size()];
		string* r = new string[str.size()];
		string* rbuff = new string[str.size()];
		int** ibuff = new int*[str.size()];
		int* ibuff2 = new int[str.size()];
	
		int i;
		int k;
	
		srand(time(0));
		for(i = 0; i < str.size(); i++)
		{
			ibuff[i] = new int[4];
		}
	
		int c;
		int suma = 0;

		for(i = 0; i < str.size(); i++)
		{
			c = str[i];
			c = c + i;
			c = c - x;
			h->Valid[i] = (long)c;
			for(k = 0; k < 4; k++)
			{	
				ibuff[i][k] = rand() % 10;
				suma = suma + ibuff[i][k];
			}
		
			h->Valid[i] = h->Valid[i] + suma;
			c = c - suma;
			rbuff[i] = toString((int)c);
		
			suma = 0;
		}
	
		for(i = 0; i < str.size(); i++)
		{
			r[i] = rbuff[str.size() - i - 1];
			r[i].append(".");
			for(k = 0; k < 4; k++)
			{
				r[i].append(toString(ibuff[str.size() - i - 1][k]));
			}
		}
	
		h->String = r;
	
		return h;
	}

	string myDeHash(hashedString* str, int size, int x)
	{
		string r = "";
		string* sbuff1 = new string[size];
		string sbuff2 = "";
		string* sbuff3 = new string[size];
		int* ibuff1 = new int[size];
		int** ibuff2 = new int*[size];
		int ibuff3 = 0;
	
		int i;
		int k;
		for(i = 0; i < size; i++)
		{
			for(k = 0; k < 4; k++)
			{
				ibuff2[i] = new int[4];
			}
		}
	
		for(i = 0; i < size; i++)
		{
			sbuff1[i] = str->String[size - i - 1];
		}
	
		bool b = true;
		for(i = 0; i < size; i++)
		{
			for(k = 0; k < str->String[i].size(); k++)
			{
				if(b)
				{
					if(str->String[i][k] == '.') b = false; else
					{
						sbuff2.append(toString(str->String[i][k]));
					}
				}
				else
				{
					if(ibuff3 < 4)
					{
						ibuff2[i][ibuff3] = atoi(toString(str->String[i][k]).c_str());
						ibuff3++;
					}
				}
			}
		
			ibuff1[i] = atoi(sbuff2.c_str());
			sbuff2 = "";
			b = true;
			ibuff3 = 0;
		}
	
		int suma = 0;
		sbuff2 = "";
		for(i = 0; i < size; i++)
		{
			for(k = 0; k < 4; k++)
			{	
				suma = suma + ibuff2[size - 1 - i][k];
			}
		
			ibuff1[size - 1 - i] = ibuff1[size - 1 - i] + suma;
			if(ibuff1[size - 1 - i] + suma == str->Valid[i])
			{
				ibuff1[size - 1 - i] = ibuff1[size - 1 - i] - i;
				ibuff1[size - 1 - i] = ibuff1[size - 1 - i] + x;
				r.append(toString((char)ibuff1[size - 1 - i]));	
			}
			else
			{
				r.append(toString((char)33));
			}
		
			suma = 0;
		}
		return r;
	}
	
	int sizeOfArray(string name)
	{
		int i;
		for(i = 0; i <= l; i++)
		{
			if(tabs[i]->name==name) return tabs[i]->size;
		}
		return -1;
	}
	
	template <typename AddTo, typename AddIt>
	void arrayAdding(string name, AddTo to, AddIt it)
	{
		int i;
		for(i = 0; i <= l; i++)
		{
			if(tabs[i]->name == name)
			{
				if(tabs[i]->an >= sizeOfArray(name))
				{
					setlocale(LC_ALL, "polish");
					cout << "arrayAdding: Przekroczono zakres danych. Program zostanie zamkniêty." << endl;
					exit(0);
				}
				else
				{
					to[tabs[i]->an] = it;
					tabs[i]->an++;
				}
			}
		}
	}
	
	void hashSavesAtStart()
	{
		fileList* tab = listOfFiles("Saves","gcpp");
		if(tab->Size > 0)
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
			for(i = 0; i < tab->Size; i++)
			{
				try
				{	
					hs  = new hashedString;
					ss1 = new splitedString;
					ss2 = new splitedString;
					ss3 = new splitedString;
					saves.append(tab->String[i]);
					ifs.open(saves.c_str(),ios::in);
					getline(ifs,buff,'\0');
					ss1 = splitString(buff,'>');
					ibuff = atoi(ss1->String[0].c_str());
					ss2 = splitString(ss1->String[1],'|');
					for(k = 0; k < ss2->Size; k++)
					{
						sum = sum + atof(ss2->String[k].c_str());
					}
					ave = sum / ss2->Size * 2;
					if(ave > 700 || ave < -700) ave = ave % 30;
					ss3 = splitString(ss1->String[2],'|');
					hs->String = new string[ss2->Size];
					hs->Valid =  new int[ss3->Size];
					for(k = 0; k < ss2->Size; k++)
					{
						hs->String[k] = ss2->String[k];
						hs->Valid[k] = atoi(ss3->String[k].c_str());
					}
					buff = myDeHash(hs,ss2->Size,ibuff);
					ifs.close();
					hs = myHash(buff,ave);
					buff2.append(toString(ave));
					buff2.append(">");
					for(k = 0; k < buff.size(); k++)
					{
						buff2.append(hs->String[k]);
						if(k < buff.size() - 1) buff2.append("|");
					}
					buff2.append(">");
					for(k = 0; k < buff.size(); k++)
					{
						buff2.append(toString(hs->Valid[k]));
						if(k < buff.size() - 1) buff2.append("|");
					}
					
					ofs.open(saves.c_str(),ios::out);
					ofs << buff2;
					ofs.close();
					
					saves = "Saves/";
				} catch(exception e) { cout << "Coœ posz³o nie tak..."; }	
			}
		}
	}
	
};

publicMechanics* dm = new publicMechanics();

#endif
