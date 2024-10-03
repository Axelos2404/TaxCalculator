#include <iostream>
#include <string>
#include "progressbar.hpp"
#include <Windows.h>
using namespace std;

int main()
{
    constexpr float personalAllowance = 12570.0;
    float homeTake = 0.0;
    float PAYE = 0.0;
    float grossPay = 0.0;
    float taxableIncome = 0;
    float nationalInsurance = 0.0;
    
    cout << "Please enter your yearly Gross Pay( Salary before tax ): ";
    cin >> grossPay;
    taxableIncome = grossPay - personalAllowance;
    if (grossPay < 12571)
    {
        PAYE = taxableIncome * 0;
        nationalInsurance = taxableIncome * 0;
    }
    else if (grossPay < 50271)
    {
        PAYE = taxableIncome * 0.2f;
        nationalInsurance = taxableIncome * 0.08f;
    }
    else if (grossPay < 125141)
    {
        PAYE = taxableIncome * 0.4f;
        nationalInsurance = taxableIncome * 0.02f;
    }
    else
    {
        PAYE = taxableIncome * 0.45f;
        nationalInsurance = taxableIncome * 0.02f;
    }
    progressbar bar(100);
    for (int i = 0; i < 100; ++i) {
        Sleep(10);
        bar.update();
        // ... the program
    }
    cout << "\n";
    homeTake = grossPay - (PAYE + nationalInsurance);
    cout << "Your Taxable Income(yearly) is " << taxableIncome << "\n";
    cout << "Your Tax BREAKDOWN(yearly) is " << PAYE << "\n";
    cout << "Your National Insurance(yearly) is " << nationalInsurance << "\n";
    cout << "Your 2024 Take Home(yearly) is " << homeTake << "\n";
    return 0;
}



