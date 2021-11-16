#include <conio.h>
#include <cstdio>
#include <iostream>
#include <stdio.h>  
#include <string.h>
#include <string>
#include <cstdlib>
#include <fstream>
#include <windows.h>

using namespace std;

void add()
{
	ofstream fs;
	string s;
	
	cout << "\n\t\t\t\t\t\tEnter your name file :";
	cin >> s;
	fs.open(s+".txt", ios::app | ios::out);
	//fs << s << '\t' << '\n';
	fs.close();
}

void view()
{
	string r,s;
	cout << "\t\t\t\t\t\tWhat is the name of your  file  ? (Pleas add .txt)\n\t\t\t\t\t\t";
	cin >> s;
	ifstream read(s);
	if (!read)
	{
		cout << "\t\t\t\t\t\tNot found!";
	}
	else
	{
		while (getline(read, r))
			{
				cout << "\n\t\t\t\t\t\t" << r;
			}
	}
	

}

void copy()
{
	ofstream z;
	string r,s,h;
	cout << "\t\t\t\t\t\tWhat is the name of your original file ? (Pleas add .txt)\n\t\t\t\t\t\t";
	cin >> s;
	cout << "\t\t\t\t\t\tWhat is the name of the new file to copy ?";
	cin >> h;
	ifstream read(s);
	if (!read) 
	{
		cout << "\t\t\t\t\t\tNot found!";
	}
	else
	{
	z.open(h + "copy.txt", ios::app | ios::out);
	while (getline(read, r))
		{
			
			z << r<<"\n";
			
		}
	cout << "\t\t\t\t\t\tSucses!";
	}
	
}

void movefile()
{
	ofstream z;
	string r,str,h;
	cout << "\t\t\t\t\t\tWhat is the name of your original file ?\n\t\t\t\t\t\t";
	cin >> str;	 str.append(".txt");
	cout << "\t\t\t\t\t\tWhat is the comp;ete address of the new file directory with slash? (ex: D:Software) \n";
	cin >> h;
	ifstream read(str);
	if (!read) 
	{
		cout << "\t\t\t\t\t\tNot found!";
	}
	else
	{
	const char* s = str.c_str();
//	ساخت آدرس مقصد
	h.append("/");
	h.append(str);
	const char* maghsad = h.c_str();
	CopyFile(s, maghsad , TRUE);
	//حذف فایل اول
	if( remove(s) != 0 )
    perror( "UnSuccessfully!" );
  else
    puts( "Successfully moved" );
}
}
void deletefile(){
	string str;
	cout << "\t\t\t\t\t\tWhat is the name of your file ?\n\t\t\t\t\t\t";
	cin >> str;
	str.append(".txt");
	const char* s = str.c_str();
	if( remove(s) != 0 )
    perror( "Error deleting file" );
  else
    puts( "File successfully deleted" );
	
// با  c++ 17
/*string searchfilename;
  cout << "Please enter the filename to be searched\n";
  cin >> searchfilename;
  try {
    if (filesystem::remove(searchfilename))
       cout << "file " << searchfilename << " deleted.\n";
    else
       cout << "file " << searchfilename << " not found.\n";
  }
  catch(const filesystem::filesystem_error& err) {
     cout << "filesystem error: " << err.what() << '\n';
  }*/
}
int main()
{
	int x;
	while (1)
	{
		cout << "\n\n\n\t\t\t\t\t\t1. Add \n"
			<< "\t\t\t\t\t\t2. View \n"
			<< "\t\t\t\t\t\t3. Copy \n"
			<< "\t\t\t\t\t\t4. Movefile \n"
			<< "\t\t\t\t\t\t5. Delete\n"
			<< "\t\t\t\t\t\t6. Exit\n"
			<< "\t\t\t\t\t\tEnter your choice-->";
		cin >> x;
		switch (x)
		{
		case 1:{add();
			_getch();
			system("cls");
		break;}
		case 2:{view();
			_getch();
			system("cls");
		break;}
		case 3:{copy();
			_getch();
			system("cls");
		break;}
		case 4:{movefile();
			_getch();
			system("cls");
		break;}
		case 5:{ deletefile();
				_getch();
			system("cls");
		break;}
		case 6:{ exit(0);}
		}
	}

}
