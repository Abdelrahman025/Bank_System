/*
 * File        : Main.c
 * Description : This file includes The Interface Of User And Admin
 * Author      : Abdelrahman Mohamed Abdelsatar
 * Date        : 27/12/2022
 * Git account : https://github.com/Abdelrahman025
 * mail        : abdomohamed0135@gmail.com
 */

#include <stdio.h>

#include "Admin.h"
#include "Std_Types.h"
#include "User.h"

uint16 AU;
uint8 flag = 1;
uint8 flag_Admin = 1;
int main() {
    user_acount *Head = NULL;
    while (flag) {
        printf("1-Admin\n2-User\n3-Exit Program\n");
        scanf("%hu", &AU);
        flag_Admin = 1;
        if (AU == 1) {
            while (flag_Admin) {
                uint16 ch;
                uint32 ID;
                printf("1-Create New Account\n");
                printf("2-Open Existing Account\n");
                printf("3-Exit System\n");
                scanf("%hu", &ch);
                switch (ch) {
                    case 1:
                        Creat_Acount(&Head);
                        break;
                    case 2:
                        printf("Please Enter Your Account ID ");
                        scanf("%lu", &ID);
                        Search_Admin_User(Head, ID);
                        break;
                    case 3:
                        flag_Admin = 0;
                        break;
                }
            }
        } else if (AU == 2) {
            uint32 ID_User;
            printf("Please Enter Your Account ID ");
            scanf("%lu", &ID_User);
            Search_User(Head, ID_User);
        } else {
            flag = 0;
        }
    }

    return 0;
}