/*
 * File        : User.h
 * Description : This file includes Declearation of Function of User menu List
 * Author      : Abdelrahman Mohamed Abdelsatar
 * Date        : 27/12/2022
 * Git account : https://github.com/Abdelrahman025
 * mail        : abdomohamed0135@gmail.com
 */


#ifndef USER_H_
#define USER_H_
#include "Bank.h"
/*
 * Prototype   : Search_User(user_acount *head_ref, uint32 ID);
 * Description : To Search In Data Of User account what user_account i want to make (Transaction & change_account_status & Get_cash & Deposit) 
 * Arguments   : head : The first Address of My data to go search in list on what user_account i want 
 *               ID   : the Account ID that i want to open it 
 * return      : No return
 */
void Search_User(user_acount *head_ref, uint32 ID);
/*
 * Prototype   : void Make_Transaction_user(user_acount *curr, user_acount *head);
 * Description : That Function responsible for The Transaction Between Two Accunt The Current Account and The Account That I Want to Make Transaction With
 * Arguments   : Curr : The current User 
 *               Head : The first Address To Search on The List with the account id that i want to transfer money to him return
 * : No return
 */
void Make_Transaction_user (user_acount *curr, user_acount *head);
/*
 * Prototype   : void Change_Account_Password_user ;
 * Description : That function make me change My Password Account
 * Arguments   : Curr : The current user my account that i want to change Password
 * return      : No return
 */
void Change_Account_Password_user(user_acount *curr);
/*
 * Prototype   : void Get_Cash_user(user_acount *curr);
 * Description : That function make me Withdraw money from my account
 * Arguments   : Curr : the current user account that i want to Withdraw money
 * return      : No return
 */
void Get_Cash_user(user_acount *curr);
/*
 * Prototype   : void Deposit_in_Account_user(user_acount *curr);
 * Description : That function make me Deposit on my account and increment My Balance of money 
 * Arguments   : Curr : the current user account that i want to Deposit 
 * return      : No return
 */
void Deposit_in_Account_user(user_acount *curr);

#endif
