#include "contact.h"
#include<stdlib.h>
int main()
{ 
    int option;
    AddressBook addressbook;
    initialize(&addressbook);
    while(1)
    {
        // print menu here
        printf("\n");
        printf(BHRED"**Menu**\n"COLOR_RESET);
        printf(HBLU"1 Create Contact\n"COLOR_RESET);
        printf(HBLU"2 Search Contact\n"COLOR_RESET);
        printf(HBLU"3 Edit Contact\n"COLOR_RESET);
        printf(HBLU"4 Delete Contact\n"COLOR_RESET);
        printf(HBLU"5 List Contact\n"COLOR_RESET);
        printf(HBLU"6 Save Contact\n"COLOR_RESET);
        printf(HBLU"7 Exit Contact\n"COLOR_RESET);

        //Reade the option
        printf(BHMAG"\nChoose your option between 1 to 7 : "COLOR_RESET);
        printf(BHYEL);
        scanf("%d",&option);
        printf(COLOR_RESET);
        // call the contacts using switch case
        switch (option)
        {
            case 1:
            {
                createContact(&addressbook);
                break;
            }
            case 2:
            {
                searchContact(&addressbook);
                break;
            }
            case 3:
            {
                editContact(&addressbook);
                break;
            }
            case 4:
            {
                deleteContact(&addressbook);
                break;
            }
            case 5:
            {
                listContacts(&addressbook);
                break;
            }
            case 6:
            {
                saveContacts(&addressbook);
                printf(BHGRN"\nSaved Successfully!!\n"COLOR_RESET);
                break;
            }
            case 7:
            {
                printf(BHRED"AddressBook Exited!!\n"COLOR_RESET);
                exit(0);
            }
            default:
            {
                printf(BHRED"Invalid option please try again!\n"COLOR_RESET);

            }
        }  
    }
}
