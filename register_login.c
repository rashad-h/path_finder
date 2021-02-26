#include <stdio.h>
#include "register_login.h"
#include <string.h>


const unsigned int borrow_limit = 2; // limit of how many books can a user borrow

// struct User first_user;


struct UserArray all_users = {, 0}; //array of all users
// all_users.array = (User* ) malloc(sizeof(User));
// all_users.length = 0;




//Registering users
int register_user() {

    printf("%lu\n", sizeof(struct User));

    char name[MAX];
    char username[MAX];
    char password[MAX];
    char email[MAX];

    int invalid_email = 1; // to check if mail is valid

    //input name
    printf("Please enter a name: ");
    fgets(name, MAX, stdin);
    //int len ​​= strlen(name);
    //if(len >0&&name[len-1] =='\n') name[len-1] ='\0';

    //input username
    printf("Please enter a username: ");
    fgets(username, MAX, stdin);
    // len ​​= strlen(username);
    // if(len >0&&username[len-1] =='\n') username[len-1] ='\0';

    //input password
    printf("Please enter a password: ");
    fgets(password, MAX, stdin);

    //input email
    printf("Please enter an email: ");
    fgets(email, MAX, stdin);

    

    //for checking email
    
    for (int i = 0; i < MAX; i++)
    {
        if (email[i] == '\n')
        {
            invalid_email = 1;
            break;
        }
        
        if(email[i] == '@') {
            invalid_email = 0;
            break;
        }
        
    }
    printf("\n");

    //check username
    if ((0 == (strcmp(username, "librarian\n"))) || 0) //check to see if librarian or alredy exists
    {
        printf("Sorry, registration unsuccessful, the username you enterd already exists.\n\n");
        return 1;
    }

    //check email
    
    else {
            if (invalid_email) {
                printf("THe email address entered is invalid!\n\n");
                return 1;

            } 
                //adding user
            else {
                add_user(name, username, password, email);
                printf("Registration successful!\n\n");
                for (int i = 0; i < all_users.length; i++)
                {
                    printf("%s, %p\n", (all_users.array + i)->name, (all_users.array + i));
                }
                return 0;
                
            }
    }
    
    


}



// //logging in
int login_user() {

    char username[MAX];
    char password[MAX];

    //input username
    printf("Please enter a username: ");
    fgets(username, MAX, stdin);

    //input password
    printf("Please enter a password: ");
    fgets(password, MAX, stdin);

    //check if lbrarian
    if ((0 == (strcmp(username, "librarian\n"))) && (0 == (strcmp(password, "librarian\n")))) {
        //librarian function
        //librarin_function();
        return 0;
    }

    // else
    // {
    //     if (/* condition */)
    //     {
    //         /* code */
    //     }
        
    // }
    
    

    //else try to find user

    //user function
    return 0;
}


// //Logged in as a librarian
// void librarian_function() {


// }



// //Logged in as a normal user
// void user_function(struct User user) {


// }

// //Find user by username
// struct User find_user(char* username){


// }

// //Add user
// //return 0 if user is added successfully
int add_user(char* name, char* username, char* password, char* email) {

    
    // struct User* a_user;= all_users.array + all_users.length;
    // a_user = (User *) malloc(sizeof(User));
    //(all_users.array + all_users.length)->

    if (all_users.length == 0)
    {
        all_users.array = (User* ) malloc(sizeof(User));
        all_users.array->name = name;
        all_users.array->username = username;
        all_users.array->password = password;
        all_users.array->email = email;
    }
    else
    {
        (all_users.array + all_users.length)->name = name;
        (all_users.array + all_users.length)->username = username;
        (all_users.array + all_users.length)->password = password;
        (all_users.array + all_users.length)->email = email;
    }
    

    

    printf("%s, %p\n", (all_users.array + all_users.length)->name, (all_users.array + all_users.length));

    all_users.length = all_users.length + 1;


    return 0;
}

// //Borrow books
// //return 0 if successful otherwise return 1;
// int borrow_book(struct User user, struct Book book) {

//     return 0;
// }

// //Return book
// //return 0 if successful otherwise return 1;
// int return_book(struct User user, struct Book book) {

//     return 0;
// }