#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_NONSTDC_NO_WARNINGS
#include <stdint.h>
//#include <card.h>
#include <stdio.h>
/*
typedef struct ST_cardData_t
{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[6];
}ST_cardData_t;
typedef struct ST_terminalData_t
{
    float transAmount;
    float maxTransAmount;
    uint8_t transactionDate[11];
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
    TERMINAL_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;

typedef enum EN_transStat_t
{
    APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, FRAUD_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t;

typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t terminalData;
    EN_transState_t transState;
    uint32_t transactionSequenceNumber;
}ST_transaction_t;

typedef enum EN_serverError_t
{
    SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE, BLOCKED_ACCOUNT
}EN_serverError_t;

typedef enum EN_accountState_t
{
    RUNNING,
    BLOCKED
}EN_accountState_t;

typedef struct ST_accountsDB_t
{
    float balance;
    EN_accountState_t state;
    uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;


EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence)
{
	if (termData->transAmount > accountRefrence->balance)
		return LOW_BALANCE;
	return SERVER_OK;
}

void isAmountAvailableTest(void)
{
    static char counter;
    ST_terminalData_t termData[20];
    ST_accountsDB_t accountRefrence;
    accountRefrence.balance = 8000.0;
    EN_terminalError_t error = TERMINAL_OK;
    termData[counter].maxTransAmount = 8000.0;
    termData[counter].transAmount = 1000.0 + (500.0 * counter);
    error = isAmountAvailable(&termData[counter],&accountRefrence);
    printf("Tester Name: Matarawy\n");
    printf("Test case : %d\n",counter+1);
    printf("Input Data: maxTransAmount = %2.f and transAmount = %2.f\n", accountRefrence.balance, termData[counter].transAmount);
    if (error == LOW_BALANCE)
        printf("Expected Result: Your amount is more than your acount balance\n");
    else
        printf("Expected Result: Server is OK\n");
    if(error == SERVER_OK)
        printf("Actual Result: Server is OK\n\n\n\n");
    else
        printf("Actual Result:  amount is more than the max amount \n\n\n\n");

    counter++;
}
*/
#include <time.h>
int main()
{

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    /*time_t dt;
    time(&dt);
    enum months {Jan=1 , Feb , Mar , Apr , May , Jun , Jul , Aug , Sep , Oct , Nov , Dec };
    uint8_t month_string[12][3] = { "Jan" , "Feb" , "Mar" , "Apr" ,"May" , "Jun" ,"Jul" , "Aug" , "Sep" ,"Oct" , "Nov" , "Dec" };
    printf("System's current date\n");
    printf("%c%c%c\n", ctime(&dt)[4] , ctime(&dt)[5] , ctime(&dt)[6]);
    printf("%c%c%c%c\n", ctime(&dt)[20], ctime(&dt)[21], ctime(&dt)[22], ctime(&dt)[23]);
    printf("%s\n", ctime(&dt));
    printf("%d\n", Dec);
    */
	/*for (char i = 0; i < 20; i++)
	{
        isAmountAvailableTest();
		//getCardExpiryDateTest();
	}*/
	return 0;
}