//Task1

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

//Task2

#include <iostream>
#include <fstream>
using namespace std;
void missingletters(){
fstream file;
file.open("alphabets.txt", ios::in);
string input;
getline(file, input);
file.close();
bool present[26]={false};
for(char c : input){
    if(c>='a' && c<='z'){
        present[c-'a']=true;
    }
}
string missingletters="";
for(char c ='a'; c<='z'; ++c){
    if(!present[c-'a']){
        missingletters=missingletters+c;
    }
}
file.open("alphabets.txt", ios::app);
if(missingletters.empty()){
    file<<endl;
}else{
    file<<missingletters<<endl;
}
file.close();



}
int main(){
missingletters();
return 0;




}

//Task3
#include <iostream>
#include <fstream>
using namespace std;
void converttomorse(string input, fstream& outputfile){
    string morsecode[27]={
           ".-", "-...", "-.-","-..",".","..-.","--.","....","..",".---",
           "-.-",".-..","--","---",".--.","--.-",".-.","...","-",
           "..-","...-",".--","-..-","-.--","--.."," "};

      for(int i=0; i<input.length(); i++){
       char c=input[i];
       if(c>='A' && c<='Z'){
        outputfile<<morsecode[c-'A']<<" ";
       }else if(c>= 'a' && c<= 'z'){
        outputfile<<morsecode[c-'a']<<" ";
       }else if(c==' '){
        outputfile<<morsecode[26];
       }


      }     
}
int main(){
fstream inputfile("input.txt", ios::in);
fstream outputfile("output.txt", ios::out);

string line;
while(getline(inputfile,line)){
    converttomorse(line, outputfile);
    outputfile<<endl;
}
inputfile.close();
outputfile.close();

return 0;

}