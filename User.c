/*
 * File        : User.c
 * Description : This file includes Function of User menu List
 * Author      : Abdelrahman Mohamed Abdelsatar
 * Date        : 27/12/2022
 * Git account : https://github.com/Abdelrahman025
 * mail        : abdomohamed0135@gmail.com
 */

#include "User.h"

#include <stdio.h>

#include "Std_Types.h"
/*
 * Prototype   : Search_User(user_acount *head_ref, uint32 ID);
 * Description : To Search In Data Of User account what user_account i want to make (Transaction & change_account_status & Get_cash & Deposit) 
 * Arguments   : head : The first Address of My data to go search in list on what user_account i want 
 *               ID   : the Account ID that i want to open it 
 * return      : No return
 */
void Search_User(user_acount *head_ref, uint32 ID) {
    user_acount *curr = head_ref;
    uint32 pass_user;
    uint16 sw;
    uint16 lo = 1;
    while (curr != NULL) {
        if (curr->Bank_ACC_ID == ID) {
            printf("Please Enter your Password ");
            scanf("%lu", &pass_user);
            if (pass_user == curr->Pass) {
                while (lo) {
                    printf("\n\n        Name is %s \n", curr->Name);
                    printf("        Your ID is %s \n\n", curr->ID);
                    printf("\nPlease Choese What Operation You Want\n");
                    printf("1-Make Transaction\n");
                    printf("2-Change Account Password\n");
                    printf("3-Get Cash\n");
                    printf("4-Deposit in Account\n");
                    printf("5-Return to main Menu\n");
                    scanf("%hu", &sw);
                    switch (sw) {
                        case 1:
                            Make_Transaction_user(curr, head_ref);
                            break;
                        case 2:
                            Change_Account_Password_user(curr);
                            break;
                        case 3:
                            Get_Cash_user(curr);
                            break;
                        case 4:
                            Deposit_in_Account_user(curr);
                            break;
                        case 5:
                            lo = 0;
                            break;
                    }
                }
            } else {
                printf("wrong Password \n");
            }
        }
        if (lo == 0) {
            break;
        }
        curr = curr->Next;
    }
    if (lo == 1) {
        printf("\nNo User Account ID Found\n\n");
    }
}
/*
 * Prototype   : void Make_Transaction_user(user_acount *curr, user_acount*head); 
 * Description : That Function responsible for The Transaction Between Two Accunt The Current Account and The Account That I Want to Make Transaction With 
 * Arguments   : Curr : The current User 
 *               Head : The first Address To Search on The List with the account id that i want to transfer money to him 
 * return : No return
 */
void Make_Transaction_user(user_acount *curr, user_acount *head) {
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
                        printf("---------     Your Balance Now is %lu \n\n\n",curr->Balance);
                        // printf(
                        //     "---------     The Balance Of Account you send "
                        //     "Money Now is %lu \n\n\n",
                        //     Tran->Balance);
                    } else {
                        printf("\nThe Transaction is Falled Please Checke Your Money \n");
                        break;
                    }
                    break;
                } else {
                    printf("*****   The Account_Status is '%c' make sure The Account you want to send the money is 'A'ctive   *****\n",Tran->Account_Status);
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
 * Prototype   : void Change_Account_Password_user ;
 * Description : That function make me change My Password Account
 * Arguments   : Curr : The current user my account that i want to change Password 
 * return      : No return
 */
void Change_Account_Password_user(user_acount *curr) {
    uint32 pass;
    // uint32 new_pass;
    uint8 x = 3;
    while (x--) {
        printf("\nPlease Enter Your Current Password ");
        scanf("%lu", &pass);
        if (curr->Pass == pass) {
            printf("Please Enter Your New Password ");
            scanf_s("%lu", &curr->Pass);
            // curr->Pass = new_pass;
            printf("\n*****   Your New Password is %lu   *****\n\n",curr->Pass);
            break;
        } else {
            printf("\nYou enter worng Password you have %d try\n", x);
        }
    }
}
/*
 * Prototype   : void Get_Cash_user(user_acount *curr);
 * Description : That function make me Withdraw money from my account
 * Arguments   : Curr : the current user account that i want to Withdraw money
 * return      : No return
 */
void Get_Cash_user(user_acount *curr) {
    uint32 Cash;
    printf("\nPlease Enter Your Cash ");
    scanf("%lu", &Cash);
    if (curr->Balance > Cash) {
        curr->Balance = curr->Balance - Cash;
        printf("       ---------------------------------------\n");
        printf("-------    Your Cash After operation %lu    --------\n",curr->Balance);
        printf("       ---------------------------------------\n\n");
    } else {
        printf("Cant Complete Please Cheak Your Money");
    }
}
/*
 * Prototype   : void Deposit_in_Account_user(user_acount *curr);
 * Description : That function make me Deposit on my account and increment My Balance of money 
 * Arguments   : Curr : the current user account that i want to Deposit 
 * return      : No return
 */
void Deposit_in_Account_user(user_acount *curr) {
    uint32 Dep;
    printf("\nPlease Enter Your Deposit ");
    scanf("%lu", &Dep);
    curr->Balance = curr->Balance + Dep;
    printf("   ---------------------------------------\n");
    printf("-------    Your Cash After Deposit %lu    -------\n",curr->Balance);
    printf("   ---------------------------------------\n");
}