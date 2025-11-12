#include <bits/stdc++.h>
using mamespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int b[101]={};
    int n,m,w;
    cin>>n>>m;
    cin>>w;
    b[0]=w;
    for(int i=1;i<n*m;i++){
        cin>>b[i];
    }
    sort(b+1,b+n*m+1)
    for(int i=0;i<m*n;i++){
        if(b[i]==w){
            w=n*m-i;
        }
    }
    int x,y;
    x=w/m+1;
    cout<<x<<" ";
    if(x/2==0){
        y=m-w%m+1;}
    else{
        y=w%(m+1);
    }
    cout<<y;
    return 0;
}
