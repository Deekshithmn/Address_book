    
#define _GNU_SOURCE
#include "contact.h"
#include<stdio.h>
#include<string.h>

//----------------------------------------------------------------------------------------------------

//why list?
// using this option we can  access or listout  the data fome the address book
//here i use bubble sort to lis out the contact detailes(assending order)
// and also we can list the data by using sorted  phone and email 

// Function declarations
void sort_by_name(Contact *contacts, int count);
void sort_by_phone(Contact *contacts, int count);
void sort_by_email(Contact *contacts, int count);
void createContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook)
{
    int option;
    char temp[100];

    printf( BHBLU "Enter your listing mode \n"COLOR_RESET);
   
    // Sorting options
    printf( BHBLU"\n Choose how you want to Sort the contact list\n"COLOR_RESET);
    printf( HGRN"1.By Name\n"COLOR_RESET);
    printf( HGRN"2.By Phone\n"COLOR_RESET);
    printf( HGRN"3.By Email\n"COLOR_RESET);

    
    printf(BHBLU"\nEnter your option: "COLOR_RESET);
    printf(HGRN);
    scanf("%d", &option);
    printf(COLOR_RESET);

    // Sorting based on the option selected by the user
    switch (option) { 
        case 1:
            // Sort by Name
            sort_by_name(addressBook->contacts, addressBook->contactCount);
            break;
        case 2:
            // Sort by Phone
            sort_by_phone(addressBook->contacts, addressBook->contactCount);
            break;
        case 3:
            // Sort by Email
            sort_by_email(addressBook->contacts, addressBook->contactCount);
            break;
        default:
            printf("Invalid option\n");
            return;
    }

    // Display the sorted list
    printf(BHBLK "\n===========================================================\n"COLOR_RESET);
    printf(BHRED"Sl\tName\t\tPhone\t\tEmail\n"COLOR_RESET);
    printf(BHBLK "===========================================================\n"COLOR_RESET);
    for (int i = 0; i < addressBook->contactCount; i++) {
        printf("%d\t%s\t", i + 1, addressBook->contacts[i].name);
        printf("%s\t", addressBook->contacts[i].phone);
        printf("%s\n", addressBook->contacts[i].email);
        //printf("\n");
    }
    
}
// Sorting by Name
void sort_by_name(Contact *contacts, int count) {
    char temp[100];
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(contacts[i].name, contacts[j].name) > 0) {
                
                strcpy(temp, contacts[i].name);
                strcpy(contacts[i].name, contacts[j].name);
                strcpy(contacts[j].name, temp);
                // swap phone and email also
                strcpy(temp, contacts[i].phone);
                strcpy(contacts[i].phone, contacts[j].phone);
                strcpy(contacts[j].phone, temp);

                strcpy(temp, contacts[i].email);
                strcpy(contacts[i].email, contacts[j].email);
                strcpy(contacts[j].email, temp);
            }
        }
    }
}

// Sorting by Phone
void sort_by_phone(Contact *contacts, int count) {
    char temp[100];
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(contacts[i].phone, contacts[j].phone) > 0) {
               
                strcpy(temp, contacts[i].phone);
                strcpy(contacts[i].phone, contacts[j].phone);
                strcpy(contacts[j].phone, temp);
                // swap name and email also
                strcpy(temp, contacts[i].name);
                strcpy(contacts[i].name, contacts[j].name);
                strcpy(contacts[j].name, temp);

                strcpy(temp, contacts[i].email);
                strcpy(contacts[i].email, contacts[j].email);
                strcpy(contacts[j].email, temp);
            }
        }
    }
}

// Sorting by Email
void sort_by_email(Contact *contacts, int count) {
    char temp[100];
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(contacts[i].email, contacts[j].email) > 0) {
               
                strcpy(temp, contacts[i].email);
                strcpy(contacts[i].email, contacts[j].email);
                strcpy(contacts[j].email, temp);
                // swap name and phone also
                strcpy(temp, contacts[i].name);
                strcpy(contacts[i].name, contacts[j].name);
                strcpy(contacts[j].name, temp);

                strcpy(temp, contacts[i].phone);
                strcpy(contacts[i].phone, contacts[j].phone);
                strcpy(contacts[j].phone, temp);
            }
        }
    }
}

//------------------------------------------------------------------------------------------------------------------------
//why creat contact?
// using this option we create the new name ,phone,and email 
//It should be unique
void createContact(AddressBook *addressBook) 
{
    char create_name[50];
    char create_phone[20];
    char create_email[50];
    int is_name=0;
    int is_phone=0;
    int is_email=0;
    int i=0;
    while(1)
    {
        //read the contact name
        printf( BHBLU"Enter Name for create: "COLOR_RESET);
        printf(HCYN);
        scanf(" %[^\n]",create_name);
        printf(COLOR_RESET);
        //read the phone number
        printf( BHBLU"Enter Phone Number for create: "COLOR_RESET);
        printf(HCYN);
        scanf(" %[^\n]",create_phone);
        printf(COLOR_RESET);
        //read the email 
        printf( BHBLU"Enter Email ID for create: "COLOR_RESET);
        printf(HCYN);
        scanf(" %[^\n]",(create_email));
        printf(COLOR_RESET);

        //chaeck the contact  name is present in address book or not====>1
        for(int i=0;i<(addressBook->contactCount);i++)
        {
            int check_name=strcmp(addressBook->contacts[i].name,create_name);
            if(check_name==0)
            {
                printf(HRED"\nThe entered Name "HYEL" '%s' "HRED" is already exist?\n"COLOR_RESET,create_name);
                is_name=1;
                break;
            }
        }
        if(is_name)
        {
            printf(BHBLU"Enter a new contact Name\n"COLOR_RESET);
            is_name=0;
            continue;
        }
        //Read vallid name
        for(int i=0;create_name[i]!='\0';i++)
        {
            if(!((create_name[i]>='A'&& create_name[i]<='Z')
                ||(create_name[i]>='a'&&create_name[i]<='z')
                ||create_name[i]==' '))
            {
                printf(BHRED"\nEnter a Valid Contact Name!!\n"COLOR_RESET);

            }
            continue;
        }
        //printf("%s",creat_name);
        
        //chaeck the contact phone is present or not=====>2
        for(int i=0;i<(addressBook->contactCount);i++)
        {
            int check_phone=strcmp(addressBook->contacts[i].phone,create_phone);
            if(check_phone==0)
            {
                printf(HRED"\nThe entered Phone Number "HYEL" '%s' "HRED" is already exist?\n"COLOR_RESET,create_phone);
                is_phone=1;
                break;
            }
        }
        if(is_phone)
        {
            printf(BHBLU"Enter a new contact Phone Number \n"COLOR_RESET);
            is_phone=0;
            continue;
        }

        //Read vallid phone number 
        int phone_length=strlen(create_phone);
        for(int i=0;i<phone_length;i++)
        {
            if(!(create_phone[i]>='0'&& create_phone[i]<='9'))
            {
                printf(HRED"\nEnter a Valid Contact Phone Number!! \n"COLOR_RESET);
                break;
            }
        }
        if(phone_length!=10)
        {
            printf(HRED"\nPhone number must be contain 10 digits, please enter again!!\n"COLOR_RESET);
            continue;
        }
        //printf("%s",creat_phone);
    
        //chaeck the contact  email is present or not====>3
        
        for(int i=0;i<(addressBook->contactCount);i++)
        {
            int check_email=strcmp(addressBook->contacts[i].email,create_email);
            if(check_email==0)
            {
                printf(HRED"\nThe entered Email ID "HYEL" '%s' "HRED" is already exist?\n"COLOR_RESET,create_email);
                is_email=1;
                break;
            }
        }
        if(is_email)
        {
            printf(BHBLU"Enter the new Email ID\n"COLOR_RESET);
            is_email=0;
            continue;
        }
        //Read valid email
        if(strchr(create_email,'@')==NULL ||strstr(create_email,".com")==NULL)
        {
            printf(HRED"\nEnter a Valid Email address!!\n"COLOR_RESET);
            continue;
        }
        //printf("%s",creat_email);
        break;
    }
    strcpy(addressBook->contacts[addressBook->contactCount].name,create_name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,create_phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email,create_email);
    //Increment the Contact count 
    (addressBook->contactCount)++;
}

//----------------------------------------------------------------------------------------------------------------------
//why search?
// using this option we can  search  it and access the data from the address book
// by name ,phone  or email we can search it.

void searchContact(AddressBook *addressBook) 
{
    char search_name[20];
    char search_phone[50];
    char search_email[50];
    int option;
    int sl=1;
    printf(BHBLU"Enter your Searching mode \n"COLOR_RESET);
    printf(HGRN"1. By Name\n"COLOR_RESET);
    printf(HGRN"2. By Phone\n"COLOR_RESET);
    printf(HGRN"3. By Email\n"COLOR_RESET);

    printf(BHBLU "Enter your option: "COLOR_RESET);
    printf(HGRN);
    scanf("%d",&option);
    printf(COLOR_RESET);
    switch(option)
    {
        case 1:
        {
            //search by using name
            printf(BHBLU"Enter the Name for searching: "COLOR_RESET);
            printf(HCYN);
            scanf(" %[^\n]",search_name);
            printf(COLOR_RESET);
            int found=0; //flag variable to check string is present or not
            printf(BHGRN"\nAfter Searching by Name\n"COLOR_RESET);
            printf(BHBLK"============================================================\n"COLOR_RESET);
            printf(BHRED"Sl\tName\t\tPhone\t\tEmail\n"COLOR_RESET);
            printf(BHBLK"=============================================================\n"COLOR_RESET);
            for(int i=0;i<(addressBook->contactCount);i++)
            {
                if(strcasestr(addressBook->contacts[i].name,search_name)!=NULL)
                {
                    printf("%d \t%s\t",sl++,addressBook->contacts[i].name);
                    printf("%s\t",addressBook->contacts[i].phone);
                    printf("%s",addressBook->contacts[i].email);
                    found=1;
                    printf("\n");
                }  
            }
            printf("\n");
            if(!found)
                {
                    printf(HRED"\nNo contact found with the name "HYEL" '%s' \n"COLOR_RESET, search_name);
                }
                break;
        }
        case 2:
        {
            printf(BHBLU"Enter the Phone Number for searching: "COLOR_RESET);
            printf(HCYN);
            scanf(" %[^\n]",search_phone);
            printf(COLOR_RESET);
            //search by using phone number
            int found=0;
            printf(BHGRN"\nAfter Searching by Phone Number\n"COLOR_RESET);
            printf(BHBLK"==========================================================\n"COLOR_RESET);
            printf(BHRED "Sl\tName\t\tPhone\t\tEmail\n"COLOR_RESET);
            printf(BHBLK"==========================================================\n"COLOR_RESET);
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(strcasestr(addressBook->contacts[i].phone,search_phone)!=NULL)
                {
                    printf("%d\t %s\t",sl++,addressBook->contacts[i].name);
                    printf("%s\t",addressBook->contacts[i].phone);
                    printf("%s",addressBook->contacts[i].email);
                    printf("\n");
                    found = 1;
                }
            }
            printf("\n");
            if(!found)
            {
                printf(HRED"\nNo contact found with the Phone Number "HYEL" '%s'  \n"COLOR_RESET, search_phone);
            }
            break;
        }
        case 3:
        {
            //search by using email
            printf(BHBLU"Enter the Email Address for searching: "COLOR_RESET);
            printf(HCYN);
            scanf(" %[^\n]", search_email);
            printf(COLOR_RESET);
            //search by using email
            int found = 0;
            printf(BHGRN"\nAfter Searching by Email ID\n"COLOR_RESET);
            printf(BHBLK"=========================================================\n"COLOR_RESET);
            printf(BHRED"Sl\tName\t\tPhone\t\tEmail\n"COLOR_RESET);
            printf(BHBLK"=========================================================\n"COLOR_RESET);
            for (int i = 0; i < addressBook->contactCount; i++) 
            {
                if (strcasestr(addressBook->contacts[i].email, search_email) != NULL) 
                {
                    printf("%d\t %s\t",sl++,addressBook->contacts[i].name);
                    printf("%s\t",addressBook->contacts[i].phone);
                    printf("%s",addressBook->contacts[i].email);
                    printf("\n");
                    found = 1;
                }
            }
            printf("\n");
            if (!found) 
            {
                printf(HRED"\nNo contact found with the email "HYEL" '%s' \n"COLOR_RESET, search_email);
            }
            break;
        }
        default:
        {
            printf(BHRED"\nInvalid Option Selected!\n"COLOR_RESET);
            break;
        }
    }
 }
//---------------------------------------------------------------------------------------------------------------------
// only use  name to edit
//why edit?
// using this option we can edit the contact details from the address book
void editContact(AddressBook *addressBook) 
{
    char edit_name[50];
    char edit_phone[50];
    char edit_email[50];
    int index[100]; // taking another array to store the founded index
    int found=0;
    int sl=1;
    int edit_sl,i;
    
    
    printf(BHBLU"Enter the Name to edit the contact: "COLOR_RESET);
    printf(HCYN);
    scanf(" %[^\n]",edit_name);
    printf(COLOR_RESET);
    
    printf(BHBLK"=========================================================\n"COLOR_RESET);
    printf(BHRED"Sl\tName\t\tPhone\t\tEmail\n"COLOR_RESET);
    printf(BHBLK"=========================================================\n"COLOR_RESET);

    for(int i=0;i<(addressBook->contactCount);i++)
    {
        char *ret=(strcasestr(addressBook->contacts[i].name,edit_name));
        if(ret)
        {
            printf("%d\t %s\t",sl++,addressBook->contacts[i].name);
            printf("%s\t",addressBook->contacts[i].phone);
            printf("%s",addressBook->contacts[i].email);
            printf("\n");
            // Store the index of the found contact
            index[found]=i;
            found++;  
        }
    }
    if(!found)
    {
        printf(BHRED"\nThe Entered Name is not found! \n"COLOR_RESET);
        return;
    }
    
    // if the contact name is found we enter the new contact details
    // enter the new contact details
    printf(BHBLU"\nEnter the sl number of contact to edit: "COLOR_RESET);
    printf(HCYN);
    scanf("%d",&edit_sl);
    printf(COLOR_RESET);
    
    int edit_index=index[edit_sl-1];
    printf(HRED"Are you sure to edit "HYEL" '%s' "HRED"contact\n"COLOR_RESET,addressBook->contacts[edit_index].name);
    int option;
    printf(HGRN"1. Yes\n"COLOR_RESET);
    printf(HGRN"2. No\n"COLOR_RESET);
    printf(HBLU"Choose your option: "COLOR_RESET);
    printf(HCYN);
    scanf("%d",&option);
    printf(COLOR_RESET);
    switch (option)
    {
        case 1:
        {
            break; 
        }    
        case 2:
        {
            printf(BHGRN"\nAfter Editing the Contacts:"COLOR_RESET);
            printf(BHBLK"\n===========================================================\n"COLOR_RESET);
            printf(BHRED"Sl\tName\t\tPhone\t\tEmail\n"COLOR_RESET);
            printf(BHBLK"===========================================================\n"COLOR_RESET);
            for(int i=0;i<(addressBook->contactCount);i++)
            {
                printf("%d\t%s\t",i+1,addressBook->contacts[i].name);
                printf("%s\t",addressBook->contacts[i].phone);
                printf("%s",addressBook->contacts[i].email);
                printf("\n");
            }
            return;
            
        }
        default:
        {
            printf(BHRED"\nInvalid Input!!\n"COLOR_RESET);
            return;
        }
    }
    printf(BHBLU"Enter Name: "COLOR_RESET);
    printf(HCYN);
    scanf(" %[^\n]"COLOR_RESET,edit_name);
    printf(COLOR_RESET);
    printf(BHBLU"Enter Phone number: "COLOR_RESET);
    printf(HCYN);
    scanf(" %[^\n]"COLOR_RESET,edit_phone);
    printf(COLOR_RESET);
    printf(BHBLU"Enter Email ID: "COLOR_RESET);
    printf(HCYN);
    scanf(" %[^\n]"COLOR_RESET,edit_email);
    printf(COLOR_RESET);

    // Check for duplicate name, phone, or email from the other contacts in the same list
    for(int i=0;i<(addressBook->contactCount);i++)
    {
        if(strcmp(addressBook->contacts[i].name,edit_name)==0 && i!=edit_index)
        {
            printf(HRED"\nThe Name "HYEL" '%s' "HRED" is already exist!\n"COLOR_RESET,edit_name);
            return; 
        }
    }
     for(int i=0;i<(addressBook->contactCount);i++)
    {
        if (strcmp(addressBook->contacts[i].phone,edit_phone)==0 && i!=edit_index)
        {
            printf(HRED"\nThe Phone number "HYEL" '%s' "HRED" is already exist!\n"COLOR_RESET,edit_phone);
            return;
        }
    }
    for(int i=0;i<(addressBook->contactCount);i++)
    {
        if(strcmp(addressBook->contacts[i].email,edit_email)==0 && i!=edit_index)
        {
            printf(HRED"\nThe Email ID "HYEL" '%s' "HRED" is already exist!\n"COLOR_RESET,edit_email);
            return;
        }
    }
    
    // Update contact details
    strcpy(addressBook->contacts[edit_index].name,edit_name);
    strcpy(addressBook->contacts[edit_index].phone,edit_phone);
    strcpy(addressBook->contacts[edit_index].email,edit_email);
    // After editing the contact
    //// Show updated contact list
    printf(BHGRN"\nAfter Editing the Contacts:"COLOR_RESET);
    printf(BHBLK"\n===========================================================\n"COLOR_RESET);
    printf(BHRED"Sl\tName\t\tPhone\t\tEmail\n"COLOR_RESET);
    printf(BHBLK"===========================================================\n"COLOR_RESET);
    for(int i=0;i<(addressBook->contactCount);i++)
    {
        printf("%d\t%s\t",i+1,addressBook->contacts[i].name);
        printf("%s\t",addressBook->contacts[i].phone);
        printf("%s",addressBook->contacts[i].email);
        printf("\n");
    }
}
//---------------------------------------------------------------------------------------------------------------
// why delete?
//  using this option we can delete the contact detailes form the address book
// after deleting we can update the contact file by using save option 
void deleteContact(AddressBook *addressBook) 
{
    char delet_name[50], delet_phone[20], delet_email[50];
    int found = 0;
    int index[100];  // Array to store the matching contacts
    int sl = 1;
    int delete_sl;
    int option;
    
    // Ask the user for deleted mode
    printf(BHBLU"Choose how you want to delete the contact:\n");
    printf(BHGRN"1. By Name\n"COLOR_RESET);
    printf(BHGRN"2. By Phone\n"COLOR_RESET);
    printf(BHGRN"3. By Email\n"COLOR_RESET);
    printf(BHBLU"Choose your option: "COLOR_RESET);
    printf(HCYN);
    scanf("%d", &option);
    printf(COLOR_RESET);

    switch(option) 
    {
        case 1:
            printf(BHBLU"Enter the name you want to delete: ");
            printf(HCYN);
            scanf(" %[^\n]", delet_name);
            break;
        case 2:
            printf(BHBLU"Enter the phone number you want to delete: ");
            printf(HCYN);
            scanf(" %[^\n]", delet_phone);
            break;
        case 3:
            printf(BHBLU"Enter the email you want to delete: ");
            printf(HCYN);
            scanf(" %[^\n]", delet_email);
            break;
        default:
            printf(BHRED"\nInvalid Option!\n"COLOR_RESET);
            return;
    }

    printf(COLOR_RESET);
    printf(BHBLK"=========================================================\n"COLOR_RESET);
    printf(BHRED"Sl\tName\t\tPhone\t\tEmail\n"COLOR_RESET);
    printf(BHBLK"=========================================================\n"COLOR_RESET);

    // Search for contacts based on the option
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        int match = 0;
        
        switch(option) 
        {
            case 1:
                // Compare by name (case insensitive==>strcasestr)
                if (strcasestr(addressBook->contacts[i].name, delet_name)) {
                    match = 1;
                }
                break;
            case 2:
                // Compare by phone
                if (strcasestr(addressBook->contacts[i].phone, delet_phone)) {
                    match = 1;
                }
                break;
            case 3:
                // Compare by email
                if (strcasestr(addressBook->contacts[i].email, delet_email)) {
                    match = 1;
                }
                break;
        }
        
        if (match)
         {
            printf("%d\t %s\t", sl++, addressBook->contacts[i].name);
            printf("%s\t", addressBook->contacts[i].phone);
            printf("%s\t", addressBook->contacts[i].email);
            printf("\n");
            index[found] = i;  // Store the index of the found contact
            found++;
        }
    }

    // If no contacts were found, return to ask for valid option
    if (!found)
    {
        printf(BHRED"\nNo contacts found matching your input!\n"COLOR_RESET);
        return;
    }

    // Ask the user which contact to delete
    printf(BHBLU"\nEnter the sl number of the contact to delete: "COLOR_RESET);
    printf(HCYN);
    scanf("%d", &delete_sl);
    printf(COLOR_RESET);

    if (delete_sl < 1 || delete_sl > found)
    {
        printf(BHRED"\nInvalid Selection!\n"COLOR_RESET);
        return;
    }

    int delete_index = index[delete_sl - 1];
    printf(HRED"Are you sure you want to delete the contact "HYEL"'%s'?\n"COLOR_RESET, addressBook->contacts[delete_index].name);
    
    printf(BHGRN"1. Yes\n"COLOR_RESET);
    printf(BHGRN"2. No\n"COLOR_RESET);
    printf(BHBLU"Choose your option: "COLOR_RESET);
    printf(BHGRN);
    scanf("%d", &option);
    printf(COLOR_RESET);

    switch (option) {
        case 1:
            // Shift contacts after the deleted one
            for (int j = delete_index; j < addressBook->contactCount - 1; j++)
            {
                strcpy(addressBook->contacts[j].name, addressBook->contacts[j + 1].name);
                strcpy(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone);
                strcpy(addressBook->contacts[j].email, addressBook->contacts[j + 1].email);
            }
            // Decrement the contact count
            addressBook->contactCount--;
            printf(HRED"Contact deleted successfully.\n"COLOR_RESET);
            break;
        case 2:
            printf(HRED"Contact deletion canceled.\n"COLOR_RESET);
            break;
        default:
            printf(BHRED"Invalid input!\n"COLOR_RESET);
            break;
    }

    // Show remaining contacts
    printf(BHGRN"\nRemaining Contacts:"COLOR_RESET);
    printf(BHBLK"\n===========================================================\n"COLOR_RESET);
    printf(BHRED"Sl\tName\t\tPhone\t\tEmail\n"COLOR_RESET);
    printf(BHBLK"===========================================================\n"COLOR_RESET);
    for (int i = 0; i < addressBook->contactCount; i++) {
        printf("%d\t%s\t", i + 1, addressBook->contacts[i].name);
        printf("%s\t", addressBook->contacts[i].phone);
        printf("%s", addressBook->contacts[i].email);
        printf("\n");
    }
}


//-------------------------------------------------------------------------------------------------
// why initialisation
// we access the data from contact.txt file to adreess book
void initialize(AddressBook *addressBook) 
{
    
    FILE*contact;
    char temp[1000];
    char *temp_name,*temp_phone,*temp_email;
    //open the file with a read mode
    contact=fopen("contact.txt","r");
    addressBook->contactCount=0;
    
    if (contact == NULL)
    {
        printf(HRED"Error opening file.\n"COLOR_RESET);
        return;
    }
    while ((fgets(temp, sizeof(temp), contact) != NULL))
    {
        int length = strlen(temp);
        // printf("%d",len);
        if (temp[length - 1] == '\n')
        {
            temp[length - 1] = '\0';
        }
        // printf("%s\n", temp);

        //break into phone name and email
        temp_name = strtok(temp, ",");
        temp_phone = strtok(NULL, ",");
        temp_email = strtok(NULL, ",");
        strcpy(addressBook->contacts[addressBook->contactCount].name, temp_name);
        strcpy(addressBook->contacts[addressBook->contactCount].phone, temp_phone);
        strcpy(addressBook->contacts[addressBook->contactCount].email, temp_email);
        addressBook->contactCount++;
    }
    fclose(contact); 
}


//----------------------------------------------------------------------------------------------------------------------
// why save?
//we want to  save the contact detailes permanently
//using this we can save data to contact.txt  
void saveContacts(AddressBook *addressBook)
{
    FILE *fptr;
    fptr=fopen("contact.txt","w");
    if(fptr==NULL)
    {
        fprintf(fptr,BHRED"File dose not exist!!\n"COLOR_RESET);
        return;
    }
    for(int i=0;i<(addressBook->contactCount);i++)
    {
        fputs(addressBook->contacts[i].name,fptr);
        fputc(',',fptr);
        fputs(addressBook->contacts[i].phone,fptr);
        fputc(',',fptr);
        fputs(addressBook->contacts[i].email,fptr);
        fputc('\n',fptr);
    
        // fprintf(fptr,"\n");
    }
    fclose(fptr);
}
