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