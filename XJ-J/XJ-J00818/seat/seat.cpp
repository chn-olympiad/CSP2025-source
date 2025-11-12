#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int c,r;
    int n,m;
    cin>>n>>m;
    char a[101];
    cin>>a;
    if(100-a[0]+1<n){
        c=1;
        r=100-a[0]+1;
        cout<<c<<" "<<r;
    }
    if(100-a[0]+1>n and 100-a[0]+1<m){
        c=100-a[0]+1-n+1;
        r=100-a[0]+1;
        cout<<c<<" "<<r;
    }
    if(100-a[0]+1>n and 100-a[0]+1>m){
        c=100-a[0]+1-n+1;
        r=100-a[0]+1-n+1-m;
        cout<<c<<" "<<r;
    }

    return 0;
}
