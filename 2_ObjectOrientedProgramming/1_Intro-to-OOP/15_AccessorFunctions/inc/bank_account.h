#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

class BankAccount
{
    public:
        // Accessors
        std::string AccountOwner() const;
        int AccountNumber() const;
        double FundsAvailable() const;

        // Mutators
        void AccountOwner(std::string name);
        int AccountNumber(int accnt_num);
        double FundsAvailable(double funds);

        
    private:
        std::string account_owner;
        int account_number;
        double funds_available;
};

#endif // BANK_ACCOUNT_H