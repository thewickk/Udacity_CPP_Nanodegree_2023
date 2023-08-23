#include <iostream>
#include "../inc/bank_account.h"

int main()
{
    BankAccount account1;
    account1.AccountOwner("Chad Lewis");
    account1.AccountNumber(1234567);
    account1.FundsAvailable(75.70);

    std::cout << account1.AccountOwner() << " " << account1.AccountNumber() << " " << account1.FundsAvailable() << std::endl;
}