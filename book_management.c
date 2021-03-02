#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "register_login.h"

struct BookArray all_books = {0, 0}; //array of all books
struct Book loaded_book;
// getting ready to add books
//returns 0 if successful
int ready_add_book() {

    char* title;
    char* author;
    char* copies_str;
    char* year_str;

    title = ask_question("Enter the title of the book you wish to add: ");  
    author = ask_question("Enter the author of the book you wish to add: "); 
    copies_str = ask_question("Enter the number of copies of the book that you wish to add: ");
    year_str = ask_question("Enter the year the book was written: ");  

    printf("\n");

    //check for correct author
    if (atoi(author))
    {
        printf("Please enter a valid author.\n\n");
        return 1;
    }
    

    //check for corret number of copies
    if(!atoi(copies_str)) 
    {
        printf("Please enter an integer value for the number of copies.\n\n");
        return 1;
    }
    //check for correct year (4 digits)
    else
    {
        if (!atoi(year_str) || strlen(year_str) != 4)
        {
            printf("Please enter a valid year.\n\n");
            return 1;
        }
        else
        {
            struct Book book;
            book.authors = author;
            book.copies = atoi(copies_str);
            book.title = title;
            book.year = atoi(year_str);
            add_book(book);

            printf("Your book was added successfully\n\n");            

            return 0;
        }
    }
}

// adding books
//return 0 if completed
int add_book(struct Book book) {
    all_books.array = realloc(all_books.array, (all_books.length + 1) * sizeof(struct Book));
    all_books.array[all_books.length] = book;
    
    
    all_books.length++;
    // for (int i = 0; i < all_books.length; i++)
    // {
    //     printf("%s\n", all_books.array[all_books.length].title);
    // }
    return 0;
}



// Find book
// return null if does not find anything
int find_book() {
    struct BookArray searched_books_list;
    while (1)
    {

        printf("Please choose an option:\n");
        printf("1) Find books by title\n");
        printf("2) Find books by author\n");
        printf("3) Find books by year\n");
        printf("4) Return to previous menu\n");
        printf(" Option: ");

        // Evaluationg the option
        static int option;
        scanf("%d", &option);
        printf("\n");

        //Find by title
        if (option == 1)
        {
            option = 0;
            while ((getchar()) != '\n');
            
            //Find by title
            char* title;
            title = ask_question("Please eneter title: ");
            printf("\n");
            searched_books_list = find_book_by_title(title);
            if (searched_books_list.length == 0)
            {
                printf("Did not find any books!\n\n");
            }
            else
            {
                display_book_array(searched_books_list);
            }
            return 0;
            
        }

        ////find by author
        else if (option ==2)
        {
            option = 0;
            while ((getchar()) != '\n');
            //find by author
            char* author;
            author = ask_question("Please eneter author: ");
            printf("\n");
            searched_books_list = find_book_by_author(author);
            if (searched_books_list.length == 0)
            {
                printf("Did not find any books!\n\n");
            }
            else
            {
                display_book_array(searched_books_list);
            }
            
            return 0;
        }
        //Find by year
        else if (option ==3)
        {
            option = 0;
            while ((getchar()) != '\n');
            //Find by year
            char* year;
            year = ask_question("Please eneter year: ");
            printf("\n");
            searched_books_list = find_book_by_year(atoi(year));
            if (searched_books_list.length == 0)
            {
                printf("Did not find any books!\n\n");
            }
            else
            {
                display_book_array(searched_books_list);
            }
            
            return 0;
        }
        //returning back
        else if (option == 4)
        {
            option = 0;
            while ((getchar()) != '\n');
            printf("Returning to previous menu...\n\n");
            return 0;
        }
        else
        {
            printf("Sorry, the option you entered was invalid, please try again.\n");
            printf("\n");
            while ((getchar()) != '\n'); 
        }
    }
    return 0;
}




struct BookArray find_book_by_title (const char *title) {
    struct BookArray searched_books;
    searched_books.array = (struct Book* ) malloc(sizeof(struct Book));;
    searched_books.length = 0;

    for (int i = 0; i < all_books.length; i++)
    {
        if (!strcmp(all_books.array[i].title, title))
        {
            searched_books.array = realloc(searched_books.array, (searched_books.length + 1) * sizeof(struct Book));
            searched_books.array[searched_books.length] = all_books.array[i];
            searched_books.length++;
        }
    }
    return searched_books;  
}

struct BookArray find_book_by_author (const char *author) {
    struct BookArray searched_books;
    searched_books.array = (struct Book* ) malloc(sizeof(struct Book));;
    searched_books.length = 0;

    for (int i = 0; i < all_books.length; i++)
    {
        if (!strcmp(all_books.array[i].authors, author))
        {
            searched_books.array = realloc(searched_books.array, (searched_books.length + 1) * sizeof(struct Book));
            searched_books.array[searched_books.length] = all_books.array[i];
            searched_books.length++;
        }
    }
    return searched_books;  
}

struct BookArray find_book_by_year (unsigned int year) {
    struct BookArray searched_books;
    searched_books.array = (struct Book* ) malloc(sizeof(struct Book));;
    searched_books.length = 0;

    for (int i = 0; i < all_books.length; i++)
    {
        if (all_books.array[i].year == year)
        {
            searched_books.array = realloc(searched_books.array, (searched_books.length + 1) * sizeof(struct Book));
            searched_books.array[searched_books.length] = all_books.array[i];
            searched_books.length++;
        }
    }
    return searched_books;  
}


// Display array of books
void display_book_array(struct BookArray results) {
    printf("Id\tTitle\t\t\t\t\tAuthors\t\t\t\t\tYear\tCopies \n");
    for (int i = 0; i < results.length; i++)
    {
        printf("%i\t%-32s\t%-32s\t%i\t%i \n", i, results.array[i].title, results.array[i].authors,
                                        results.array[i].year, results.array[i].copies);
    }
    printf("\n");
}


// Interface for removing a book
void ready_remove_book() {
    display_book_array(all_books);
    char* ID;
    char* n_copies;

    //input the id
    ID = ask_question("Enter the Id of the book you wish to remove: ");
    n_copies = ask_question("Enter the number of copies you wish to remove: ");

    if (!atoi(n_copies))
    {
        printf("The number of copies is invalid!\n\n");
    }
    else
    {
        if (atoi(n_copies) > all_books.array[atoi(ID)].copies)
        {
            printf("There is not enough copies of this book in the library.\n\n");
        }
        else
        {
            for (int i = 0; i < atoi(n_copies); i++)
            {
                remove_book(all_books.array[atoi(ID)]);
            }
            printf("%s copies of the book were removed.\n\n", n_copies);
            
        }
        
        
    }
    
    

}


// removes a number of copy of book
int remove_book(struct Book book) {

    for (int i = 0; i < all_books.length; i++)
    {
        if ((!strcmp(book.title, all_books.array[i].title)) && (!strcmp(book.authors, all_books.array[i].authors)))
        {
            if (all_books.array[i].copies > 0)
            {
                all_books.array[i].copies--;
                return 0;
            }
            
        }
        
    }
    return 1;
}

//saves the database of books in the specified file
//returns 0 if books were stored correctly, or an error code otherwise
int store_books(FILE *file) {

    file = fopen("books.txt", "w");
    fprintf(file, "%i\n", all_books.length);
    for (int i = 0; i < all_books.length; i++)
    {
        fprintf(file, "%s\n%s\n%i\n%i\n", all_books.array[i].title,
                 all_books.array[i].authors, all_books.array[i].year, all_books.array[i].copies);
    }
    fclose(file);


    return 0;
    
}

//loads the database of books from the specified file
//the file must have been generated by a previous call to store_books()
//returns 0 if books were loaded correctly, or an error code otherwise
int load_books(FILE *file) {

    file = fopen("books.txt", "r");
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
        strcpy(loaded_book.title = (char*)malloc(sizeof(str)), str);
        
        fgets(str, 49, file);
        str[strcspn(str, "\n")] = 0;
        strcpy(loaded_book.authors = (char*)malloc(sizeof(str)), str);

        fgets(str, 49, file);
        loaded_book.year = atoi(str);

        fgets(str, 49, file);
        loaded_book.copies = atoi(str);

        add_book(loaded_book);

    }


    return 0;

    
}