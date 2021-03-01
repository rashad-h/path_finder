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
    if ((0 == (strcmp(username, "librarian"))) || find_user(username)) //check to see if librarian or alredy exists
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
                return 0;   
            }
    }
    
    


}



// //logging in
int login_user() {

    char* username;
    char* password;

    //input username
    username = ask_question("Please enter a username: ");

    //input password
    password = ask_question("Please enter a password: ");

    printf("\n");
    //check if lbrarian
    if ((0 == (strcmp(username, "librarian"))) && (0 == (strcmp(password, "librarian")))) {
        //librarian function
        librarian_function();
        return 0;
    }

    else
    {
        if (find_user(username))
        {
            if (!strcmp(find_user(username)->password, password))
            {
                //Login function
                user_function(find_user(username));
                return 0;
            }
            
        }

        printf("Incrorrect username or password!\n\n");
        return 1;
        
    }
    
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
            //adding book interface
            ready_add_book();
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
            //find a book
            find_book();  
        }
        //Display all books
        else if (option ==4)
        {
            option = 0;
            while ((getchar()) != '\n');
            //display all books
            printf("Displaying all books...\n\n");
            display_book_array(all_books);
        }
        //Log out
        else if (option ==5)
        {
            option = 0;
            while ((getchar()) != '\n');
            printf("Logging out...\n\n");
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
        printf("Logged in as: %s\n", user->username);
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
            // Finding books
            find_book();   
        }
        //Display all books
        else if (option ==4)
        {
            option = 0;
            while ((getchar()) != '\n');
            // Displaying all books
            printf("Displaying all books...\n\n");
            display_book_array(all_books);
        }
        //Log out
        else if (option ==5)
        {
            option = 0;
            while ((getchar()) != '\n');
            printf("Logging out...\n\n");
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
struct User* find_user(char* username){
    for (int i = 0; i < all_users.length; i++)
    {
        if (!strcmp(all_users.array[i].username, username))
        {
            return &all_users.array[i];
        }
        
    }
    return 0;    

}

// //Add user
// //return 0 if user is added successfully
void add_user(char* name, char* username, char* password, char* email) {

    all_users.array = realloc(all_users.array, (all_users.length + 1) * sizeof(struct User));
    all_users.array[all_users.length].name = name;

    all_users.array[all_users.length].username = username;

    all_users.array[all_users.length].password = password;

    all_users.array[all_users.length].email = email;

    all_users.length++;

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
char *ask_question(const char *question) {

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