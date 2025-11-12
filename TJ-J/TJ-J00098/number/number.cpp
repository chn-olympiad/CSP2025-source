#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int b[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;int n=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9')b[n++]=a[i]-'0';
    }sort(b,b+n);
    for(int i=n-1;i>=0;i--)printf("%d",b[i]);
    return 0;
}
