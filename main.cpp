#include <iostream>
#include "class.h"
#include <string.h>
using std::cout;

using namespace std;


bool action(LongNum A, LongNum B, LongNum Mod, char choice, LongNum& Result)
{
	if (Mod < (int)0)     
	{
		cout << "Negative Module!" << endl;
		return false;
	}

	if (choice == '^')   
	{
		Result = Pow(A, B, Mod);
		return true;
	}

	if (Mod > (int)0)
	{
		A = A % Mod;
		B = B % Mod;
	}

	switch (choice)
	{
	case '+':
		Result = A + B;
		break;

	case '-':
		Result = A - B;
		break;

	case '*':
		Result = A * B;
		break;

	case '/':
		Result = A / B;
		break;

	case '%':
		Result = A % B;
		break;

	default:
		cout << "Wrong choice." << endl;     
		
		return false;
	}

	if (Mod > (int)0)     
	{
		Result = Result % Mod;
		while (Result < (int)0)
			Result = Result + Mod;
	}

	return true;
}

int main(int argc, char* argv[])
{
	if (argc < 5)
	{
		cout << "Too few arguments!" << endl;  
		return -1;
	}

	if (argc > 7)
	{
		cout << "Too many arguments!" << endl; 
		return -1;
	}

	char* fileA = argv[1];    
	char choice = argv[2][0]; 
	char* fileB = argv[3];  
	char* fileRes = argv[4];
	bool bin = false;   
	char* ModFile = NULL;  

	if (argc == 6)
	{
		if (!strcmp(argv[5], "-b"))  
			bin = true;
		else
			ModFile = argv[5]; 
	}

	if (argc == 7) 
	{
		bin = true;
		ModFile = argv[6];
	}

	LongNum A, B, Mod = (int)0;

	if (bin)   
	{
		A.OutBinFile(fileA); 
		B.OutBinFile(fileB); 
		if (ModFile)  
			Mod.OutBinFile(ModFile); 
	}
	else   
	{
		A.OutFile(fileA); 
		B.OutFile(fileB);
		if (ModFile)  
			Mod.OutFile(ModFile); 
	}

	LongNum Result;

	if (!action(A, B, Mod, choice, Result))  
		return -1;

	if (bin)   
		Result.InBinFile(fileRes);  
	else
		Result.InFile(fileRes);

	return 0;
}
