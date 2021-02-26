#include <stdio.h>
#include <stdlib.h>
#include "register_login.h"
//#include "book_management.h"


int main(int argc, char const *argv[])
{

    
    while (1)
    {
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

            //login_user();

            //if librarian


            //if normal user


            //if user does not exist



            option = 0;
            while ((getchar()) != '\n');
        }

        //option 3 (Search for books)
        else if (option ==3)
        {

            //find_book();
            
            option = 0;
            while ((getchar()) != '\n');
            /* code */
        }

        //option 4 (Display all books)
        else if (option ==4)
        {


            //display_all_books();
            option = 0;
            while ((getchar()) != '\n');
            /* code */
        }

        //option 5 (Quit)
        else if (option ==5)
        {
            option = 0;
            while ((getchar()) != '\n');

            for (int i = 0; i < all_users.length; i++)
            {
                printf("%s, %p\n", (all_users.array + i)->name, (all_users.array + i));
            }
            

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
