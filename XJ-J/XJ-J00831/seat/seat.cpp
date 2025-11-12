#include"bits/stdc++.h"
using namespace std;
sxxt(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int x=a*b;
    int f[a][b];
    int boom[x];
    for(int i=1;i<=x;i++){
        cin>>boom[i];
    }int flag=1,n=1,fxxk=boom[1];
    sort(boom+1,boom+x+1,sxxt);
    for(int j=1;j<=b;j++){
        if(flag==1){
            for(int i=1;i<=a;i++){
                f[i][j]=boom[n];
                n=n+1;
            }
            flag=2;
        }else{
            for(int i=a;i>=1;i--){
                f[i][j]=boom[n];
                n=n+1;
            }
            flag=1;
        }
    }for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(f[i][j]==fxxk){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
}
