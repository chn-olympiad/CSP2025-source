#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int c=0;
    cin>>s;
    for(int i=0;i<=s.length();i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[c]=s[i];
            c++;
        }
    }
    sort(a,a+c);
    for(int i=c;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
