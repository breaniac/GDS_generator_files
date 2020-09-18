#pragma once

#define SUM_FIELD_OFFSET(x,y)   (x)+(y)

/* Guarantee Record
======================================================================================================================================================================
*/
#define GUARANTEE_RECORD_TYPE								(0)
#define GUARANTEE_RECORD_TYPE_LENGHT						(6)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUARANTEE_VERSION_TYPE								SUM_FIELD_OFFSET(GUARANTEE_RECORD_TYPE,GUARANTEE_RECORD_TYPE_LENGHT)
#define GUARANTEE_VERSION_TYPE_LENGHT						(2)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUARANTEE_SUBSCRIBER_CODE							SUM_FIELD_OFFSET(GUARANTEE_VERSION_TYPE,GUARANTEE_VERSION_TYPE_LENGHT)
#define GUARANTEE_SUBSCRIBER_CODE_LENGT						(5)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUARANTEE_FINANCE_TYPE								SUM_FIELD_OFFSET(GUARANTEE_SUBSCRIBER_CODE,GUARANTEE_SUBSCRIBER_CODE_LENGT)
#define GUARANTEE_FINANCE_TYPE_LENGT						(2)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUARANTEE_CONSUM_ACC_NUMBER							SUM_FIELD_OFFSET(GUARANTEE_FINANCE_TYPE,GUARANTEE_FINANCE_TYPE_LENGT)
#define GUARANTEE_CONSUM_ACC_NUMBER_LENGT					(40)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUARANTEE_AGREEMENT_NUM								SUM_FIELD_OFFSET(GUARANTEE_CONSUM_ACC_NUMBER,GUARANTEE_CONSUM_ACC_NUMBER_LENGT)
#define GUARANTEE_AGREEMENT_NUM_LENGT						(40)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUARANTOR_NAME										SUM_FIELD_OFFSET(GUARANTEE_AGREEMENT_NUM,GUARANTEE_AGREEMENT_NUM_LENGT)
#define GUARANTOR_NAME_LENGT								(150)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUAR_COVERED_AMOUNT									SUM_FIELD_OFFSET(GUARANTOR_NAME,GUARANTOR_NAME_LENGT)
#define GUAR_COVERED_AMOUNT_LENGT							(15)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUAR_COVERED_AMOUNT_CURRENCY						SUM_FIELD_OFFSET(GUAR_COVERED_AMOUNT,GUAR_COVERED_AMOUNT_LENGT)
#define GUAR_COVERED_AMOUNT_CURRENCY_LENGT					(3)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUAR_AMOUNT											SUM_FIELD_OFFSET(GUAR_COVERED_AMOUNT_CURRENCY,GUAR_COVERED_AMOUNT_CURRENCY_LENGT)
#define GUAR_AMOUNT_LENGT									(15)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUAR_CURRENCY										SUM_FIELD_OFFSET(GUAR_AMOUNT,GUAR_AMOUNT_LENGT)
#define GUAR_CURRENCY_LENGT									(3)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUAR_OPEN_DATE										SUM_FIELD_OFFSET(GUAR_CURRENCY,GUAR_CURRENCY_LENGT)
#define GUAR_OPEN_DATE_LENGT								(8)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUAR_DUE_DATE										SUM_FIELD_OFFSET(GUAR_OPEN_DATE,GUAR_OPEN_DATE_LENGT)
#define GUAR_DUE_DATE_LENGT									(8)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUAR_CLOSE_DATE										SUM_FIELD_OFFSET(GUAR_DUE_DATE,GUAR_DUE_DATE_LENGT)
#define GUAR_CLOSE_DATE_LENGT								(8)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUAR_REASON_FOR_CLOSURE								SUM_FIELD_OFFSET(GUAR_CLOSE_DATE,GUAR_CLOSE_DATE_LENGT)
#define GUAR_REASON_FOR_CLOSURE_LENGT						(2)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUAR_RECORD_DELETE_INDICATOR						SUM_FIELD_OFFSET(GUAR_REASON_FOR_CLOSURE,GUAR_REASON_FOR_CLOSURE_LENGT)
#define GUAR_RECORD_DELETE_INDICATOR_LENGT					(1)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUAR_NUM_OF_BANK_GUAR_HOLDERS						SUM_FIELD_OFFSET(GUAR_RECORD_DELETE_INDICATOR,GUAR_RECORD_DELETE_INDICATOR_LENGT)
#define GUAR_NUM_OF_BANK_GUAR_HOLDERS_LENGT					(2)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define GUAR_FILTER											SUM_FIELD_OFFSET(GUAR_NUM_OF_BANK_GUAR_HOLDERS,GUAR_NUM_OF_BANK_GUAR_HOLDERS_LENGT)
#define GUAR_FILTER_LENGT									(70)



/* Name Record
======================================================================================================================================================================
*/
#define NAME_RECORD_TYPE									(0)
#define NAME_RECORD_TYPE_LENGHT								(6)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_VERSION_TYPE									SUM_FIELD_OFFSET(NAME_RECORD_TYPE,NAME_RECORD_TYPE_LENGHT)
#define NAME_VERSION_TYPE_LENGHT							(2)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_SUBSCRIBER_CODE								SUM_FIELD_OFFSET(NAME_VERSION_TYPE,NAME_VERSION_TYPE_LENGHT)
#define NAME_SUBSCRIBER_CODE_LENGT							(5)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_FINANCE_TYPE									SUM_FIELD_OFFSET(NAME_SUBSCRIBER_CODE,NAME_SUBSCRIBER_CODE_LENGT)
#define NAME_FINANCE_TYPE_LENGT								(2)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_CONSUM_ACC_NUMBER								SUM_FIELD_OFFSET(NAME_FINANCE_TYPE,NAME_FINANCE_TYPE_LENGT)
#define NAME_CONSUM_ACC_NUMBER_LENGT						(40)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_AGREEMENT_NUM									SUM_FIELD_OFFSET(NAME_CONSUM_ACC_NUMBER,NAME_CONSUM_ACC_NUMBER_LENGT)
#define NAME_AGREEMENT_NUM_LENGT							(40)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_HOLDER_NUM										SUM_FIELD_OFFSET(NAME_AGREEMENT_NUM,NAME_AGREEMENT_NUM_LENGT)
#define NAME_HOLDER_NUM_LENGT								(2)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_SPECIAL_INDICATOR_INDICATOR					SUM_FIELD_OFFSET(NAME_HOLDER_NUM,NAME_HOLDER_NUM_LENGT)
#define NAME_SPECIAL_INDICATOR_INDICATOR_LENGT				(1)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_HOLDER_TYPE									SUM_FIELD_OFFSET(NAME_SPECIAL_INDICATOR_INDICATOR,NAME_SPECIAL_INDICATOR_INDICATOR_LENGT)
#define NAME_HOLDER_TYPE_LENGT								(2)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_PRIM_ID_TYPE									SUM_FIELD_OFFSET(NAME_HOLDER_TYPE,NAME_HOLDER_TYPE_LENGT)
#define NAME_PRIM_ID_TYPE_LENGT								(2)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_PRIM_ID_NUM									SUM_FIELD_OFFSET(NAME_PRIM_ID_TYPE,NAME_PRIM_ID_TYPE_LENGT)
#define NAME_PRIM_ID_NUM_LENGT								(20)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_PRIM_ID_EXP_DATE								SUM_FIELD_OFFSET(NAME_PRIM_ID_NUM,NAME_PRIM_ID_NUM_LENGT)
#define NAME_PRIM_ID_EXP_DATE_LENGT							(8)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_PRIM_ID_ISSUE_DATE								SUM_FIELD_OFFSET(NAME_PRIM_ID_EXP_DATE,NAME_PRIM_ID_EXP_DATE_LENGT)
#define NAME_PRIM_ID_ISSUE_DATE_LENGT						(8)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_PRIM_ID_PLACE_OF_ISSUE							SUM_FIELD_OFFSET(NAME_PRIM_ID_ISSUE_DATE,NAME_PRIM_ID_ISSUE_DATE_LENGT)
#define NAME_PRIM_ID_PLACE_OF_ISSUE_LENGT					(30)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_PRIM_ID_AUTHORITY								SUM_FIELD_OFFSET(NAME_PRIM_ID_PLACE_OF_ISSUE,NAME_PRIM_ID_PLACE_OF_ISSUE_LENGT)
#define NAME_PRIM_ID_AUTHORITY_LENGT						(100)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_SEC_ID_TYPE									SUM_FIELD_OFFSET(NAME_PRIM_ID_AUTHORITY,NAME_PRIM_ID_AUTHORITY_LENGT)
#define NAME_SEC_ID_TYPE_LENGT								(2)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_SEC_ID_NUM										SUM_FIELD_OFFSET(NAME_SEC_ID_TYPE,NAME_SEC_ID_TYPE_LENGT)
#define NAME_SEC_ID_NUM_LENGT								(20)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_SEC_ID_EXP_DATE								SUM_FIELD_OFFSET(NAME_SEC_ID_NUM,NAME_SEC_ID_NUM_LENGT)
#define NAME_SEC_ID_EXP_DATE_LENGT							(8)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_SEC_ID_ISSUE_DATE								SUM_FIELD_OFFSET(NAME_SEC_ID_EXP_DATE,NAME_SEC_ID_EXP_DATE_LENGT)
#define NAME_SEC_ID_ISSUE_DATE_LENGT						(8)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_SEC_ID_PLACE_OF_ISSUE							SUM_FIELD_OFFSET(NAME_SEC_ID_ISSUE_DATE,NAME_SEC_ID_ISSUE_DATE_LENGT)
#define NAME_SEC_ID_PLACE_OF_ISSUE_LENGT					(30)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_SEC_ID_AUTHORITY								SUM_FIELD_OFFSET(NAME_SEC_ID_PLACE_OF_ISSUE,NAME_SEC_ID_PLACE_OF_ISSUE_LENGT)
#define NAME_SEC_ID_AUTHORITY_LENGT							(100)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_PENSION_NUM									SUM_FIELD_OFFSET(NAME_SEC_ID_AUTHORITY,NAME_SEC_ID_AUTHORITY_LENGT)
#define NAME_PENSION_NUM_LENGT								(20)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_PRIVATE_ENTREPRENEUR_NUM						SUM_FIELD_OFFSET(NAME_PENSION_NUM,NAME_PENSION_NUM_LENGT)
#define NAME_PRIVATE_ENTREPRENEUR_NUM_LENGT					(20)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_PRIVATE_ENTREPRENEUR_ISSUE_DATE				SUM_FIELD_OFFSET(NAME_PRIVATE_ENTREPRENEUR_NUM,NAME_PRIVATE_ENTREPRENEUR_NUM_LENGT)
#define NAME_PRIVATE_ENTREPRENEUR_ISSUE_DATE_LENGT			(8)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_PRIVATE_ENTREPRENEUR_EGRN						SUM_FIELD_OFFSET(NAME_PRIVATE_ENTREPRENEUR_ISSUE_DATE,NAME_PRIVATE_ENTREPRENEUR_ISSUE_DATE_LENGT)
#define NAME_PRIVATE_ENTREPRENEUR_EGRN_LENGT				(20)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_PREVIOUS_ID									SUM_FIELD_OFFSET(NAME_PRIVATE_ENTREPRENEUR_EGRN,NAME_PRIVATE_ENTREPRENEUR_EGRN_LENGT)
#define NAME_PREVIOUS_ID_LENGT								(20)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_SUPPLIED_NAME_FORMAT							SUM_FIELD_OFFSET(NAME_PREVIOUS_ID,NAME_PREVIOUS_ID_LENGT)
#define NAME_SUPPLIED_NAME_FORMAT_LENGT						(1)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_NAME_TITLE										SUM_FIELD_OFFSET(NAME_SUPPLIED_NAME_FORMAT,NAME_SUPPLIED_NAME_FORMAT_LENGT)
#define NAME_NAME_TITLE_LENGT								(2)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_FIRST_NAME										SUM_FIELD_OFFSET(NAME_NAME_TITLE,NAME_NAME_TITLE_LENGT)
#define NAME_FIRST_NAME_LENGT								(100)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_PATRONYMIC										SUM_FIELD_OFFSET(NAME_FIRST_NAME,NAME_FIRST_NAME_LENGT)
#define NAME_PATRONYMIC_LENGT								(100)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_SURNAME										SUM_FIELD_OFFSET(NAME_PATRONYMIC,NAME_PATRONYMIC_LENGT)
#define NAME_SURNAME_LENGT									(150)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_MAIDEN_NAME									SUM_FIELD_OFFSET(NAME_SURNAME,NAME_SURNAME_LENGT)
#define NAME_MAIDEN_NAME_LENGT								(100)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_PREVIOUS_COMPANY_NAME							SUM_FIELD_OFFSET(NAME_MAIDEN_NAME,NAME_MAIDEN_NAME_LENGT)
#define NAME_PREVIOUS_COMPANY_NAME_LENGT					(100)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_SEX_CODE										SUM_FIELD_OFFSET(NAME_PREVIOUS_COMPANY_NAME,NAME_PREVIOUS_COMPANY_NAME_LENGT)
#define NAME_SEX_CODE_LENGT									(1)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_BIRTH_DATE										SUM_FIELD_OFFSET(NAME_SEX_CODE,NAME_SEX_CODE_LENGT)
#define NAME_BIRTH_DATE_LENGT								(8)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_PLACE_OF_BIRTH									SUM_FIELD_OFFSET(NAME_BIRTH_DATE,NAME_BIRTH_DATE_LENGT)
#define NAME_PLACE_OF_BIRTH_LENGT							(100)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_CITIZENSHIP									SUM_FIELD_OFFSET(NAME_PLACE_OF_BIRTH,NAME_PLACE_OF_BIRTH_LENGT)
#define NAME_CITIZENSHIP_LENGT								(2)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_CONSENT_INDICATOR								SUM_FIELD_OFFSET(NAME_CITIZENSHIP,NAME_CITIZENSHIP_LENGT)
#define NAME_CONSENT_INDICATOR_LENGT						(1)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_DATE_CONSENT_GIVEN								SUM_FIELD_OFFSET(NAME_CONSENT_INDICATOR,NAME_CONSENT_INDICATOR_LENGT)
#define NAME_DATE_CONSENT_GIVEN_LENGT						(8)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_MOBILE_TELEPHONE_NUM							SUM_FIELD_OFFSET(NAME_DATE_CONSENT_GIVEN,NAME_DATE_CONSENT_GIVEN_LENGT)
#define NAME_MOBILE_TELEPHONE_NUM_LENGT						(16)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_SUBJECT_CODE									SUM_FIELD_OFFSET(NAME_MOBILE_TELEPHONE_NUM,NAME_MOBILE_TELEPHONE_NUM_LENGT)
#define NAME_SUBJECT_CODE_LENGT								(15)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_CHANGE_TYPE									SUM_FIELD_OFFSET(NAME_SUBJECT_CODE,NAME_SUBJECT_CODE_LENGT)
#define NAME_CHANGE_TYPE_LENGT								(1)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define NAME_PRIM_ID_AUTHORITY_CODE							SUM_FIELD_OFFSET(NAME_CHANGE_TYPE,NAME_CHANGE_TYPE_LENGT)
#define NAME_PRIM_ID_AUTHORITY_CODE_LENGT					(7)





/* Address Record
======================================================================================================================================================================
*/
#define ADDRESS_RECORD_TYPE									(0)
#define ADDRESS_RECORD_TYPE_LENGHT							(6)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define ADDRESS_VERSION_TYPE								SUM_FIELD_OFFSET(ADDRESS_RECORD_TYPE,ADDRESS_RECORD_TYPE_LENGHT)
#define ADDRESS_VERSION_TYPE_LENGHT							(2)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define ADDRESS_SUBSCRIBER_CODE								SUM_FIELD_OFFSET(ADDRESS_VERSION_TYPE,ADDRESS_VERSION_TYPE_LENGHT)
#define ADDRESS_SUBSCRIBER_CODE_LENGT						(5)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define ADDRESS_FINANCE_TYPE								SUM_FIELD_OFFSET(ADDRESS_SUBSCRIBER_CODE,ADDRESS_SUBSCRIBER_CODE_LENGT)
#define ADDRESS_FINANCE_TYPE_LENGT							(2)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define ADDRESS_CONSUM_ACC_NUMBER							SUM_FIELD_OFFSET(ADDRESS_FINANCE_TYPE,ADDRESS_FINANCE_TYPE_LENGT)
#define ADDRESS_CONSUM_ACC_NUMBER_LENGT						(40)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define ADDRESS_AGREEMENT_NUM								SUM_FIELD_OFFSET(ADDRESS_CONSUM_ACC_NUMBER,ADDRESS_CONSUM_ACC_NUMBER_LENGT)
#define ADDRESS_AGREEMENT_NUM_LENGT							(40)

/* Trailer Record
======================================================================================================================================================================
*/
#define TRAILER_RECORD_TYPE									(0)
#define TRAILER_RECORD_TYPE_LENGHT							(6)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_VERSION_NUMBER								SUM_FIELD_OFFSET(TRAILER_RECORD_TYPE,TRAILER_RECORD_TYPE_LENGHT)
#define TRAILER_VERSION_NUMBER_LENGHT						(2)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_SUBSCRIBER_CODE								SUM_FIELD_OFFSET(TRAILER_VERSION_NUMBER,TRAILER_VERSION_NUMBER_LENGHT)
#define TRAILER_SUBSCRIBER_CODE_LENGHT						(5)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_FINANCE_TYPE								SUM_FIELD_OFFSET(TRAILER_SUBSCRIBER_CODE,TRAILER_SUBSCRIBER_CODE_LENGHT)
#define TRAILER_FINANCE_TYPE_LENGHT							(2)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_TOTAL_ACCOUNT_RECORDS						SUM_FIELD_OFFSET(TRAILER_FINANCE_TYPE,TRAILER_FINANCE_TYPE_LENGHT)
#define TRAILER_TOTAL_ACCOUNT_RECORDS_LENGHT				(9)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_TOTAL_HISTORY_RECORDS						SUM_FIELD_OFFSET(TRAILER_TOTAL_ACCOUNT_RECORDS,TRAILER_TOTAL_ACCOUNT_RECORDS_LENGHT)
#define TRAILER_TOTAL_HISTORY_RECORDS_LENGHT				(9)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_TOTAL_NAME_RECORDS							SUM_FIELD_OFFSET(TRAILER_TOTAL_HISTORY_RECORDS,TRAILER_TOTAL_HISTORY_RECORDS_LENGHT)
#define TRAILER_TOTAL_NAME_RECORDS_LENGHT					(9)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_TOTAL_ADDRESS_RECORDS						SUM_FIELD_OFFSET(TRAILER_TOTAL_NAME_RECORDS,TRAILER_TOTAL_NAME_RECORDS_LENGHT)
#define TRAILER_TOTAL_ADDRESS_RECORDS_LENGHT				(9)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_FILTER_0									SUM_FIELD_OFFSET(TRAILER_TOTAL_ADDRESS_RECORDS,TRAILER_TOTAL_ADDRESS_RECORDS_LENGHT)
#define TRAILER_FILTER_0_LENGHT								(9)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_TOTAL_EMPLOYER_RECORDS						SUM_FIELD_OFFSET(TRAILER_FILTER_0,TRAILER_FILTER_0_LENGHT)
#define TRAILER_TOTAL_EMPLOYER_RECORDS_LENGHT				(9)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_FILTER_1									SUM_FIELD_OFFSET(TRAILER_TOTAL_EMPLOYER_RECORDS,TRAILER_TOTAL_EMPLOYER_RECORDS_LENGHT)
#define TRAILER_FILTER_1_LENGHT								(9)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_FILTER_2									SUM_FIELD_OFFSET(TRAILER_FILTER_1,TRAILER_FILTER_1_LENGHT)
#define TRAILER_FILTER_2_LENGHT								(20)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_TOTAL_LEGAL_RECORDS							SUM_FIELD_OFFSET(TRAILER_FILTER_2,TRAILER_FILTER_2_LENGHT)
#define TRAILER_TOTAL_LEGAL_RECORDS_LENGHT					(9)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_TOTAL_WARRANTY_RECORDS						SUM_FIELD_OFFSET(TRAILER_TOTAL_LEGAL_RECORDS,TRAILER_TOTAL_LEGAL_RECORDS_LENGHT)
#define TRAILER_TOTAL_WARRANTY_RECORDS_LENGHT				(9)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_TOTAL_WARRANTY_HISTORY_RECORDS				SUM_FIELD_OFFSET(TRAILER_TOTAL_WARRANTY_RECORDS,TRAILER_TOTAL_WARRANTY_RECORDS_LENGHT)
#define TRAILER_TOTAL_WARRANTY_HISTORY_RECORDS_LENGHT		(9)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_TOTAL_GUARANTEE_RECORDS						SUM_FIELD_OFFSET(TRAILER_TOTAL_WARRANTY_HISTORY_RECORDS,TRAILER_TOTAL_WARRANTY_HISTORY_RECORDS_LENGHT)
#define TRAILER_TOTAL_GUARANTEE_RECORDS_LENGHT				(9)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_TOTAL_LIEN_RECORDS							SUM_FIELD_OFFSET(TRAILER_TOTAL_GUARANTEE_RECORDS,TRAILER_TOTAL_GUARANTEE_RECORDS_LENGHT)
#define TRAILER_TOTAL_LIEN_RECORDS_LENGHT					(9)
//-----------------------------------------------------------------------------------------------------------------------------------------
#define TRAILER_TOTAL_ASSIGNEE_RECORDS						SUM_FIELD_OFFSET(TRAILER_TOTAL_LIEN_RECORDS,TRAILER_TOTAL_LIEN_RECORDS_LENGHT)
#define TRAILER_TOTAL_ASSIGNEE_RECORDS_LENGHT				(9)



/* Records ID settings
======================================================================================================================================================================
*/
#define RECORDS_WINDOW			(6)
#define RECORDS_OFFSET			(0)
