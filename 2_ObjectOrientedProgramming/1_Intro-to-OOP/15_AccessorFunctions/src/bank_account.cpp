#include "../inc/bank_account.h"

// Accessors
std::string BankAccount::AccountOwner() const { return account_owner; }
int BankAccount::AccountNumber() const { return account_number; }
double BankAccount::FundsAvailable() const { return funds_available; }

// Mutators
void BankAccount::AccountOwner(std::string name)
{
    account_owner = name;
}

int BankAccount::AccountNumber(int accnt_num)
{
    account_number = accnt_num;
}

double BankAccount::FundsAvailable(double funds)
{
    funds_available = funds;
}