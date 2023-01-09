/*
 * File        : Admin.c
 * Description : This file includes Function of Admin menu List
 * Author      : Abdelrahman Mohamed Abdelsatar
 * Date        : 27/12/2022
 * Git account : https://github.com/Abdelrahman025
 * mail        : abdomohamed0135@gmail.com
 */

#include "Admin.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * Prototype   : void Creat_Acount(user_acount **head_ref);
 * Description : Greate New User (Node) And Append It to List To Make Linked list 
 * Arguments   : Head : takes The first /Start of the list (Head) to Know the end of list to append New one in the end 
 * return      : No return
 */

void Creat_Acount(user_acount **head_ref) {
    user_acount *new = (user_acount *)malloc(sizeof(user_acount));
    if (new != NULL) {
        Data(new);
        user_acount *current = *head_ref;
        if (*head_ref == NULL) {
            *head_ref = new;
        } else {
            while (current->Next != NULL) {
                current = current->Next;
            }
            current->Next = new;
        }
    } else {
        printf("Heap is Full");
    }
}


/*
 * Prototype   : void Data(user_acount *temp);
 * Description : The Data that will be Entered Each Time Create New User (Node)
 * Arguments   : temp : The New User (Node) That created to Enter Data
 * return      : No return
 */

void Data(user_acount *temp) {
    uint8 x = 0;
    srand(time(NULL));
    while (x < 3) {
        printf("Please Enter Full Name It must be quadruple ");
        scanf(" %[^\n]", temp->Name);
        for (uint8 i = 0; temp->Name[i] != '\0'; i++) {
            if (temp->Name[i] == ' ') {
                x++;
            }
        }
    }
    printf("Please Enter Address ");
    scanf(" %[^\n]", temp->Address);
    while (strlen(temp->ID) < 14) {
        printf("Please Enter ID It Should be 14 Digits ");
        scanf("%s", temp->ID);
    }
    printf("Please Enter age ");
    scanf("%hu", &temp->age);
    if (temp->age < 21) {
        while (strlen(temp->Guardian_ID) < 14) {
            printf("Please Enter Guardian_ID It Should be 14 Digits ");
            scanf("%s", temp->Guardian_ID);
        }
    }
    temp->Account_Status = 'A';
    temp->Balance = 75000;
    temp->Bank_ACC_ID = rand() + 10000000000;
    temp->Pass = rand() + 10000;
    temp->Next = NULL;
    PrintN(temp);
}

/*
 * Prototype   : void PrintN(user_acount *Nod);
 * Description : To Print The User_Bank_ID  and The User_Password
 * Arguments   : Nod : The New User (Node) That created to Print The User_Bank_ID  and The User_Password 
 * return      : No return
 */
void PrintN(user_acount *Nod) {
    printf("\n\n********************************************************\n");
    printf("********         user_Bank_ID = %lu      ********\n",Nod->Bank_ACC_ID);
    printf("********         user_Pass    = %lu           ********\n",Nod->Pass);
    printf("********************************************************\n\n\n");
}



/*
 * Prototype   : Search_Admin_User(user_acount *head_ref, uint32 ID);
 * Description : To Search In Data Of User account what user_account i want to make (Transaction & change_account_status & Get_cash & Deposit) 
 * Arguments   : head : The first Address of My data to go search in list on what user_account i want 
 *               ID   : the User Account ID that i want to open it 
 * return      : No return
 */
void Search_Admin_User(user_acount *head_ref, uint32 ID) {
    user_acount *curr = head_ref;
    uint16 sw;
    uint16 lo = 1;
    while (curr != NULL) {
        if (curr->Bank_ACC_ID == ID) {
            while (lo) {
                printf("\n\n        Name is %s \n", curr->Name);
                printf("        Your ID is %s \n\n", curr->ID);
                printf("\nPlease Choese What Operation You Want\n");
                printf("1-Make Transaction\n");
                printf("2-Change Account Status\n");
                printf("3-Get Cash\n");
                printf("4-Deposit in Account\n");
                printf("5-Return to main Menu\n");
                scanf("%hu", &sw);
                switch (sw) {
                    case 1:
                        Make_Transaction(curr, head_ref);
                        break;
                    case 2:
                        Change_Account_Status(curr);
                        break;
                    case 3:
                        Get_Cash(curr);
                        break;
                    case 4:
                        Deposit_in_Account(curr);
                        break;
                    case 5:
                        lo = 0;
                        break;
                }
            }
        } else {
            printf("No User Account ID Found");
        }
        if (lo == 0) {
            break;
        }
        curr = curr->Next;
    }
}

/*
 * Prototype   : void Make_Transaction(user_acount *curr, user_acount *head);
 * Description : That Function responsible for The Transaction Between Two Accunt The Current Account and The Account That I Want to Make Transaction With
 * Arguments   : Curr : The current User 
 *               Head : The first Address To Search on The List with the account id that i want to transfer money to him return
 * : No return
 */
void Make_Transaction(user_acount *curr, user_acount *head) {
    user_acount *Tran = head;
    uint32 ID_Transaction;
    uint32 Money_Trans;
    if (curr->Account_Status == 'A') {
        printf("\nPlease Enter Bank Account ID It Must Be 10 Digits ");
        scanf("%lu", &ID_Transaction);
        while (Tran != NULL) {
            if (Tran->Bank_ACC_ID == ID_Transaction) {
                if (Tran->Account_Status == 'A') {
                    printf("\nPlease enter amount of money to transfer it to the this account ");
                    scanf("%lu", &Money_Trans);
                    if (curr->Balance > Money_Trans) {
                        curr->Balance = curr->Balance - Money_Trans;
                        Tran->Balance = Tran->Balance + Money_Trans;
                        printf("\n\n---------          The Transaction Is done         --------- \n");
                        printf("---------     The Transaction Money is %lu \n",Money_Trans);
                        printf("---------     Your Balance Now is %lu \n",curr->Balance);
                        printf("---------     The Balance Of Account you send Money Now is %lu \n\n\n",Tran->Balance);
                    } else {
                        printf("\nThe Transaction is Falled Please Checke Your Money \n");
                        break;
                    }
                    break;
                } else {
                    printf("\n*****   The Account_Status is '%c' make sure The Account you want to send the money is 'A'ctive   *****\n",Tran->Account_Status);
                    break;
                }
            }
            Tran = Tran->Next;
        }
    } else {
        printf("\n\nThe Bank Account_Status Is '%c' Please Make sure your Account Is 'A'ctive\n",curr->Account_Status);
    }
}


/*
 * Prototype   : void Change_Account_Status(user_acount *curr) ;
 * Description : the function that i can change the Account status to ("Active","Closed","Restricted") 
 * Arguments   : Curr : The current user that i want to change account status 
 * return      : No return
 */
void Change_Account_Status(user_acount *curr) {
    uint16 Status;
    printf("Please Chose What Account Status\n");
    printf("1-Set Account to Active State \n");
    printf("2-Set Account to Restricted State \n");
    printf("3-Set Account to Closed \n");
    scanf("%hu", &Status);
    switch (Status) {
        case 1:
            curr->Account_Status = 'A';
            printf("\n*****   Accunt Status is Active   *****\n");
            break;
        case 2:
            curr->Account_Status = 'R';
            printf("\n*****   Accunt Status is Restricted   *****\n");
            break;
        case 3:
            curr->Account_Status = 'C';
            printf("\n*****   Accunt Status is Closed  *****\n");
            break;
    }
}

/*
 * Prototype   : void Get_Cash(user_acount *curr);
 * Description : That function make me Withdraw money from my account
 * Arguments   : Curr : the current user account that i want to Withdraw money
 * return      : No return
 */
void Get_Cash(user_acount *curr) {
    uint32 Cash;
    printf("\nPlease Enter Your Cash ");
    scanf("%lu", &Cash);
    if (curr->Balance > Cash) {
         printf("\n       ---------------------------------------\n");
        printf("-------    Your Cash Before operation %lu    --------\n",curr->Balance);
        printf("       ---------------------------------------\n\n");
        curr->Balance = curr->Balance - Cash;
        printf("\n       ---------------------------------------\n");
        printf("-------    Your Cash After operation %lu    --------\n",curr->Balance);
        printf("       ---------------------------------------\n\n");
    } else {
        printf("Cant Complete Please Cheak Your Money");
    }
}


/*
 * Prototype   : void Deposit_in_Account(user_acount *curr);
 * Description : That function make me Deposit on my account and increment My Balance of money 
 * Arguments   : Curr : the current user account that i want to Deposit 
 * return      : No return
 */
void Deposit_in_Account(user_acount *curr) {
    uint32 Dep;
    printf("\nPlease Enter Your Deposit ");
    scanf("%lu", &Dep);
        printf("\n      ---------------------------------------\n");
    printf("-------    Your Cash Before Deposit %lu    -------\n",curr->Balance);
    printf("      ---------------------------------------\n");
    curr->Balance = curr->Balance + Dep;
    printf("\n      ---------------------------------------\n");
    printf("-------    Your Cash After Deposit %lu    -------\n",curr->Balance);
    printf("      ---------------------------------------\n");
}