/*
 * File        : Admin.h
 * Description : This file includes The Declearation of function of Admin Menu List
 * Author      : Abdelrahman Mohamed Abdelsatar
 * Date        : 27/12/2022
 * Git account : https://github.com/Abdelrahman025
 * mail        : abdomohamed0135@gmail.com
 */


#ifndef ADMIN_H_
#define ADMIN_H_
#include "Bank.h"
#include "Std_Types.h"


/*
 * Prototype   : void Creat_Acount(user_acount **head_ref);
 * Description : Greate New User (Node) And Append It to List To Make Linked list 
 * Arguments   : Head : takes The first /Start of the list (Head) to Know the end of list to append New one in the end 
 * return      : No return
 */
void Creat_Acount(user_acount **head_ref);

/*
 * Prototype   : void Data(user_acount *temp);
 * Description : The Data that will be Entered Each Time Create New User (Node)
 * Arguments   : temp : The New User (Node) That created to Enter Data
 * return      : No return
 */
void Data(user_acount *temp);
/*
 * Prototype   : void PrintN(user_acount *Nod);
 * Description : To Print The User_Bank_ID  and The User_Password
 * Arguments   : Nod : The New User (Node) That created to Print The User_Bank_ID  and The User_Password 
 * return      : No return
 */
void PrintN(user_acount *Nod);
/*
 * Prototype   : Search_Admin_User(user_acount *head_ref, uint32 ID);
 * Description : To Search In Data Of User account what user_account i want to make (Transaction & change_account_status & Get_cash & Deposit) 
 * Arguments   : head : The first Address of My data to go search in list on what user_account i want 
 *               ID   : the User Account ID that i want to open it 
 * return      : No return
 */
void Search_Admin_User(user_acount *head_ref, uint32 ID);
/*
 * Prototype   : void Make_Transaction(user_acount *curr, user_acount *head);
 * Description : That Function responsible for The Transaction Between Two Accunt The Current Account and The Account That I Want to Make Transaction With
 * Arguments   : Curr : The current User 
 *               Head : The first Address To Search on The List with the account id that i want to transfer money to him return
 * : No return
 */
void Make_Transaction(user_acount *curr, user_acount *head);
/*
 * Prototype   : void Change_Account_Status(user_acount *curr) ;
 * Description : the function that i can change the Account status to ("Active","Closed","Restricted") 
 * Arguments   : Curr : The current user that i want to change account status 
 * return      : No return
 */
void Change_Account_Status(user_acount *curr);
/*
 * Prototype   : void Get_Cash(user_acount *curr);
 * Description : That function make me Withdraw money from my account
 * Arguments   : Curr : the current user account that i want to Withdraw money
 * return      : No return
 */
void Get_Cash(user_acount *curr);
/*
 * Prototype   : void Deposit_in_Account(user_acount *curr);
 * Description : That function make me Deposit on my account and increment My Balance of money 
 * Arguments   : Curr : the current user account that i want to Deposit 
 * return      : No return
 */
void Deposit_in_Account(user_acount *curr);
#endif