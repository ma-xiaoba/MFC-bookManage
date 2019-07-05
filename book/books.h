#ifndef BOOKLIST_H
#define BOOKLIST_H

#include<iostream>
#include<fstream>
#include<string>
#include <map>

using namespace std;

struct Book{
	public:
	int id;
	string name;
	int number;
};

class BookList{

private: 
	//这里只是声明，没有定义
	
public:
	static int a;
	static map<int,Book> books;
	BookList();
	~BookList();
	Book search(int);
	void addBook(Book);
	void deleteBook(int);
	void updateBook(Book);
	map<int,Book> showAll();
};

#endif