#include <stdio.h>
#include <stdlib.h>
#include "register_login.h"
//#include "book_management.h"

struct UserArray all_users; //array of all users
struct BookArray all_books; //array of all books


int main(int argc, char const *argv[])
{
    
    loan_length = 0;
    all_users.length = 0;
    all_users.array = (struct User* ) malloc(sizeof(struct User));


    
    //variable used for loading
    struct Book loaded_book;

    char* loaded_name;
    char* loaded_username;
    char* loaded_password;
    char* loaded_email;

    unsigned int ID_loaded; 
    char* title_loaded; 
    char* authors_loaded; 
    char* user_id_loaded;

    //loading
    FILE* file1;
    load_books(file1);
    load_users(file1);
    load_loans(file1);

    
    while (1)
    {
        printf("\n");
        printf("Please choose an option:\n");
        printf("1) Register an account\n");
        printf("2) Login\n");
        printf("3) Search for books\n");
        printf("4) Display all books\n");
        printf("5) Quit\n");
        printf(" Option: ");


        
        
        

        // Evaluationg the option
        static int option;
        scanf("%d", &option);
        printf("\n");

        
        // Option 1 (Register an account)
        if (option == 1)
        {
            option = 0;
            while ((getchar()) != '\n');
            register_user();

            
        }

        //option 2 (Login)
        else if (option ==2)
        {
            option = 0;
            while ((getchar()) != '\n');

            login_user();
            
        }

        //option 3 (Search for books)
        else if (option ==3)
        {
            option = 0;
            while ((getchar()) != '\n');
            find_book();
        }

        //option 4 (Display all books)
        else if (option ==4)
        {
            option = 0;
            while ((getchar()) != '\n');
            // Displaying all books
            printf("Displaying all books...\n\n");
            display_book_array(all_books);
        }

        //option 5 (Quit)
        else if (option ==5)
        {
            option = 0;
            while ((getchar()) != '\n');
            printf("Goodbye!\n\n");

            //saving
            FILE* file;
            store_books(file);
            store_users(file);
            store_loans(file);


            exit(1);
        }

        //invalid inut
        else
        {

            printf("Sorry, the option you entered was invalid, please try again.\n");
            printf("\n");
            while ((getchar()) != '\n'); 
        }
        

    }
    return 0;
}
