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
	SYSTEMTIME* Dates;
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
	
	long long multiplySTE(SYSTEMTIME st)
	{
		return st.wYear * st.wMonth * st.wDay * st.wHour * st.wMinute * st.wDayOfWeek / 1000000;
	}
	
	long long multiplySTE(SYSTEMTIME* st)
	{
		return st->wYear * st->wMonth * st->wDay * st->wHour * st->wMinute * st->wDayOfWeek / 1000000;
	}
	
	string plString(string str)
	{
		const char* tab = str.c_str();
	
		string* PL = new string[123];
		//PL - Polish Letters, a nie Polska :)
		PL[91] = "π";
		PL[122] = "Ê";
		PL[87] = "Í";
		PL[120] = "≥";
		PL[28] = "Ò";
		PL[94] = "Û";
		PL[104] = "ú";
		PL[85] = "ü";
		PL[66] = "ø";
		PL[92] = "•";
		PL[113] = "∆";
		PL[88] = " ";
		PL[99] = "£";
		PL[29] = "—";
		PL[32] = "”";
		PL[105] = "å";
		PL[115] = "è";
		PL[67] = "Ø";
	
		int i;
		int ibuff;
		string sbuff = "";
		for(i = 0; i < str.size(); i++)
		{
			ibuff = (int)tab[i];
			if(ibuff < 0) sbuff.append(PL[ibuff * -1]); else sbuff.append(toString(tab[i]));
		}
		
		return sbuff;
	}

	string matchedString(string regS, string text)
	{
		
		string r;
		regex reg(regS.c_str(), regex_constants::ECMAScript);
		
		cout << text; 
		
		do
		{
			cin >> r;
			r = plString(r);
			if(!regex_match(r,reg)) cout << "Nie pasuje! Wprowadü ponownie: ";
		} while(!regex_match(r,reg));
		
		system("cls");
		
		return r;
	}
	
	bool validGameString(string gameString)
	{
		
		string buff = "^[KM]\\|([A-Z][a-zπÊÍÒ≥Ûøü]{2,}\\|){7}([1-9][0-9]*\\|){7}(([a-z]+";
		buff.append("(\\.[1-9]+)+(\\+[a-z]+(\\.[1-9]+)+)*)?\\|){3}(((0|-?([1-9]|[1-9][0-9]|100))\\|)*(0|-?([1-9]|[1-9][0-9]|100)){1})?$");
		regex reg(buff.c_str(),regex_constants::ECMAScript);
		
		return regex_match(gameString.c_str(),reg);
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
    	SYSTEMTIME* dates = new SYSTEMTIME[9999];
    	string buff = "/*.";
    	int counter = 0;
    	buff.append(fileExtension);
    
    	string search_path = folder + buff;
    	WIN32_FIND_DATA fd;
    	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd); 
    	
    	FILETIME ft;
    	int i = 0;
    	if(hFind != INVALID_HANDLE_VALUE)
		{	
			
        	do
			{
            	if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) )
				{	
					SYSTEMTIME st;
                	files[i] = fd.cFileName;
                	ft = fd.ftLastWriteTime;
                	FileTimeToSystemTime(&ft,&st);
                	dates[i] = st;
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
    	fl->Dates = dates;
    	fl->Size = counter;
    	
    	return fl;
	}
	
	hashedString* myHash(string str, int x, long long y)
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
			int ycounter = 2;
			do
			{
				c = c - x;
				c = c + y / ycounter;
				ycounter = ycounter * 2 - 1;
			} while(y / ycounter != 0);
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

	string myDeHash(hashedString* str, int size, int x, long long y)
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
				int ycounter = 2;
				do
				{
					ibuff1[size - 1 - i] = ibuff1[size - 1 - i] + x;
					ibuff1[size - 1 - i] = ibuff1[size - 1 - i] - y / ycounter;
					ycounter = ycounter * 2 - 1;
				} while(y / ycounter != 0);
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
		for(i = 0; i < l; i++)
		{
			if(tabs[l - i - 1]->name==name) return tabs[l - i - 1]->size;
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
					cout << "arrayAdding: Przekroczono zakres danych. Program zostanie zamkniÍty." << endl;
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
	
};

publicMechanics* dm = new publicMechanics();

#endif
