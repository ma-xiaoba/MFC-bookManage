
#include "stdafx.h"
#include "user.h"


UserList::UserList(){
	
   // 以读模式打开文件
	if(users.empty()){
		ifstream infile; 
		infile.open("user.dat");

		User user;
		while(infile>>user.userId>>user.password){
			
			users.push_back(user);
	   }
	   infile.close();
	}

}

bool UserList::search(string userId,string password){

	for(int i=0;i<users.size();i++){
		if(users[i].password.compare(password)==0 && users[i].userId.compare(userId)==0)
			return true;
	}
	return false;
}