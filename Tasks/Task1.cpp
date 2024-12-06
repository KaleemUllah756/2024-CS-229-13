#include <iostream>
#include <fstream>
using namespace std;
void getbirthdaycake(){

fstream file;
file.open("names.txt", ios::in);

string name;
int age;
getline(file,name,',');
file>>age;
file.close();
file.open("output.txt", ios::out);

if(age%2==0){
  file<<"################"<<endl;
  file<<"# "<<age<< " HB "<<name<<"! "<<age<<" #"<<endl;
  file<<"################"<<endl;
}else{
  file<<"****************"<<endl;
  file<<"* "<<age<<" HB "<<name<<"! "<<age<<" *"<<endl;
  file<<"****************"<<endl;
}
file.close();

}
int main(){
  getbirthdaycake();
  return 0;
}