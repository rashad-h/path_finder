#include <stdio.h>
#include "register_login.h"
#include <string.h>


const unsigned int borrow_limit = 2; // limit of how many books can a user borrow


//Registering users
int register_user() {

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

    printf("\n");

    //for checking email
    for (int i = 0; i < MAX; i++)
    {
        if(email[i] == '@') {
            invalid_email = 0;
        }
    }

    //check username
    if ((0 == (strcmp(username, "librarian\n"))) || 0) //check to see if librarian or alredy exists
    {
        printf("opps");
        return 1;
    }

    //check email
    else if (invalid_email) {
        printf("Emailllllll\n");
        return 1;

    } 
    
    //adding user
    else {
        add_user()
    return 0;
    }

}



// //logging in
// int login_user() {

//     //input username

//     //input password

//     //check if lbrarian

//     //librarian function

//     //else try to find user

//     //user function
//     return 0;
// }


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