#include <stdio.h>
#include <stdlib.h>


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
        int option;
        scanf("%d", &option);
        printf("\n");


        // Option 1 (Register an account)
        if (option == 1)
        {
            static int re
            register_user();

            //



            option = 0;
            while ((getchar()) != '\n');
        }

        //option 2 (Login)
        else if (option ==2)
        {
            static int lg_usr;
            usr = login_user();

            //if librarian


            //if normal user


            //if user does not exist



            option = 0;
            while ((getchar()) != '\n');
        }

        //option 3 (Search for books)
        else if (option ==3)
        {

            find_book();
            
            option = 0;
            while ((getchar()) != '\n');
            /* code */
        }

        //option 4 (Display all books)
        else if (option ==4)
        {
            option = 0;
            while ((getchar()) != '\n');
            /* code */
        }

        //option 5 (Quit)
        else if (option ==5)
        {
            option = 0;
            while ((getchar()) != '\n');
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
