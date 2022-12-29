/*
 * File        : Bank.h
 * Description : This file includes The Template of The Basic Data That i will Pass Each Time i create a new user(Node)
 * Author      : Abdelrahman Mohamed Abdelsatar
 * Date        : 27/12/2022
 * Git account : https://github.com/Abdelrahman025
 * mail        : abdomohamed0135@gmail.com
 */

#ifndef BANK_H_
#define BANK_H_
#include "Std_Types.h"
typedef struct User_Acount {
    uint8 Name[50];
    uint8 ID[20];
    uint8 Address[50];
    uint16 age;
    uint8 Guardian_ID[20];
    uint32 Balance;
    uint8 Account_Status;
    uint32 Bank_ACC_ID;
    uint32 Pass;

    struct User_Acount *Next;

} user_acount;

#endif