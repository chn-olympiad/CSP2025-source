#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size(),n2=0;
    for(int i=0;i<n;i++){
        if(s[i]>='1'&&s[i]<='9'){
                a[i]+=(int(s[i])-48);
        }
        if(s[i]=='0'){
            n2++;
        }
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        if(a[i]!=0){
            cout<<a[i];
        }
    }
    for(int i=1;i<=n2;i++){
        cout<<0;
    }
    return 0;
}
