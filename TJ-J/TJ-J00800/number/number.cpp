#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long number[1000000]={0},cont=0;
    for(long long i=0;i<=s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            number[cont]=s[i]-48;
            cont++;
        }
    }
    sort(number,number+cont,cmp);
    for(long long i=0;i<cont;i++){
        cout<<number[i];
    }
    return 0;
}
