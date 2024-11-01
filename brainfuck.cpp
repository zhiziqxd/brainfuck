#include <bits/stdc++.h>
using namespace std;
map<int,int> value;
int ptr;
string str;
bool flag;
char input(){
    char a;
    cin>>a;
    return a-'0';
}
void run(char ch){
    switch(ch){
        case '>':
        ptr++;
        case '<':
        ptr--;
        case '+':
        value[ptr]++;
        case '-':
        value[ptr]--;
        case '.':
        cout<<char(value[ptr]);
        case ',':
        value[ptr]=input();
        case ']':
        flag=true;
    }
    return;
}
int main(){
    freopen("bf.txt","r",stdin);
    while(cin>>str){
        for(int i=0;i<str.length();i++){
            run(str[i]);
            if(flag&&value[ptr]){
                int cnt=0;
                for(int j=i-1;j>=0;j--){
                    if(str[j]=='['&&cnt==0){
                        i=j+1;
                        break;
                    }
                    if(str[j]=='['&&cnt!=0){
                        cnt--;
                    }
                    if(str[j]==']'){
                        cnt++;
                    }
                }
                if(cnt!=0){
                    cout<<"error";
                    return 0;
                }
            }
        }
    }
    return 0;
}
