#include<iostream>
using namespace std;
int main(){
    char ch;
    cout<<"Ente the desired character required"<<endl;
    cin>>ch;
    cout<<"We eill be checking for both th cases of vowel s of uppercase and lowercase as well along with th epossibilities of encountering with other consonants as well "<<endl;
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
        cout<<"The enterd character is a vowl of a lower case";
    }
    else if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
        cout<<"Enered character is  a  characater of uppecase "<<endl;
    }
    else{
        cout<<"Enterd charcter is  a consonant";
    }
    return 0;
}
