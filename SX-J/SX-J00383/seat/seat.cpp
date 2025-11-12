#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,f,b[105][105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
	}
	t=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(t==a[i]){
        	f=i;
		}
	}
    int x=2*n-1;
    int y=1;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
            if(j==1){
            	b[i][j]=i;
			}else{
                b[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
		   if(i%2==1){
              b[i][j]=b[i][j-1]+x;
		   }else{
		   	  b[i][j]=b[i][j-1]+y;
		   }
		   x-=2;
		   y+=2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f==b[i][j]){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}