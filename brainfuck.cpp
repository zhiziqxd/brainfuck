#include <bits/stdc++.h>
using namespace std;
char *ptr;
string str;
bool f_while,flag;
int start;
char input(){
    char a;
    cin>>a;
    return a;
}
void run(char ch,int x){
    if(ch==']'){
        flag=true;
        return;
    }
    switch(ch){
        case '>':
        ptr++;
        case '<':
        ptr--;
        case '+':
        *ptr++;
        case '-':
        *ptr--;
        case '.':
        cout<<char(*ptr);
        case ',':
        *ptr=input();
        case '[':
        f_while=true;
        start=x;
    }
    return;
}
int main(){
    freopen("bf.txt","r",stdin);
    while(cin>>str){
        for(int i=0;i<str.length();i++){
            run(str[i],i);
            if(f_while&&flag&&!(*ptr)){
                f_while=false;
                flag=false;
            }
            if(f_while&&flag&&(*ptr)){
                i=start+1;
            }
        }
    }
    return 0;
}
