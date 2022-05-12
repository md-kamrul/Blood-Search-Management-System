/*

    Project Name: Blood Search Management System

    Members:
        1. Md. Kamrul Islam 2211745642
        2. Md. Nazmul Islam Sihan 2211930042
        3. Md. Mubtasin Hasnat Shihab 2212374042

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define ENTER 13
#define BACKSPACE 8

long long int nid_log;

struct sign_up_data
{
    char full_name[30];
    long long int nid;
    char blood_group[5];
    long long int contact;
    char address[20];
    char password[20];
    char confirm_password[20];
};
typedef struct sign_up_data var;

// function prototype here
int welcoming_interface_function();
void searching_function(var data);
void sign_up_function();
void appointment_check_function();
int donate_blood_function(var data);
void event_function();
void about_function();
int log_in_function(var data);
void delay(int time);
int search_for_detect(char *file, long long int nid);
void loadingBar();

// main body here
int main()
{
    int choice;
    var data;

    printf("\n\n\n\t\t\tProject Name: Blood Search Management System\n\n\t\t\tTeam Members:");
    printf("\n\t\t\t\xDB\xB2 Md. Kamrul Islam 2211745642");
    printf("\n\n\t\t\t\xDB\xB2 Md. Nazmul Islam Sihan 2211930042");
    printf("\n\n\t\t\t\xDB\xB2 Md. Mubtasin Hasnat Shihab 2212374042");
    printf("\n\n\n\t\t\tLet's jump in to the project!!!\n\n\t\t\t");
    getch();

back:
    system("COLOR 07");
    choice = welcoming_interface_function(); // home interface

    // entering the options from here
    switch (choice)
    {
    case 1:
        searching_function(data); // search blood in the nearest area
        goto back;
    case 2:
        sign_up_function(); // sign up for new members
        goto back;
    case 3:
        appointment_check_function(data); // appointment to check blood group
        goto back;
    case 4:
        donate_blood_function(data); // appointment to donate blood
        goto back;
    case 5:
        event_function(); // announcement about upcoming event
        goto back;
    case 6:
        about_function(); // who we are
        goto back;
    case 7:
        exit(0);
    default:
        printf("\n\n\t\t\tWRONG!!!\n\t\t\tPlease enter the correct option");
        getch();
        goto back;
    }

    getch();
    return 0;
}


//****************************************************************************************************************************************************************************************************


// home interface
int welcoming_interface_function()
{
    int choice;

    system("cls");

    printf("\n\n\n\t\t\tWelcome to Blood Search Management System\n\n\t\t\t");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\t\xDB\xDB\xDB\xDB\xB2 1. Searching");
    printf("\n\n\t\t\t\xDB\xDB\xDB\xDB\xB2 2. Sign Up");
    printf("\n\n\t\t\t\xDB\xDB\xDB\xDB\xB2 3. Appointment to check blood group");
    printf("\n\n\t\t\t\xDB\xDB\xDB\xDB\xB2 4. Donate blood");
    printf("\n\n\t\t\t\xDB\xDB\xDB\xDB\xB2 5. Event");
    printf("\n\n\t\t\t\xDB\xDB\xDB\xDB\xB2 6. Who we are");
    printf("\n\n\t\t\t\xDB\xDB\xDB\xDB\xB2 7. Exit");
    printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n\n\t\t\tEnter your choice here: ");
    scanf("%d", &choice);
    return choice;
}


//****************************************************************************************************************************************************************************************************


// blood searching in the nearest area
void searching_function(var data)
{
    system("cls");
    char blood[5], area[30];
    long long int nid_check, contact;
    char password_check[20], name[30], blood_group[5], address[30];
    int count = 0;
    FILE *info;
    info = fopen("information.txt", "r");

    printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SEARCHING \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\tEnter blood group: ");
    scanf("%s", blood);
    printf("\n\t\tEnter location (Thana Only): ");
    scanf("%s", area);

    if (info == NULL)
    {
        system("COLOR 04");
        printf("\n\n\t\t\t\tError!!! Somethings went wrong. \n\n\t\t\t\tPress any key to go home....");
        getch();
    }
    else
    {
        loadingBar();
        system("cls");
        printf("\n\n\t");
        printf("\n\n\n\t\tName\t\tBlood Group\tContact\t\t\tAddress\n\n");
        while (fscanf(info, "%lld\t\t%s\t\t%s\t\t%lld\t%s\t%s", &nid_check, name, blood_group, &contact, address, password_check) != EOF)
        {
            if (strcmp(blood, blood_group) == 0 && strcmp(area, address) == 0)
            {
                printf("\t\t%s\t\t%s\t\t0%lld\t\t%s", name, blood_group, contact, address);
                printf("\n");
                count++;
            }
        }
        if(count == 0)
            printf("\n\n\n\t\t\tSorry! no donor found  :( ");
        printf("\n\n\n\n\t\tBe a donor by signing here.\n\t\tPress any key to go home.....");

        fclose(info);

        getch();
    }
}


//****************************************************************************************************************************************************************************************************


// sign up for new members
void sign_up_function()
{
    FILE *info;

    var data;
    long long nid_check;
    int count = 0;

    if (info == NULL)
    {
        system("COLOR 04");
        printf("\n\n\t\t\t\tError!!! Somethings went wrong. \n\n\t\t\t\tPress any key to go home....");
        getch();
    }
    else
    {
        fflush(stdin);
        system("cls");
        printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Sign Up \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\n\t\tEnter your id: ");
        scanf("%lld", &data.nid);
        info = fopen("information.txt", "r");
        while (fscanf(info, "%lld\t%*s\t%*s\t%*d\t%*s\t%*s\n", &nid_check) == 1)
        {
            if (nid_check == data.nid)
                count++;
        }
        fclose(info);

        info = fopen("information.txt", "a");
        if (count == 0)
        {
            fflush(stdin);
            fprintf(info, "%lld\t\t", data.nid);
            printf("\n\t\tEnter your full name: ");
            fgets(data.full_name, sizeof(data.full_name), stdin);
            data.full_name[strlen(data.full_name) - 1] = '\0';
            fprintf(info, "%s\t\t", data.full_name);
            printf("\n\t\tEnter your blood group: ");
            scanf("%s", data.blood_group);
            fprintf(info, "%s\t\t", data.blood_group);
            fflush(stdin);
            printf("\n\t\tEnter your contact number: ");
            scanf("%d", &data.contact);
            fprintf(info, "%d\t", data.contact);
            fflush(stdin);
            printf("\n\t\tEnter your address (Thana Only): ");
            scanf("%s", &data.address);
            fprintf(info, "%s\t", data.address);
        part_02:
            printf("\n\n\t\tEnter the password: ");
            for (int i = 0; i < 20; i++)
            {
            new_password_take:
                data.password[i] = getch();

                // to exit inputing password
                if (data.password[i] == ENTER)
                {
                    data.password[i] = '\0';
                    break;
                }

                // to deleting input
                else if (data.password[i] == BACKSPACE)
                {
                    printf("\b \b");
                    i--;
                    goto new_password_take;
                }

                printf("*");
            }

            fflush(stdin);
            printf("\n\n\t\tConfirm the password: ");
            for (int i = 0; i < 20; i++)
            {
            confirm_password:
                data.confirm_password[i] = getch();

                // to exit inputing password
                if (data.confirm_password[i] == ENTER)
                {
                    data.confirm_password[i] = '\0';
                    break;
                }

                // to deleting input
                else if (data.confirm_password[i] == BACKSPACE)
                {
                    printf("\b \b");
                    i--;
                    goto confirm_password;
                }

                printf("*");
            }

            if (strcmp(data.password, data.confirm_password) != 0)
            {
                system("COLOR 04");
                printf("\n\n\n\t\tPassword does not match!!! Press any key to go to input again.....");
                getch();
                system("cls");
                goto part_02;
            }
            else
            {
                fprintf(info, "%s\n", data.password);
                printf("\n\n\t\tIt is almost done. Please wait.....");
                delay(2);
                system("cls");
                system("COLOR 02");
                printf("\n\n\t\t\t\t\t\tCongratulations!!!\n\t\t\t\t\t\t******************\n\n\t\t\tYour account has successfully created. Press any key to go to home....");
                getch();
                system("cls");
            }

            fclose(info);
        }
        else
        {
            system("color 04");
            printf("You have already an account here. Press any key....");
            getch();
        }
    }
}


//****************************************************************************************************************************************************************************************************


// appointment to check blood group
void appointment_check_function()
{
    system("cls");

    int x, t, hospital, date_day, date_month, date_year;
    long long int phone, nid;
    char name[50];

    printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Appointment To Check Blood Group \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\tOur appointments for blood test are available everyday. Please choose your date according to your convenience.\n\tSelect date,month and year gradually.");
    printf("\n\n\tEnter date : ");
    scanf("%d", &date_day);
    printf("\n\tEnter month : ");
    scanf("%d", &date_month);
    printf("\n\tEnter year : ");
    scanf("%d", &date_year);
    fflush(stdin);
    printf("\n\tName: ");
    gets(name);
    printf("\n\tPhone number: ");
    scanf("%lld", &phone);
    printf("\n\tID no: ");
    scanf("%lld", &nid);
hospital:
    printf("\n\n\t\t\t\tOur Registered Hospitals:\n\t1.LABAID(DHANMONDI)\n\t2.SQUARE\n\t3.BIHS\n\t4.IBN SINA (DHANMONDI 9/A)\n\t5.IBN SINA(KALLAYANPUR)\n\t6.LABAID(MIRPUR-1)");
    printf("\n\n\tEnter the hospital number where you want to take appointment: ");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        printf("\n\tYou have selected LABAID(DHANMONDI)");
        break;
    case 2:
        printf("\n\tYou have selected SQUARE");
        break;
    case 3:
        printf("\n\tYou have selected BIHS");
        break;
    case 4:
        printf("\n\tYou have selected IBN SINA (DHANMONDI 9/A)");
        break;
    case 5:
        printf("\n\tYou have selected IBN SINA(KALLAYANPUR)");
        break;
    case 6:
        printf("\n\tYou have selected LABAID(MIRPUR-1)");
        break;
    default:
        printf("\n\tPlease enter the right input.Press any key.....");
        getch();
        goto hospital;
    }

    FILE *appointment;
    appointment = (fopen("appoint.txt", "a"));
    if (appointment == NULL)
    {
        system("COLOR 04");
        printf("\n\n\t\t\t\tError!!! Somethings went wrong. \n\n\t\t\t\tPress any key to go home....");
        getch();
    }
    else
    {
        fprintf(appointment, "\n\nName: %s\nNID: %lld\nPhone: %lld\nDate: %d/%d/%d", name, nid, phone, date_day, date_month, date_year);
        switch (x)
        {
        case 1:
            fprintf(appointment, "\nHospital: LABAID(DHANMONDI)");
            break;
        case 2:
            fprintf(appointment, "\nHospital: SQUARE");
            break;
        case 3:
            fprintf(appointment, "\nHospital: BIHS");
            break;
        case 4:
            fprintf(appointment, "\nHospital: IBN SINA (DHANMONDI 9/A)");
            break;
        case 5:
            fprintf(appointment, "\nHospital: IBN SINA(KALLAYANPUR)");
            break;
        case 6:
            fprintf(appointment, "\nHospital: LABAID(MIRPUR-1)");
            break;
        }
    time:
        printf("\n\n\t\t\tTime slots:\n\t1) 11:00am\n\t2) 02:00pm\n\t3) 05:00pm\n\t4) 07.00pm\n");
        printf("\tEnter your time slot no: ");
        scanf("%d", &t);
        switch (t)
        {
        case 1:
            fprintf(appointment, "\nTime: 11:00am");
            break;
        case 2:
            fprintf(appointment, "\nTime: 02:00pm");
            break;
        case 3:
            fprintf(appointment, "\nTime: 05:00pm");
            break;
        case 4:
            fprintf(appointment, "\nTime: 07.00pm");
            break;
        default:
            printf("\n\tPlease enter the right input.Press any key.....");
            getch();
            goto time;
        }
        fclose(appointment);

        loadingBar();
        system("cls");

        printf("\n\n\n\n\t\tThanks for taking an appointment. Please be present on time.\n\n\t\tPress any key to go to home....");

        getch();
    }
}



//****************************************************************************************************************************************************************************************************


// appointment to donate blood
int donate_blood_function(var data)
{
    int value = log_in_function(data);
    if (value == -1)
    {
        system("cls");
        int date_day, date_month, date_year, x, t, count_nid = -1, times = 0;
        long long int nid, nid_check, contact;
        char name[30], blood_group[5], address[30], password_check[20];

        printf("\n\n\t\t\t\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Appointment To Donate Blood \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\n\tOur blood donation campaigns are available everyday. Please choose your date according to your convenience.\n\tSelect date,month and year gradually.");
        printf("\n\n\tEnter date : ");
        scanf("%d", &date_day);
        printf("\n\tEnter month : ");
        scanf("%d", &date_month);
        printf("\n\tEnter year : ");
        scanf("%d", &date_year);
    hospital:
        printf("\n\n\t\t\t\tOur Registered Hospitals:\n\t1.LABAID(DHANMONDI)\n\t2.SQUARE\n\t3.BIHS\n\t4.IBN SINA (DHANMONDI 9/A)\n\t5.IBN SINA(KALLAYANPUR)\n\t6.LABAID(MIRPUR-1)");
        printf("\n\n\tEnter the hospital number where you want to take appointment: ");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            printf("\n\tPlease enter the right input.Press any key.....");
            getch();
            goto hospital;
        }
    nid:
        printf("\n\tEnter your NID no for varification: ");
        scanf("%lld", &nid);

        FILE *info;
        info = fopen("information.txt", "r");

        if (info == NULL)
        {
            system("COLOR 04");
            printf("\n\n\t\t\t\tError!!! Somethings went wrong. \n\n\t\t\t\tPress any key to go home....");
            getch();
        }
        else
        {
            while (fscanf(info, "%lld\t\t%s\t\t%s\t\t%lld\t%s\t%s", &nid_check, name, blood_group, &contact, address, password_check) != EOF)
            {
                if (nid_check == nid)
                {
                    count_nid = 0;
                    break;
                }
            }
            if (nid_check != nid_log)
            {
                system("COLOR 04");
                printf("\n\n\t\t\tWarning!!! You have entered wrong NID no.\n\n\t\t\t\tEnter the correct number.\n");
                goto nid;
            }
            fclose(info);
        }

        if (count_nid == 0)
        {
            FILE *donation_appointment;
            donation_appointment = fopen("donation_list.txt", "a");

            if (donation_appointment == NULL)
            {
                system("COLOR 04");
                printf("\n\n\t\t\t\tError!!! Somethings went wrong. \n\n\t\t\t\tPress any key to go home....");
                getch();
            }
            else
            {
                if (times == 0)
                {
                    fprintf(donation_appointment, "NID: %lld\nName: %s\nBlood Group: %s\nDate: %d/ %d / %d", nid, name, blood_group, date_day, date_month, date_year);

                    switch (x)
                    {
                    case 1:
                        fprintf(donation_appointment, "\nHospital: LABAID(DHANMONDI)");
                        break;
                    case 2:
                        fprintf(donation_appointment, "\nHospital: SQUARE");
                        break;
                    case 3:
                        fprintf(donation_appointment, "\nHospital: BIHS");
                        break;
                    case 4:
                        fprintf(donation_appointment, "\nHospital: IBN SINA (DHANMONDI 9/A)");
                        break;
                    case 5:
                        fprintf(donation_appointment, "\nHospital: IBN SINA(KALLAYANPUR)");
                        break;
                    case 6:
                        fprintf(donation_appointment, "\nHospital: LABAID(MIRPUR-1)");
                        break;
                    default:
                        printf("\n\tPlease enter the right input.Press any key.....");
                        getch();
                        goto hospital;
                    }
                    times++;
                }

            time:
                printf("\n\n\t\t\tTime slots:\n\t1) 11:00am\n\t2) 02:00pm\n\t3) 05:00pm\n\t4) 07.00pm\n");
                printf("\n\tEnter your time slot no: ");
                scanf("%d", &t);

                switch (t)
                {
                case 1:
                    fprintf(donation_appointment, "\nTime: 11:00am");
                    break;
                case 2:
                    fprintf(donation_appointment, "\nTime: 02:00pm");
                    break;
                case 3:
                    fprintf(donation_appointment, "\nTime: 05:00pm");
                    break;
                case 4:
                    fprintf(donation_appointment, "\nTime: 07.00pm");
                    break;
                default:
                    printf("\n\tPlease enter the right input.Press any key.....");
                    getch();
                    goto time;
                }
                fprintf(donation_appointment, "\n\n\n");

                fclose(donation_appointment);

                loadingBar();
                system("cls");

                printf("\n\n\n\n\t\tThanks for taking an appointment. Please be present on time.\n\n\tPress any key to go to home....");
            }
        }

        getch();
    }
    else
        return 0;
}

// announcement about upcoming event
void event_function()
{
    system("cls");
    printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Upcoming Events \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    char c;
    FILE *E;
    E = (fopen("event.txt", "r"));
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(E);
    }

    fclose(E);
    getch();
}

// who we are
void about_function()
{
    system("cls");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Who We Are \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    char c;
    FILE *ABOUT;
    ABOUT = (fopen("who.txt", "r"));
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(ABOUT);
    }

    fclose(ABOUT);
    getch();
}

// log in function
int log_in_function(var data)
{
    FILE *info;
    info = fopen("information.txt", "r");
    int count_nid, count_password;
log_in:
    system("cls");
    printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Donate Blood \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\t\t\tLog In\n\n\n\t\tEnter your id: ");
    scanf("%lld", &data.nid);
    fflush(stdin);
    printf("\n\t\tEnter your password: ");

    for (int i = 0; i < 20; i++)
    {
    password_take:
        data.password[i] = getch();

        // to exit inputing password
        if (data.password[i] == ENTER)
        {
            data.password[i] = '\0';
            break;
        }

        // to deleting input
        else if (data.password[i] == BACKSPACE)
        {
            printf("\b \b");
            i--;
            goto password_take;
        }

        printf("*");
    }

    long long int nid_check, contact;
    char password_check[20], name[30], blood_group[5], address[30];
    int count = 0;

    if (info == NULL)
    {
        system("COLOR 04");
        printf("\n\n\t\t\t\tError!!! Somethings went wrong. \n\n\t\t\t\tPress any key to go home....");
        getch();
        return 0;
    }
    else
    {
        while (fscanf(info, "%lld\t\t%s\t\t%s\t\t%lld\t%s\t%s", &nid_check, name, blood_group, &contact, address, password_check) != EOF)
        {
            if ((nid_check == data.nid) && strcmp(password_check, data.password) == 0)
            {
                loadingBar();
                count++;
                nid_log = nid_check;
                return -1;
            }
        }
        fclose(info);

        if (count == 0)
        {
            printf("\n\n\n\t\tYou have entered NID Number or Password wrong!!!\n\n\t\tPress any key....");
            getch();
            return 0;
        }
    }
}

// for wating sevarel time
void delay(int time)
{
    int milli_seconds = 1000 * time;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}

// loading bar
void loadingBar()
{
    system("color 0F");
    system("cls");

    char a = 177, b = 219;

    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\tPlease wait...\n\n");
    printf("\t\t\t\t\t");

    // Print initial loading bar
    for (int i = 0; i < 26; i++)
        printf("%c", a);

    // Set the cursor again starting
    // point of loading bar
    printf("\r");
    printf("\t\t\t\t\t");

    // Print loading bar progress
    for (int i = 0; i < 26; i++)
    {
        printf("%c", b);

        // Sleep for 1 second
        Sleep(100);
    }
}
