#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "longArifmetics.h"

using namespace std;

//function to print initial dialogue
void printInitial()
{
    cout << "Long arithmetics. Realised operations are: ";
    cout << " addition - ""+"", substraction - ""-"", multiplication - ""m"", dividing - ""/"", involution - ""^"", taking the residue - ""r"".\n";
    cout << "Command line arguments must be entered this way: \n";
    cout << "[inFile1] [operationSign] [inFile2] [resultFile] [-b(if necessary)] [moduleFile (if necessary)]\n";
}

//function to check whether number of parameters coincide
bool argumentsOk(int argc, char* argv[])
{
    if (argc < 5)
    {
        cout << "Too few arguments. Try again.\n";
        return false;
    }
    
    if (argc > 7)
    {
        cout << "Too many arguments. Try again.\n";
        return false;
    }
    
    if (strlen(argv[2]) > 1)
    {
        cout << "Wrong operation.\n";
        return false;
    }
    
    return true;
}


int main(int argc, char * argv[]) {
   
    printInitial();
    
    if (!argumentsOk(argc, argv))
    {
        return 0;
    }
    
    char* inFIle1 = argv[1];
    char operation = argv[2][0];
    char* inFIle2 = argv[3];
    char* resFile = argv[4];
    char* bin = NULL;
    char* moduleFile = NULL;
    
    int base = 0;
    bool isModule = false;
    
    if (argc == 5) //not binary
    {
        base = 1000000000;
    }
    
    if (argc == 6) // binary or module
    {
        if (!strcmp(argv[5], "-b"))
        {
            bin = argv[5];
            base = 256;
        }
        else
        {
            base = 1000000000;
            moduleFile = argv[5];
            isModule = true;
        }
    }
    
    if (argc == 7) //binary AND module or mistake
    {
        if (!strcmp(argv[5], "-b"))
        {
            bin = argv[5];
            base = 256;
            moduleFile = argv[6];
            isModule = true;
        }
        else
        {
            cout << "Too many arguments. Error!\n";
            return 0;
        }
    }
    
    
    longNum firstNum;
    longNum secNum;
    
    longNum resultNum;
    
    if(!firstNum.read(inFIle1, base))
    {
        cout << "An error occured in reading the first number!\n";
        return 0;
    }
    if(!secNum.read(inFIle2, base))
    {
        cout << "An error occured in reading the second number!\n";
        return 0;
    }
    
    switch(operation)
    {
        case '+':
            resultNum = firstNum + secNum;
            break;
        case '-':
            resultNum = firstNum - secNum;
            break;
        case 'm':
            resultNum = firstNum * secNum;
            break;
        case '/':
            resultNum = firstNum / secNum;
            break;
        case '^':
            resultNum = firstNum ^ secNum;
            break;
        case 'r':
            resultNum = firstNum % secNum;
            break;
        default:
            cout << "Wrong operation. Error.\n";
            return false;
            break;
    }
    
    if(isModule)
    {
        longNum modlongNum;
        longNum resModlongNum;
        if(!modlongNum.read(moduleFile, base))
        {
            cout << "An error occured in reading the module!\n";
            return 0;
        }
        resModlongNum = resultNum % modlongNum;
        resModlongNum.write(resFile);
        return 0;
    }
    
    resultNum.write(resFile);
    
    return 0;
}
