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