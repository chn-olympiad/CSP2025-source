#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[1000010];
    string s;
    int x=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]<'a'){
            a[x]=s[i];
            x++;
        }
    }
    sort(a,a+x);
    for(int i=x-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
