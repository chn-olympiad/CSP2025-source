#include<bits/stdc++.h>
using namespace std;
int n,m,thanr,c,r,cr;
int a[150];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        if(a[i]>a[0]){
            thanr++;
        }
    }
    c=thanr/n+1;
    cr=thanr-(c-1)*n+1;
    if(c%2==1){
        r=cr;
    }else{
        r=n-cr+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
