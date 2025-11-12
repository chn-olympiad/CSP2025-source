#include<bits/stdc++.h>
using namespace std;
int a[130];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string x;
    cin>>x;
    int n=x.size();
    for(int i=0;i<n;i++){
        a[x[i]]++;
    }bool z=1;
    for(int i='9';i>'0';i--){
        while(a[i]--){
            cout<<(i^48);
            z=0;
        }
    }if(z)a[48]=1;
    while(a[48]--) cout<<0;
    return 0;
}
