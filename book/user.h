

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


struct User{
	string userId;
	string password;
};

class UserList{
private:
	
	
public:
	vector<User> users;
	UserList();
	bool search(string userId,string password);
};
