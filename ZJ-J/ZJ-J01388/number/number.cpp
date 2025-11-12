#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using namespace std;
int a[1000010],top;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(isdigit(str[i])){
            a[++top]=str[i]-'0';
        }
    }
    sort(a+1,a+top+1,cmp);
    for(int i=1;i<=top;i++){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
//AFO.
//OK 100 pts ^_^