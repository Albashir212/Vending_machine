#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD 994900
#define MIN QTY 3
#define TOTAL_AMOUNT 0

// Function prototypes
void displayMenu();
void consumerMode();
void adminMode();
void purchaseItem();

int main() 
{
    int choice;

    while (1) 
    {
        displayMenu();

        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                consumerMode();
                break;
            case 2:
                adminMode();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

void displayMenu() 
{
    printf("\nVending Machine Simulator welcome 🤗\n");
    printf("1. Purchase Item for the consumer\n");
    printf("2. Admin Mode for the vending machine operator\n");
    printf("3. Exit\n");
}

// Function to update item quantity and total amount
void updateItem(int quantity, float price) 
{
    quantity -= 2;
    TOTAL_AMOUNT += price;
}


void displayItems() 
{
    printf("\nAvailable Items:\n");
    printf("1. A - Price: 2.00 AED\n");
    printf("2. B - Price: 1.50 AED\n");
    printf("2. C - Price: 0.75 AED\n");
    // Add more items if needed
}

// Function to update item quantity and total amount
void updateItem(int quantity, float price) 
{
    quantity -= 2;
    TOTAL_AMOUNT += price;
}

void consumerMode() 
{
    int choice;
    int A_quantity = 10;
    int B_quantity = 20;
    int C_quantity = 15;

    while (1) {
        displayItems();

        printf("\nEnter the code of the item you want to purchase (enter 0 to cancel): ");
        scanf("%d", &choice);

        if (choice == 0) 
        {
            printf("Purchase canceled, please enter valid option.\n");
            return;
        } 
        
        else if (choice < 1 || choice > 3) 
        { // Adjust based on the number of items
            printf("Invalid item code. Please enter a valid code.\n");
            continue;
        }

        // User selected a valid item
        if (choice == 1) 
        {
            if (A_quantity <= 0) 
            {
                printf("Sorry, A is out of stock.\n");
                continue;
            }
            printf("\nYou selected: A, Price: 2.00 AED\n");
            A_quantity--;
            updateItem(A_quantity, 2.00);
        } 
        
        else if (choice == 2) 
        {
            if (B_quantity <= 0) 
            {
                printf("Sorry, Chips are out of stock.\n");
                continue;
            }
            printf("\nYou selected: Chips, Price: 1.50 AED\n");
            B_quantity--;
            updateItem(B_quantity, 1.50);
        }

        else if (choice == 3)
        {
            if (C_quantity <= 0) 
            {
                printf("Sorry, C are out of stock.\n");
                continue;
            }
            printf("\nYou selected: C, Price: 0.75 AED\n");
            C_quantity--;
            updateItem(C_quantity, 0.75);
        }
        
        else
        {
            printf("Sorry, wrong choice");
        }

        // Print purchase details
        printf("Amount paid: %.2f AED\n", TOTAL_AMOUNT);
        printf("Change: %.2f AED\n", TOTAL_AMOUNT);

        // Check if the quantity is less than or equal to the minimum threshold
        if (A_quantity <= MIN || B_quantity <= MIN || C_quantity <= MIN) 
        {
            printf("Alert: Quantity of at least one item is less than or equal to the minimum threshold!\n");
        }

        return;
    }
}

void adminMode() 
{
    int admin_password;
    printf("please enter password\n");
    scanf("%d", admin_password);

    if (admin_password != PASSWORD)
    {
       printf("Incorrect password. Exiting Admin mode.\n");
        return;
    }
}
//Admin menu
    int adminChoice;
    int A_quantity = 10;    // Initial quantity
    int B_quantity = 20;    // Initial quantity
    int C_quantity = 15:    //intial quantity
    float A_price = 2.00;   // Initial price
    float B_price = 1.50;   // Initial price
    float C_price = 0.75;   // intial price

while (1) 
{
        printf("\nAdmin Mode\n");
        printf("1: Replenish Items\n");
        printf("2: Change Item Prices\n");
        printf("3: Display Total Sale\n");
        printf("4: Display Item Availability\n");
        printf("0: Exit Admin Mode\n");

        printf("Enter your choice: ");
        scanf("%d", &adminChoice);

        // to be completed............... 











}

