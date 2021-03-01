
#ifndef BOOK_MANAGEMENT_GUARD__H 
#define BOOK_MANAGEMENT_GUARD__H

#include <stdio.h>

struct Book {
		char *title; //book title
		char *authors; //comma separated list of authors
		unsigned int year; // year of publication
		unsigned int copies; //number of copies the library has
};

struct BookArray {
	 struct Book* array; // pointer to array of struct Book.
	 unsigned int length; // number of elements in the struct Book * BookArray::find_book_by_author(const char* title)
};


struct BookArray all_books; //array of books in the library
struct BookArray borrowed_books; //array of borrowd books



//saves the database of books in the specified file
//returns 0 if books were stored correctly, or an error code otherwise
int store_books(FILE *file);

//loads the database of books from the specified file
//the file must have been generated by a previous call to store_books()
//returns 0 if books were loaded correctly, or an error code otherwise
int load_books(FILE *file);

//interface for adding book
//returns 0 if successful
int ready_add_book();

//adds a book to the ones available to the library
//returns 0 if the book could be added, or an error code otherwise
int add_book(struct Book book);

//removes a book from the library
//returns 0 if the book could be successfully removed, or an error code otherwise.
int remove_book(struct Book book);

// Remove book interface
void ready_remove_book();

//Display array of books
void display_book_array(struct BookArray results); 

//finds books with a given title.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
struct BookArray find_book_by_title (const char *title);

//finds books with the given authors.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
struct BookArray find_book_by_author (const char *author);

//finds books published in the given year.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
struct BookArray find_book_by_year (unsigned int year);

//Generally finding a book
// 0 if successful, 1 if not
int find_book();


#endif
