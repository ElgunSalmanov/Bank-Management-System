#include <iostream>
using namespace std;

// Class Bank
class BankAccount {
private:
  int balance;

public:
  // Contructor
  BankAccount() { balance = 0; }

  // Take the money method
  int takeTheMoney(int redisue) {
    if (balance < 0 || redisue > balance) {
      cout << "Insufficient funds for withdrawal" << endl;
      return balance;
    }

    balance -= redisue;
    return balance;
  }

  // Load money method
  int loadMoney(int redisue) {
    balance += redisue;
    return balance;
  }

  // Show balance method
  void showBalance() { cout << "Account balance: " << balance << endl; }

  // Transfer other Bank Account method
  void doTransfer(BankAccount &second_balance, int redisue) {
    if (second_balance.balance < 0) {
      cout << "In order to transfer, there must be a debt in second account"
           << endl;
      return;
    }

    balance -= redisue;
    second_balance.balance += redisue;
    cout << "\nTransferred " << redisue << " to the other account!" << endl;
  }
};

int main() {
  BankAccount account;
  BankAccount second_account;

  while (true) {
    int choice;

    cout << "1) Take the money" << endl;
    cout << "2) Load money" << endl;
    cout << "3) Transfer" << endl;
    cout << "4) Show balance" << endl;
    cout << "5) Exit program" << endl;
    cout << "\nEnter choice: ";
    cin >> choice;

    if (cin.fail()) {
      cout << "\nInvalid input detected. Exiting the program";
      break;
    }

    switch (choice) {
    case 1: {
      int amount;
      cout << "Enter the amount to be withdrawn: ";
      cin >> amount;
      cout << "\n";
      account.takeTheMoney(amount);
      break;
    }

    case 2: {
      int amount;
      cout << "Enter the amount to be loaded: ";
      cin >> amount;
      cout << "\n";
      account.loadMoney(amount);
      break;
    }

    case 3: {
      int amount;
      cout << "Enter the amount to be transfer: ";
      cin >> amount;
      account.doTransfer(second_account, amount);
      cout << "It was transferred from the current account to another account!"
           << endl;
      cout << "\n";
      account.showBalance();
      second_account.showBalance();
      cout << "\n";
      break;
    }

    case 4: {
      account.showBalance();
      cout << "\n";
      break;
    }

    case 5:
      cout << "\nGood bye, come again :)";
      return EXIT_SUCCESS;

    default:
      cout << "Invalid choice, try again please!\n" << endl;
    }
  }
}
