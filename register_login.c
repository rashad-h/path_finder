#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "register_login.h"


struct UserArray all_users = {0, 0}; //array of all users

//variable used for loading
char* loaded_name;
char* loaded_username;
char* loaded_password;
char* loaded_email;

unsigned int ID_loaded; 
char* title_loaded; 
char* authors_loaded; 
char* user_id_loaded;



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
            ready_remove_book();
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
            borrow_book(* user);
        }
        //Return a book
        else if (option ==2)
        {
            option = 0;
            while ((getchar()) != '\n');
            return_book(* user);
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
int borrow_book(struct User user) {
    display_book_array(all_books);
    char* book_id;
    book_id = ask_question("Enter the ID of the book you want to borrow: ");
    
    // check id is valid
    if (atoi(book_id) >= 0 && atoi(book_id) < all_books.length)
    {
        //check you have not borrowed this book
        if (loaned_already(atoi(book_id), user.username))
        {
            //check there is enough copies in the library
            if (all_books.array[atoi(book_id)].copies > 0)
            {
                add_loan(atoi(book_id), all_books.array[atoi(book_id)].title, all_books.array[atoi(book_id)].authors, user.username);
                all_books.array[atoi(book_id)].copies--;
                printf("Borrowed book successfully!\n\n");
                return 0;
            }
            else
            {
                printf("There is not enough copies of this book in the library\n\n");
                return 1;
            }
            
            
        }
        else
        {
            printf("You have already borrowed this book!\n\n");
            return 1;
        }
        
        

    }
    else
    {
        printf("Book ID is not valid.\n\n");
        return 1;
    }

}

// //Return book
// //return 0 if successful otherwise return 1;
int return_book(struct User user) {
    int number_borrowed = 0; //number of books borrowed;
    for (int i = 0; i < loan_length; i++)
    {
        if ((!strcmp(user.username, all_loans[i].user_id))) {
            printf("%i\t%-32s\t%-32s\n", all_loans[i].ID, all_loans[i].title, all_loans[i].authors);
            number_borrowed++;
        }
    }
    // check if user has borrowed any books
    if (number_borrowed > 0)
    {
        char* book_id;
        book_id = ask_question("Enter the ID of the book you want to return: ");

        //check if Id is valid
        if (!delete_loan(atoi(book_id), user.username))
        {
            all_books.array[atoi(book_id)].copies++;
            printf("The book was returned successfully!\n\n");
            return 0;
        }
        else
        {
            printf("The ID enetered is invalid\n\n");
            return 1;
        }
        
        
    }
    else
    {
        printf("You have not borrowed any books.\n\n");
        return 1;
    }

}


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

// delete a loan
// returns 0 if successful
int delete_loan(unsigned int ID, char* user_id) {
	for (int i = 0; i < loan_length; i++)
	{
		if ((all_loans[i].ID == ID) && (!strcmp(user_id, all_loans[i].user_id)))
		{
			for (int j = 0; j < (loan_length - (i + 1)); j++)
			{
				all_loans[i].title = all_loans[i + (j + 1)].title;
				all_loans[i].user_id = all_loans[i + (j + 1)].user_id;
                all_loans[i].authors = all_loans[i + (j + 1)].authors;
                all_loans[i].ID = all_loans[i + (j + 1)].ID;
			}
			loan_length--;
			return 0;
			
		}
		
	}
    return 1;
}

// add a loan to all loans
// returns 0 if successful
int add_loan(unsigned int ID, char* title, char* authors, char* user_id) {
    all_loans[loan_length].title = title;
    all_loans[loan_length].authors = authors;
    all_loans[loan_length].user_id = user_id;
    all_loans[loan_length].ID = ID;
    loan_length++;
    return 0;
}


// To check if you already have loaned this book
// return 1 if not loaned
int loaned_already(unsigned int ID, char* user_id) {
    for (int i = 0; i < loan_length; i++)
	{
		if ((all_loans[i].ID == ID) && (!strcmp(user_id, all_loans[i].user_id)))
		{
            return 0;
        }
    }
    return 1;
}

//saves the database of users in the specified file
//returns 0 if users were stored correctly, or an error code otherwise
int store_users(FILE *file) {

    file = fopen("users.txt", "w");
    fprintf(file, "%i\n", all_users.length);
    for (int i = 0; i < all_users.length; i++)
    {
        fprintf(file, "%s\n%s\n%s\n%s\n", all_users.array[i].name,
                 all_users.array[i].username, all_users.array[i].password, all_users.array[i].email);
    }
    fclose(file);
    return 0;
}

//loads the database of users from the specified file
//the file must have been generated by a previous call to store_users()
//returns 0 if users were loaded correctly, or an error code otherwise
int load_users(FILE *file) {


    file = fopen("users.txt", "r");
    if(file == NULL) {
        return 1;
    }

    int pre_length = 0;
    char str[49];
    fgets(str, 49, file);
    pre_length = atoi(str);
    for (int i = 0; i < pre_length; i++)
    {
        
        fgets(str, 49, file);
        str[strcspn(str, "\n")] = 0;
        strcpy(loaded_name = (char*)malloc(sizeof(str)), str);
        
        fgets(str, 49, file);
        str[strcspn(str, "\n")] = 0;
        strcpy(loaded_username = (char*)malloc(sizeof(str)), str);

        fgets(str, 49, file);
        str[strcspn(str, "\n")] = 0;
        strcpy(loaded_password = (char*)malloc(sizeof(str)), str);

        fgets(str, 49, file);
        str[strcspn(str, "\n")] = 0;
        strcpy(loaded_email = (char*)malloc(sizeof(str)), str);

        add_user(loaded_name, loaded_username, loaded_password, loaded_email);

    }
    return 0;
}

//saves the database of loans in the specified file
//returns 0 if loans were stored correctly, or an error code otherwise
int store_loans(FILE *file) {
    file = fopen("loans.txt", "w");
    fprintf(file, "%i\n", loan_length);
    for (int i = 0; i < loan_length; i++)
    {
        fprintf(file, "%i\n%s\n%s\n%s\n", all_loans[i].ID,
                 all_loans[i].title, all_loans[i].authors, all_loans[i].user_id);
    }
    fclose(file);
    return 0;
}

//loads the database of loans from the specified file
//the file must have been generated by a previous call to store_loans()
//returns 0 if loans were loaded correctly, or an error code otherwise
int load_loans(FILE *file) {

    file = fopen("loans.txt", "r");
    if(file == NULL) {
        return 1;
    }

    int pre_length = 0;
    char str[49];
    fgets(str, 49, file);
    pre_length = atoi(str);
    for (int i = 0; i < pre_length; i++)
    {
        fgets(str, 49, file);
        ID_loaded = atoi(str);
        
        fgets(str, 49, file);
        str[strcspn(str, "\n")] = 0;
        strcpy(title_loaded = (char*)malloc(sizeof(str)), str);

        fgets(str, 49, file);
        str[strcspn(str, "\n")] = 0;
        strcpy(authors_loaded = (char*)malloc(sizeof(str)), str);

        fgets(str, 49, file);
        str[strcspn(str, "\n")] = 0;
        strcpy(user_id_loaded = (char*)malloc(sizeof(str)), str);

        add_loan(ID_loaded, title_loaded, authors_loaded, user_id_loaded);

    }
    return 0;
}
