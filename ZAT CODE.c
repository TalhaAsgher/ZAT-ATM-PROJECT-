#include <stdio.h>
#include <string.h>
char name[50] ;
char cardtype[20];
int balance=0;
int correct_pin = 0;
int withdraw_limit = 0;
void printReceipt(char transactionType[]);
int pinVerification();
void deposit();
void withdraw();
void balanceInquiry();
void fast_cash();
int changePin(int correct_pin);
void payBill();


int pinVerification() {
    int pin;
    int attempts = 0;

    while (attempts < 3) {
        printf("ENTER YOUR PIN: ");
        scanf("%d", &pin);

        if (pin == correct_pin) {
            printf("LOGIN SUCCESSFUL...!\n");
            return 1;
        } else {
            printf("WRONG PASSWORD. TRY AGAIN....!\n");
            attempts++;
        }
    }

    printf("ATM IS BLOCKED. TRY AGAIN LATER....!\n");
    return 0;
}

void deposit() {
    int deposit_amount;
    printf("PLEASE ENTER THE AMOUNT YOU WANT TO DEPOSIT: ");
    scanf("%d", &deposit_amount);
    if (deposit_amount <= 0) {
        printf("INVALID AMOUNT.\n");
        return;
    }
    balance += deposit_amount;
    printf("DEPOSIT SUCCESSFUL...!\n");
    printf("UPDATED BALANCE: Rs. %d\n", balance);
}

void withdraw() {
    int amount;
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);

    if (amount <= 0) {
        printf("INVALID AMOUNT.\n");
    } else if (amount > balance) {
        printf("NOT ENOUGH BALANCE.\n");
    } else if (amount > withdraw_limit) {
        printf("AMOUNT EXCEEDS YOUR CARD LIMIT.\n");
    } else {
        balance = balance-amount;
        printf("Rs. %d withdrawn successfully!\n", amount);
        printReceipt("Withdrawal");
    }
}

void balanceInquiry() {
    printf("\nYour current balance is: Rs. %d\n", balance);
    printReceipt("Balance Inquiry");
}
void fast_cash() {
    int select;
    int amount = 0;

    printf("1. 10000\n");
    printf("2. 20000\n");
    printf("3. 50000\n");
    printf("4. 100000\n");

    printf("Select your withdrawal: ");
    scanf("%d", &select);

    switch (select) {
        case 1:
            amount = 10000;
            break;
        case 2:
            amount = 20000;
            break;
        case 3:
            amount = 50000;
            break;
        case 4:
            amount = 100000;
            break;
        default:
            printf("Invalid Option.\n");
            return;
    }

    if (amount > balance) {
        printf("NOT ENOUGH BALANCE.\n");
    } else if (amount > withdraw_limit) {
        printf("AMOUNT EXCEEDS YOUR CARD LIMIT.\n");
    } else {
        balance = balance - amount;
        printf("Rs.%d withdrawn successfully.\n", amount);
        printReceipt("Fast Cash");
    }
}

void printReceipt(char transactionType[]) {
    printf("\n--- Transaction Receipt ---\n");
    printf("Transaction Type : %s\n", transactionType);
    printf("Account Name     : %s\n", name);
    printf("Card Type        : %s\n", cardtype);
    printf("Current Balance  : Rs. %d\n", balance);
    printf("Thanks for using ZAT Bank!\n");
    printf("---------------------------\n\n");
}
int changePin(int correct_pin)
{
    int oldPin, newPin, confirmPin;

    printf("Enter current PIN: ");
    scanf("%d", &oldPin);

    if (oldPin == correct_pin)
    {
        printf("Enter new PIN: ");
        scanf("%d", &newPin);
        printf("Confirm new PIN: ");
        scanf("%d", &confirmPin);

        if (newPin == confirmPin)
        {
            correct_pin = newPin;
            printf("PIN changed successfully.\n");
        }
        else
        {
            printf("Confirm PIN does not match.\n");
        }
    }
    else
    {
        printf("Incorrect current PIN.\n");
    }

    return correct_pin;
}

void payBill() {
    int choice;
    int amount;
    int connum;

    printf("\n--- Bill Payment Menu ---\n");
    printf("1. Electricity Bill\n");
    printf("2. Gas Bill\n");
    printf("3. Water Bill\n");
    printf("Select your Bill: ");
    scanf("%d", &choice);

    printf("\nEnter your consumer number (Last 6 digits): ");
    scanf("%d", &connum);

    printf("\nEnter your Bill amount: ");
    scanf("%d", &amount);

    if (amount > balance) {
        printf("\nNot enough balance to pay the bill!\n");
        return; 
    }


    balance = balance - amount;

    switch (choice) {
        case 1:
            printf("Your Electricity Bill of ID %d has been paid...\n", connum);
            printReceipt("Electricity Bill");
            break;
        case 2:
            printf("Your Gas Bill of ID %d has been paid...\n", connum);
            printReceipt("Gas Bill");
            break;
        case 3:
            printf("Your Water Bill of ID %d has been paid...\n", connum);
            printReceipt("Water Bill");
            break;
        default:
            printf("Invalid Option.\n");
    }
}

int main() {
    int card_number;

    printf("\t\t============ ZAT ATM ============\n");
    printf("\t=========== Welcome to our ATM service ===========\n");
    printf("Enter your card number : ");
    scanf("%d", &card_number);
    if (card_number == 7095) {
        strcpy(cardtype, "Gold");
        strcpy(name,"ZERAK");
        balance = 150000;
        correct_pin = 1234;
        withdraw_limit = 100000;
    } else if (card_number == 7500) {
        strcpy(cardtype, "Platinum");
           strcpy(name,"TALHA");
           balance = 200000;
        correct_pin = 1111;
        withdraw_limit = 200000;
    } else {
        printf("Invalid card number.\nExiting...\n");
        return 0;
    }
    if (!pinVerification()) {
        return 0;
    }
    int choice;
    char continue_t;

    do {
        printf("\nWelcome Mr.%s\n",name);
        printf("Card Type: %s\n", cardtype);
        printf("Select an Option:\n");
        printf("1. CHECK BALANCE\t");
        printf("2. WITHDRAW MONEY\n");
        printf("3. FAST CASH\t");
        printf("\t4. DEPOSIT MONEY\n");
        printf("5.Change PIN\t");
        printf("\t6.BILL PAYMENT\n");
        printf("7.EXIT\n");
        printf("======================================\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                balanceInquiry();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                fast_cash();
                break;
            case 4:
                 deposit();
                  break;
            case 5:
                changePin(correct_pin);
                break;
                case 6:
                   payBill( balance);
                   break;
                case 7:
                   printf("THANK YOU FOR USING ZAT ATM....\n");
                   printf("@Developed By Codex");
                return 0;
            default:
                printf("INVALID OPTION. CHOOSE FROM (1-7)\n");
        }

        printf("DO YOU WANT ANY OTHER TRANSACTION (Y/N): ");
        scanf(" %c", &continue_t); 

    } while (continue_t == 'y' || continue_t == 'Y');
     printf("Thanks for using ZAT Bank!\n");
     printf("@Developed By Codex\n");
    printf("---------------------------\n\n");
    
    return 0;
}
