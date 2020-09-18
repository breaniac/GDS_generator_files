// GDS_Generator.cpp : Defines the entry point for the console application.
//
#include "stdafx.h" 

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <windows.h>
#include <fstream>
#include <time.h>

#include "FileOperation.h"

//#define MY_DEBUG

#define INPUT_FILE			(1)
#define OUTPUT_FILE			(2)
#define USER_COUNTS			(3)

#define WARNINGS			(4)
#define GENERAL_E			(5)
#define CRITICAL_E			(6)

const string framework =
"================================================== Usage ver2.0 (Base) ==========================================\n\
autor: smihaylov                                                                                                  \n\
version: 1.0 (Base)                                                                                               \n\
version: 2.0 - Custom applay Warnings, General and Critical errors                                                \n\
******************************************************************************************************************\n\
<> - Mandatory params                                                                                             \n\
[] - Optional params                                                                                              \n\
                                                                                                                  \n\
   GDS_Generator.exe <In_GDS> <Output_GDS> <Nums_Of_Accounts> <Warnings> <General_Errors> <Critical_Errors>       \n\n\
------------------------------------------------------- Example --------------------------------------------------\n\
   GDS_Generator.exe 01_GDS.GDS TEST.GDS 100 20 10 50 (100 Account will be multiply, with 20 Warnings, 10 General \n\
                                                       and 50 Critical errors)                                    \n\
==================================================================================================================\n\
";

 
int main(int argc, char* argv[])
{
#ifndef MY_DEBUG
	if (argc == 1)
	{
		cout << framework << endl;
	}
	else if (argc > 1 && argc < 7)
		cout << "Missing arguments !!!" << endl;
	else if (argc > 7)
		cout << "Too much argument !!!" << endl;
	else
	{
		int cmp1 = 0;
		int cmp2 = 0;
		bool ok_flg = true;

		if ( (cmp1 = atoi(argv[USER_COUNTS])) < (cmp2 = atoi(argv[WARNINGS])) )
		{
			cout << "REMARK: Warrning errors must be equal or less than number of accounts !" << endl;
			ok_flg = false;
		}

		if ( (cmp1 = atoi(argv[USER_COUNTS])) < (cmp2 = atoi(argv[GENERAL_E])) )
		{
			cout << "REMARK: General errors must be equal or less than number of accounts !" << endl;
			ok_flg = false;
		}

		if ( (cmp1 = atoi(argv[USER_COUNTS])) < (cmp2 = atoi(argv[CRITICAL_E])) )
		{
			cout << "REMARK: Critical errors must be equal or less than number of accounts !" << endl;
			ok_flg = false;
		}

		if (ok_flg)
		{
			FileOperation obj(atoi(argv[WARNINGS]), atoi(argv[GENERAL_E]), atoi(argv[CRITICAL_E]));

			obj.readTemplateFile(argv[INPUT_FILE]);
			obj.writeOutputFile(argv[OUTPUT_FILE], argv[USER_COUNTS], argv[WARNINGS], argv[GENERAL_E], argv[CRITICAL_E]);
		}
	}
	//system("PAUSE");
#else

	char* mult = "3";
	char* warrErr = "2";
	char* genErr = "1";
	char* critErr = "3";

	int cmp1 = 0;
	int cmp2 = 0;

	if ((cmp1 = atoi(mult)) <
		(cmp2 = atoi(warrErr)))
	{
		cout << "REMARK: Warrning errors must be equal or less than number of accounts !" << endl;
	}

	if ((cmp1 = atoi(mult)) <
		(cmp2 = atoi(genErr)))
	{
		cout << "REMARK: General errors must be equal or less than number of accounts !" << endl;
	}

	if ((cmp1 = atoi(mult)) <
		(cmp2 = atoi(critErr)))
	{
		cout << "REMARK: Critical errors must be equal or less than number of accounts !" << endl;
	}
	
	FileOperation obj(atoi(warrErr), atoi(genErr), atoi(critErr));
	obj.readTemplateFile("01_GDS.GDS");
	obj.writeOutputFile("Test.GDS", mult, warrErr, genErr, critErr);
#endif
	return 0;
}

