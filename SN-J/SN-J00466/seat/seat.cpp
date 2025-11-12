//SN-J00466  shiyihao  jinkaierzhong
#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int b=a[0];
    int c=0;
    sort(a,a+n*m);
    for(int i=n*m-1;i>=0;i++){
        c++;
        if(a[i]==b){
            break;
        }
    }
    int x,y;
    x=c/n+1;
    if(x%2==0){
        y=n-c%n;
    }else{
        y=c%n;
    }
    if(y==0&&x%2==0){
        x=x-1;
        y=n;
    }
    if(y==0&&x%2==1){
        x=x-1;
        y=1;
    }
    while(x>m){
    	x=x-m;
	}
    cout<<y<<" "<<x;
    return 0;
}

