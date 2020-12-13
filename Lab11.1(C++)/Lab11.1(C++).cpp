#include <iostream>
#include<fstream>
#include <Windows.h>
#include <string>
using namespace std;

void CreateBIN(const char* File_Name);
void ProcessBIN1(const char* File_Name, const char* File_Result);
void PrintBIN(const char* File_Result);
void Process(const char* File_Name, const char* File_Result);

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    CreateBIN("FirstFile.dat");

    PrintBIN("FirstFile.dat");

    Process("FirstFile.dat", "Result.dat");

    PrintBIN("Result.dat");

    return 0;
}

void CreateBIN(const char* File_Name)  
{
    ofstream fout(File_Name, ios::binary);    
    char ch;                 
    string s; 
    string m = " ";
    do
    {
        cout << "enter line: ";
        cin >> s;// ввелирядок
        for (unsigned i = 0; i < s.length(); i++)
        {
            fout.write((char*)&s[i], sizeof(s[i]));
        }
        cout << "continue? (y/n): "; cin >> ch;
        fout << " ";
    }while(ch == 'y'|| ch == 'Y');
    cout << endl;
}
void PrintBIN(const char* File_Name)     
{ifstream fin(File_Name, ios::binary);    
char c;                                  
while( fin.read((char*)&c, sizeof(c) )) 
{
    cout << c;                   
}
cout<< endl;
}
int search(const char* First_File)
{
    ifstream f(First_File, ios::binary);
    char c[200];
    char g[] = " ";
    while (!f.eof())
    {
        f.read((char*)&c, sizeof(c));
        if (c != g)
        {
            f.read((char*)&c, sizeof(c));
            if (strchr(c, 'i'))
            {
                char* x = strchr(c, 'i');
                f.read((char*)&c, sizeof(c));
                if (strchr(c, 'n'))
                {
                    f.read((char*)&c, sizeof(c));
                    if (strchr(c, 'f'))
                    {
                        f.read((char*)&c, sizeof(c));
                        if (strchr(c, 'o'))
                        {
                            f.read((char*)&c, sizeof(c));
                            if (strchr(c, 'r'))
                            {
                                f.read((char*)&c, sizeof(c));
                                if (strchr(c, 'm'))
                                {
                                    f.read((char*)&c, sizeof(c));
                                    if (strchr(c, 'a'))
                                    {
                                        f.read((char*)&c, sizeof(c));
                                        if (strchr(c, 't'))
                                        {
                                            f.read((char*)&c, sizeof(c));
                                            if (strchr(c, 'i'))
                                            {
                                                f.read((char*)&c, sizeof(c));
                                                if (strchr(c, 'k'))
                                                {
                                                    f.read((char*)&c, sizeof(c));
                                                    if (strchr(c, 'a'))
                                                    {
                                                        return (int)x;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Process(const char* File_Name, const char* File_Result)
{
    ifstream First_File(File_Name, ios::binary);
    ofstream Second_File(File_Result, ios::binary);
    int count = 0;
    char y[200];
    char g[] = " ";
    while (First_File.read((char*)&y, sizeof(y)))
    {
        if (y == g) { count = 0; }
        if (count > search(File_Name))
            Second_File.write((char*)&y, sizeof(y));
        count++;
    }
}
