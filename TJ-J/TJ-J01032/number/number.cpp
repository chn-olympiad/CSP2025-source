#include<bits/stdc++.h>
using namespace std;
long long a=0,b,c,d,e[1000005];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]-'0'>=0&&s[i]-'0'<=9){
            e[a]=s[i]-'0';
            a++;
        }
    }
    sort(e,e+a);
    for(int i=a-1;i>=0;i--){
        cout<<e[i];
    }
    return 0;
}
