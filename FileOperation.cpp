#include "stdafx.h"
#include "GDS_Atribute_Fields.h"
#include "FileOperation.h"

void spaceDispatcher(string& strSpaces, size_t lenght)
{
	size_t startSize = strSpaces.size();
	strSpaces.resize(lenght);
	for (size_t i = startSize; i < lenght; i++)
	{
		strSpaces[i] = 0x20;
	}

	startSize = 0;
}

void zeroDispatcher(string& strSpaces, size_t lenght)
{
	size_t strSize = strSpaces.size();
	string tmpString = strSpaces;
	tmpString.resize(lenght);

	size_t i = 0;
	for(; i < (lenght-strSize); i++)
	{
		tmpString[i] = '0';
	}

	for (size_t j =0; i < lenght; i++, j++)
	{
		tmpString[i] = strSpaces[j];
	}

	strSpaces = tmpString;
}


FileOperation::FileOperation()
{
	s_guaranteeCriticalGeneralErrors = "";
}

FileOperation::FileOperation(int w, int g, int c)
{
	GdsErrors.warnings = w;
	GdsErrors.general = g;
	GdsErrors.critical = c;
	s_guaranteeCriticalGeneralErrors = "";
}

FileOperation::~FileOperation()
{
}


/*==========================================================================================================================*/
bool FileOperation::collectRecords(string workString)
{
	size_t found;

	found = workString.find(guarantee, RECORDS_OFFSET, RECORDS_WINDOW);
	if (found != std::string::npos)
	{
		RecordsCount.guarantee++;
		return true;
	}

	found = workString.find(name, RECORDS_OFFSET, RECORDS_WINDOW);
	if (found != std::string::npos)
	{
		RecordsCount.name++;
		return true;
	}

	found = workString.find(address, RECORDS_OFFSET, RECORDS_WINDOW);
	if (found != std::string::npos)
	{
		RecordsCount.address++;
		return true;
	}

	return false;
}


/*==========================================================================================================================*/
bool FileOperation::attribModifier(Attribute wichAttribute, size_t vectorRow)
{
	switch (wichAttribute)
	{
	case GUAR_AMNT:
		{
			if (GdsErrors.critical > 0)
			{
				string temp = GdsErrors.s_critical;
				//GdsErrors.s_CriticallWriteToDisk = readedContainer[vectorRow];
				s_guaranteeCriticalGeneralErrors.replace(GUAR_AMOUNT, GUAR_AMOUNT_LENGT, temp);

				GdsErrors.critical--;
				GdsErrors.ifWriteCritical = true;
			}
		}
		break;

	case GUAR_CLOSE_D:
		{
			if (GdsErrors.general > 0)
			{
				string temp = GdsErrors.s_general;

				//GdsErrors.s_GeneralWriteToDisk = readedContainer[vectorRow];
				s_guaranteeCriticalGeneralErrors.replace(GUAR_CLOSE_DATE, GUAR_CLOSE_DATE_LENGT, temp);

				GdsErrors.general--;
				GdsErrors.ifWriteGeneral = true;
			}
		}
		break;

	case GUAR_AGR_NUM:
	{
		string temp = attrNumContainer.strAgreementNum + to_string(attrNumContainer.cntAgreementNum);
		spaceDispatcher(temp, GUARANTEE_AGREEMENT_NUM_LENGT);
		s_guaranteeCriticalGeneralErrors.replace(GUARANTEE_AGREEMENT_NUM, GUARANTEE_AGREEMENT_NUM_LENGT, temp);
	}
	break;

	case GUAR_CONS_ACC_NUM:
	{
		string temp = attrNumContainer.strConsAccNum + to_string(attrNumContainer.cntConsAccNum);
		spaceDispatcher(temp, GUARANTEE_CONSUM_ACC_NUMBER_LENGT);
		s_guaranteeCriticalGeneralErrors.replace(GUARANTEE_CONSUM_ACC_NUMBER, GUARANTEE_CONSUM_ACC_NUMBER_LENGT, temp);
	}
	break;

	case NAME_SUBJECT_CODE_:
		{
			if (GdsErrors.warnings > 0)
			{
				if (!GdsErrors.ifNameWarrningTriggered)
				{
					string temp = GdsErrors.s_warnings;

					//GdsErrors.s_warrntingWriteToDisk = readedContainer[vectorRow];
					s_nameWarrning.replace(NAME_SUBJECT_CODE, NAME_SUBJECT_CODE_LENGT, temp);

					GdsErrors.ifNameWarrningTriggered = true;
					GdsErrors.ifWriteWarning = true;
					GdsErrors.warnings--;
				}
			}
		}
		break;

	case NAME_CONS_ACC_NUM:
		{
			string temp = attrNumContainer.strConsAccNum + to_string(attrNumContainer.cntConsAccNum);
			spaceDispatcher(temp, NAME_CONSUM_ACC_NUMBER_LENGT);
			s_nameWarrning.replace(NAME_CONSUM_ACC_NUMBER, NAME_CONSUM_ACC_NUMBER_LENGT, temp);
		}
		break;

	case NAME_AGR_NUM:
	{
		string temp = attrNumContainer.strAgreementNum + to_string(attrNumContainer.cntAgreementNum);
		spaceDispatcher(temp, NAME_AGREEMENT_NUM_LENGT);
		s_nameWarrning.replace(NAME_AGREEMENT_NUM, NAME_AGREEMENT_NUM_LENGT, temp);
	}
	break;

	case ADDRESS_CONS_ACC_NUM:
		{
			string temp = attrNumContainer.strConsAccNum + to_string(attrNumContainer.cntConsAccNum);
			spaceDispatcher(temp, ADDRESS_CONSUM_ACC_NUMBER_LENGT);
			readedContainer[vectorRow].replace(ADDRESS_CONSUM_ACC_NUMBER, ADDRESS_CONSUM_ACC_NUMBER_LENGT, temp);
		}
		break;





	case ADDRESS_AGR_NUM:
		{
			string temp = attrNumContainer.strAgreementNum + to_string(attrNumContainer.cntAgreementNum);
			spaceDispatcher(temp, ADDRESS_AGREEMENT_NUM_LENGT);
			readedContainer[vectorRow].replace(ADDRESS_AGREEMENT_NUM, ADDRESS_AGREEMENT_NUM_LENGT, temp);
		}
		break;

	case TRAIL_TOTAL_GUAR_RECS:
		{
			string temp = to_string(RecordsCount.guarantee * userCnt);
			zeroDispatcher(temp, TRAILER_TOTAL_GUARANTEE_RECORDS_LENGHT);
			readedContainer[vectorRow].replace(TRAILER_TOTAL_GUARANTEE_RECORDS, TRAILER_TOTAL_GUARANTEE_RECORDS_LENGHT, temp);
		}
		break;

	case TRAIL_TOTAL_NAME_RECS:
		{
			string temp = to_string(RecordsCount.name * userCnt);
			zeroDispatcher(temp, TRAILER_TOTAL_NAME_RECORDS_LENGHT);
			readedContainer[vectorRow].replace(TRAILER_TOTAL_NAME_RECORDS, TRAILER_TOTAL_NAME_RECORDS_LENGHT, temp);
		}
		break;

	case TRAIL_TOTAL_ADDRESS_RECS:
		{
			string temp = to_string(RecordsCount.address * userCnt);
			zeroDispatcher(temp, TRAILER_TOTAL_ADDRESS_RECORDS_LENGHT);
			readedContainer[vectorRow].replace(TRAILER_TOTAL_ADDRESS_RECORDS, TRAILER_TOTAL_ADDRESS_RECORDS_LENGHT, temp);
		}
		break;
	}

	return true;
}


/*==========================================================================================================================*/
void FileOperation::attribureDispatcher(Records wichRecord, size_t vectorRow)
{
	string readedValue("");
	switch (wichRecord)
	{
	case GUARANTEE:
		s_guaranteeCriticalGeneralErrors = readedContainer[vectorRow];
		attribModifier(GUAR_CONS_ACC_NUM, vectorRow);
		attribModifier(GUAR_AGR_NUM, vectorRow);

		// Generate Critical Error
		attribModifier(GUAR_AMNT, vectorRow);
		// Generate General Error
		attribModifier(GUAR_CLOSE_D, vectorRow);
		break;

	case NAME:
		s_nameWarrning = readedContainer[vectorRow];
		attribModifier(NAME_CONS_ACC_NUM, vectorRow);
		attribModifier(NAME_AGR_NUM, vectorRow);

		//Generate Warrning
		attribModifier(NAME_SUBJECT_CODE_, vectorRow);
		break;

	case ADDRESS:
		attribModifier(ADDRESS_CONS_ACC_NUM, vectorRow);
		attribModifier(ADDRESS_AGR_NUM, vectorRow);
		break;

	case TRAILER:
		attribModifier(TRAIL_TOTAL_GUAR_RECS, vectorRow);
		attribModifier(TRAIL_TOTAL_NAME_RECS, vectorRow);
		attribModifier(TRAIL_TOTAL_ADDRESS_RECS, vectorRow);
		break;
	}
}


/*==========================================================================================================================*/
Records FileOperation::recordFinder(size_t vectorRow)
{
	size_t found;
	//string readedValue("");

	found = readedContainer[vectorRow].find(guarantee, RECORDS_OFFSET, RECORDS_WINDOW);
	if (found != std::string::npos)
	{
		return GUARANTEE;
	}

	found = readedContainer[vectorRow].find(name, RECORDS_OFFSET, RECORDS_WINDOW);
	if (found != std::string::npos)
	{
		return NAME;
	}

	found = readedContainer[vectorRow].find(address, RECORDS_OFFSET, RECORDS_WINDOW);
	if (found != std::string::npos)
	{
		return ADDRESS;
	}

	found = readedContainer[vectorRow].find(trailer, RECORDS_OFFSET, RECORDS_WINDOW);
	if (found != std::string::npos)
	{
		return TRAILER;
	}

	return NA;
}


/*==========================================================================================================================*/
bool FileOperation::readTemplateFile(char* pathFile)
{
	fileToAnalize.open(pathFile, ofstream::in | ofstream::binary);

	if (!fileToAnalize.is_open() )
		return false;
	else
	{
		string line;
		size_t readedSize = 0;
		while (getline(fileToAnalize, line))
		{
			readedSize = line.size();
			line.resize(readedSize + 1);
			line[readedSize] = 0x0a;

			readedContainer.push_back(line);
			collectRecords(line);
		}

		fileToAnalize.close();
		return true;
	}
}


bool FileOperation::writeToDisk(string data)
{
	BOOL bErrorFlag = FALSE;
	const char *DataBuffer = data.c_str();
	DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
	DWORD dwBytesWritten = 0;

	bErrorFlag = WriteFile(
				outputfile,           // open file handle
				DataBuffer,      // start of data to write
				dwBytesToWrite,  // number of bytes to write
				&dwBytesWritten, // number of bytes that were written
				NULL);            // no overlapped structure

	if (FALSE == bErrorFlag)
	{
		printf("Terminal failure: Unable to write to file.\n");
		return false;
	}
	else
	{
		if (dwBytesWritten != dwBytesToWrite)
		{
			// This is an error because a synchronous write that results in
			// success (WriteFile returns TRUE) should write all data as
			// requested. This would not necessarily be the case for
			// asynchronous writes.
			printf("Error: dwBytesWritten != dwBytesToWrite\n");
			return false;
		}
		else
		{
			return true;
		}
	}
}
void FileOperation::DoProgressBar(char label[], int step, int total)
{
	//progress width
	const int pwidth = 72;

	//minus label len
	int width = pwidth - (int)strlen(label);
	int pos = (step * width) / total;

	int percent = (step * 100) / total;

	//set green text color, only on Windows
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
	printf("%s", label);

	if (pos % 2 == 0)
	{
		//printf("%c", 0xb3);
		printf("%c", 0x2f);
	}
	else
	{
		//printf("%c", 0xc4);
		printf("%c", 0x5c);
	}

	printf(" %3d%%\r", percent);

	if (100 == percent)
	{
		printf("\n\r");
		printf("Complete\n\r");
	}

	//reset text color, only on Windows
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
}
/*==========================================================================================================================*/
bool FileOperation::writeOutputFile(char* pathFile, char* multiplyRecs, char* WarrningErr, char* GeneralErr, char* CriticalErr)
{
	userCnt = atoi(multiplyRecs);

	wchar_t* wtext = new wchar_t[strlen(pathFile) + 1];
	LPCWSTR pathFile1;
	mbstowcs(wtext, pathFile, strlen(pathFile) + 1);//Plus null
	pathFile1 = wtext;

	outputfile = CreateFile(pathFile1,              // name of the write
							GENERIC_WRITE,          // open for writing
							0,                      // do not share
							NULL,                   // default security
							CREATE_ALWAYS,          // Creates a new file, always.
							FILE_ATTRIBUTE_NORMAL,  // normal file
							NULL);                  // no attr. template

	if (outputfile == INVALID_HANDLE_VALUE)
	{
		delete[] wtext;
		return false;
	}
	else
	{
		writeToDisk(readedContainer[0]);
		Records currentRecord;

		for (int cnt = 1; cnt <= userCnt; cnt++)
		{
			attrNumContainer.cntAgreementNum = cnt;
			attrNumContainer.cntConsAccNum = cnt;

			unsigned int i = 1;
			//Warrning must be trrigered only for one NAME record for GDS Account (first one)
			GdsErrors.ifNameWarrningTriggered = false;

			for (; i < (readedContainer.size() - 1); i++)
			{
				currentRecord = recordFinder(i);
				// Find and modify the specific record
				attribureDispatcher(currentRecord, i);
				
				// Check and write the specific errors
				//if (NAME == currentRecord && GdsErrors.ifWriteWarning){
				if (NAME == currentRecord) {
					writeToDisk(s_nameWarrning);
					GdsErrors.ifWriteWarning = false;
				}
				//else if (GUARANTEE == currentRecord && (GdsErrors.ifWriteGeneral || GdsErrors.ifWriteCritical)){
				else if (GUARANTEE == currentRecord) {
					writeToDisk(s_guaranteeCriticalGeneralErrors);
					GdsErrors.ifWriteGeneral = false;
					GdsErrors.ifWriteCritical = false;
				}
				else {
					// If no errors, come on old
					writeToDisk(readedContainer[i]);
				}
				//if (GdsErrors.ifWriteCritical){
				//	writeToDisk(GdsErrors.s_CriticallWriteToDisk);
				//	GdsErrors.ifWriteCritical = false;
				//}
			}

			DoProgressBar("Generating: ", cnt, userCnt);
		}

		// Must call attribureDispatcher() for the trailer to update GUAR,NAME and ADDRESS records
		// Then must be called writeToDisk() for the trailer
		attribureDispatcher(recordFinder(readedContainer.size() - 1), readedContainer.size() - 1);
		writeToDisk(readedContainer[readedContainer.size() - 1]);

		delete[] wtext;
		return true; 
	}
}

