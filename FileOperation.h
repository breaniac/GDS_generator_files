#pragma once
#pragma warning(disable : 4996)
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

const char header[] = "300000";
const char guarantee[] = "300710";
const char name[] = "300680";
const char address[] = "300690";
const char trailer[] = "300999";

enum Records
{
	NA,
	GUARANTEE,
	NAME,
	ADDRESS,
	TRAILER
};

enum Attribute
{
	GUAR_REC_TYPE,
	GUAR_VER_TYPE,
	GUAR_SUB_CODE,
	GUAR_FIN_TYPE,
	GUAR_CONS_ACC_NUM,
	GUAR_AGR_NUM,
	GUAR_NAME,
	GUAR_COVERED_AMNT,
	GUAR_COVERED_AMOUNT_CURR,
	GUAR_AMNT,
	GUAR_CURR,
	GUAR_OPEN_D,
	GUAR_DUE_D,
	GUAR_CLOSE_D,
	GUAR_REASON_FOR_CLOSE,
	GUAR_RECORD_DEL_INDICATOR,
	GUAR_NUM_OF_BANK_HOLDERS,
	GUAR_FILT,

	NAME_REC_TYPE,
	NAME_VER_TYPE,
	NAME_SUB_CODE,
	NAME_FIN_TYPE,
	NAME_CONS_ACC_NUM,
	NAME_AGR_NUM,
	NAME_HOLD_NUM,
	NAME_SPECIAL_IND,
	NAME_HOLDER_TP,
	NAME_PRIM_ID_TP,
	NAME_PRIM_ID_NUMBER,
	NAME_PRIM_ID_EXP_D,
	NAME_PRIM_ID_ISSUE_D,
	NAME_PRIM_ID_PLACE_ISSUE,
	NAME_PRIM_ID_AUTH,
	NAME_SEC_ID_TP,
	NAME_SEC_ID_NUMBER,
	NAME_SEC_ID_EXP_D,
	NAME_SEC_ID_ISSUE_D,
	NAME_SEC_ID_PLACE_ISSUE,
	NAME_SEC_ID_AUTH,
	NAME_PENSION_NUMBER,
	NAME_PRIVATE_ENTREPRENEUR_NUMBER,
	NAME_PRIVATE_ENTREPRENEUR_ISSUE_D,
	NAME_PRIVATE_ENTREPRENEUR_EGRN_,
	NAME_PREVIOUS_ID_,
	NAME_SUPPLIED_NAME_FMT,
	NAME_NAME_TITLE_,
	NAME_FIRST_NAME_,
	NAME_PATRONYMIC_,
	NAME_SURNAME_,
	NAME_MAIDEN_NAME_,
	NAME_PREVIOUS_COMPANY_NM,
	NAME_SEX_CODE_,
	NAME_BIRTH_D,
	NAME_PLACE_OF_BIRTH_,
	NAME_CITIZENSHIP_,
	NAME_CONSENT_INDICATOR_,
	NAME_DATE_CONSENT_GIVEN_,
	NAME_MOBILE_TELEPHONE_NUMBER,
	NAME_SUBJECT_CODE_,
	NAME_CHANGE_TP,
	NAME_PRIM_ID_AUTHORITY_CODE_,


	ADDRESS_REC_TYPE,
	ADDRESS_VER_TYPE,
	ADDRESS_SUB_CODE,
	ADDRESS_FIN_TYPE,
	ADDRESS_CONS_ACC_NUM,
	ADDRESS_AGR_NUM,

	TRAIL_TOTAL_NAME_RECS,
	TRAIL_TOTAL_ADDRESS_RECS,
	TRAIL_TOTAL_GUAR_RECS
};

typedef struct {
	string strConsAccNum;
	unsigned int cntConsAccNum;;
	string strAgreementNum;
	unsigned int cntAgreementNum;
}ConsAgrNums;

class FileOperation
{
private:
	ifstream fileToAnalize;
	HANDLE outputfile;
	int userCnt = 0;

	struct gdsErr
	{
		gdsErr() : warnings(0),
				   ifNameWarrningTriggered(false), //Flag to mark that warrning applyed on the first name record ONLY
				   ifWriteWarning(false),
				   s_warnings("-ABCDEFGHKLMNOP"), //template Warning error
				   s_warrntingWriteToDisk(""), // This value will be write to OUPUT file and will generate Warning

				   general(0),
				   ifWriteGeneral(false),
				   s_general("        "), //template General error
				   s_GenCrit_GuarRecWriteToDisk(""), // This value will be write to OUPUT file and will generate General Error 

				   critical(0),
				   ifWriteCritical(false),
				   s_critical("00000000000000A") //template General error	
				   //s_CriticallWriteToDisk("") // This value will be write to OUPUT file and will generate Critical Error 
		{}

		int warnings;
		bool ifNameWarrningTriggered;
		bool ifWriteWarning;
		string s_warnings;
		string s_warrntingWriteToDisk;

		int general;
		bool ifWriteGeneral;
		string s_general;
		string s_GenCrit_GuarRecWriteToDisk;

		int critical;
		bool ifWriteCritical;
		string s_critical;
		//string s_CriticallWriteToDisk;
	}GdsErrors;

	// This data will be need for Trailer calculations
	struct RecCount
	{
		RecCount() : guarantee(0), name(0), address(0) {}
		int guarantee;
		int name;
		int address;
	}RecordsCount;


	ConsAgrNums attrNumContainer{"ACCOUNT",0,"GURANTEE NUMBER",0};
	vector<string> readedContainer;
	string s_guaranteeCriticalGeneralErrors;
	string s_nameWarrning;

	bool writeToDisk(string data);
	void DoProgressBar(char label[], int step, int total);

	bool collectRecords(string workString);
	Records recordFinder(size_t vectorRow);
	void attribureDispatcher(Records wichRecord, size_t vectorRow);
	bool attribModifier(Attribute wichAttribute, size_t vectorRow);

public:

	FileOperation();
	FileOperation(int w, int g, int c);
	~FileOperation();

	bool readTemplateFile(char * pathFile);
	bool writeOutputFile(char* pathFile, char* multiplyRecs, char* WarrningErr, char* GeneralErr, char* CriticalErr);

};

