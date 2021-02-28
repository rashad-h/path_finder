#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "register_login.h"



const unsigned int borrow_limit = 2; // limit of how many books can a user borrow

struct UserArray all_users = {0, 0}; //array of all users





//Registering users
int register_user() {


    char* name;
    char* username;
    char* password;
    char* email;

    int invalid_email = 1; // to check if mail is valid

    //input name
    name = ask_question("Please enter a name: ");


    //input username
    username = ask_question("Please enter a username: ");


    //input password
    password = ask_question("Please enter a password: ");

    //input email
    email = ask_question("Please enter an email: ");

    

    //for checking email
    
    for (int i = 0; i < strlen(email); i++)
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
    if ((0 == (strcmp(username, "librarian"))) || 0) //check to see if librarian or alredy exists
    {
        printf("Sorry, registration unsuccessful, the username you enterd already exists.\n\n");

        return 1;
        
    }

    //check email
    
    else {
            if (invalid_email) {
                printf("The email address entered is invalid!\n\n");

                return 1;
                

            } 
                //adding user
                
            else {
                add_user(name, username, password, email);
                printf("Registration successful!\n\n");
                // free(name);
                // free(username);
                // free(password);
                // free(email);
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
        printf("librarian\n");
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
int librarian_function() {
     while (1)
    {
        printf("Logged in as: librarian\n");
        printf("Please choose an option:\n");
        printf("1) Add a book\n");
        printf("2) Remove a book\n");
        printf("3) Search for books\n");
        printf("4) Display all books\n");
        printf("5) Log out\n");
        printf(" Option: ");

        // Evaluationg the option
        int option;
        scanf("%d", &option);
        printf("\n");

        // Add a book
        if (option == 1)
        {
            option = 0;
            while ((getchar()) != '\n');
        }
        //Remove a book
        else if (option ==2)
        {
            option = 0;
            while ((getchar()) != '\n');
        }
        //Search for books
        else if (option ==3)
        {
            option = 0;
            while ((getchar()) != '\n');    
        }
        //Display all books
        else if (option ==4)
        {
            option = 0;
            while ((getchar()) != '\n');
        }
        //Log out
        else if (option ==5)
        {
            option = 0;
            while ((getchar()) != '\n');
            printf("Logging out...\n");
            return 0;
        }
        //wrong option
        else 
        {
            option = 0;
            while ((getchar()) != '\n');
            printf("Sorry, the option you entered was invalid, please try again.\n");
            printf("\n");
        }
    }

}



// //Logged in as a normal user
int user_function(struct User* user) {
     while (1)
    {
        printf("Logged in as: \n");
        printf("Please choose an option:\n");
        printf("1) Borrow a book\n");
        printf("2) Return a book\n");
        printf("3) Search for books\n");
        printf("4) Display all books\n");
        printf("5) Log out\n");
        printf(" Option: ");

        // Evaluationg the option
        static int option;
        scanf("%d", &option);
        printf("\n");

        // Borrow a book
        if (option == 1)
        {
            option = 0;
            while ((getchar()) != '\n');
        }
        //Return a book
        else if (option ==2)
        {
            option = 0;
            while ((getchar()) != '\n');
        }
        //Search for books
        else if (option ==3)
        {
            option = 0;
            while ((getchar()) != '\n');    
        }
        //Display all books
        else if (option ==4)
        {
            option = 0;
            while ((getchar()) != '\n');
        }
        //Log out
        else if (option ==5)
        {
            option = 0;
            while ((getchar()) != '\n');
            printf("Logging out...\n");
            return 0;
        }
        //wrong option
        else 
        {
            option = 0;
            while ((getchar()) != '\n');
            printf("Sorry, the option you entered was invalid, please try again.\n");
            printf("\n");
        }
    }

}

// //Find user by username
// struct User find_user(char* username){


// }

// //Add user
// //return 0 if user is added successfully
int add_user(char* name, char* username, char* password, char* email) {
    printf("1\n");
    all_users.array[all_users.length].name = name;
    printf("2\n");
    all_users.array[all_users.length].username = username;
    printf("3\n");
    all_users.array[all_users.length].password = password;
    printf("4\n");
    all_users.array[all_users.length].email = email;
    printf("5\n");
    all_users.length = all_users.length + 1;
    printf("6\n");
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


//ask questions
static char *ask_question(const char *question) {

	printf("%s",question);

	const int size_step = 2;
	char *answer = malloc(size_step);
	answer[0] = 0; //now it's a string of length 0.

	//read until a new line in blocks of size_step  bytes at at time
	char *next_chunk = answer;
	int iteration = 0;
	do {
		answer = realloc(answer, size_step + iteration*size_step);
		next_chunk = answer + strlen(answer); //answer may have moved.
		fgets(next_chunk, size_step, stdin);

		next_chunk = answer + strlen(answer); //take the new read into account
		++iteration;
	} while (* (next_chunk-1) != '\n');

	*(next_chunk-1) = 0; //truncate the string eliminating the new line.

	return answer;
}