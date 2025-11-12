#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int a1,p=0,x,y,h,l;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    a1=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a1==a[i]){
            p=i;
        }
    }
    x=p/n;
    y=p%n;
    if(y){
        l=x+1;
        if(l%2){
            h=y;
        }else {
            h=n-y+1;
        }
    }
    else{
        l=x;
        if(l%2){
            h=n;
        }else {
            h=1;
        }
    }
    cout<<l<<" "<<h;
	return 0;
}
