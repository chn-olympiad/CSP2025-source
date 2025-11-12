#include<bits/stdc++.h>
using namespace std;
string a,s;
int n[(int)1e6+10];
bool cmp(int a,int b) {
    return a>b;
}
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.length();i++) { // delete a-z
        if(a[i]<='9'&&a[i]>='0') {
            s+=a[i];
        }
    }
    for(int i=0;i<s.length();i++) { //
        n[i]=s[i]-'0';
    }
    sort(n,n+s.length(),cmp);

    for(int i=0;i<s.length();i++) {
        cout<<n[i];
        if(i==0&&n[i]==0) return 0;
    }
    return 0;
}
