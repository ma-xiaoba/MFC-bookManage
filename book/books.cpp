#include "stdafx.h"
#include "books.h"

map<int,Book> BookList::books;

BookList::BookList(){
	
	if(books.empty()){
		ifstream infile; 
		infile.open("book.dat");

		Book book;
		while(infile>>book.id>>book.name>>book.number){
			books.insert(pair<int, Book>(book.id,book));
		}
		infile.close();
	}
}

BookList::~BookList(){
	ofstream outfile ("book.dat", ofstream::out | ios_base::trunc);
	
	map<int, Book>::iterator iter;
	for(iter = books.begin(); iter != books.end();iter++){
		outfile<<iter->second.id<<"\t"<<iter->second.name<<"\t"<<iter->second.number<<"\n";
	}
	outfile.close();
}

Book BookList::search(int id){
	
	if(books.count(id)==1)
		return books[id];
	else{ 

		Book b;
		b.id=0;
		return b;
	}
}
void BookList::addBook(Book book){
	
	for(int id=10000;;id++){
		if(books.count(id)==0){
			book.id=id;
			books.insert(pair<int, Book>(book.id,book));
			break;
		}
	}
}
void BookList::deleteBook(int id){
	books.erase(id);
}
void BookList::updateBook(Book book){
	
	if(books.count(book.id)==1)
		books[book.id]=book;
}
map<int,Book> BookList::showAll(){
	return books;
}