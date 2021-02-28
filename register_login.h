#ifndef REGISTER_LOGIN_GUARD__H 
#define REGISTER_LOGIN_GUARD__H

#include <stdio.h>
#include "book_management.h"


#define MAX 50 //max number for strings


struct User
{
    char* name; //name of the user
    char* username; //username of the user
    char* password; //password of the user
    char* email;

    struct BookArray borrowed_by_user; //array of books borrowd by this user
};



struct UserArray
{
    struct User* array; //pointer to the array of struct book
    unsigned int length; //number of users
};


//struct UserArray all_users; // array of all users (except librarian)





//Registering users
//return 0 if registerd correctly
int register_user();

//Logging in users
//returns 0 if everything works correctly
int login_user();


//logged in as a Librarian
void librarin_function();

//Logged in as a normal user
int user_function(struct User* user);


//Find user by username
struct User find_user(char* username);

//Add user
//return 0 if user is added successfully
void add_user(char* name, char* username, char* password, char* email);

//Borrow books
//return 0 if successful otherwise return 1;
int borrow_book(struct User user, struct Book book);

//Return book
//return 0 if successful otherwise return 1;
int return_book(struct User user, struct Book book);

//Ask questions
static char *ask_question(const char *question);

#endif