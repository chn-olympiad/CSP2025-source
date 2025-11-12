#include<bits/stdc++.h>
using namespace std;
int a[150];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int x;
    scanf("%d",&x);
    a[1]=x;
    for(int i=2;i<=n*m;i++){
        scanf("%d",&a[i]);
    }sort(a+1,a+1+n*m);
    int c,r;
    for(int j=n*m;j>=1;j--){
    	int i=n*m-j;
        if(x==a[j]){
            c=i/n+1;
            if(c&1){
                r=i%n+1;
            }else{
                r=n-(i%n);
            }
			break;
        }
    }printf("%d %d",c,r);
    return 0;
}
