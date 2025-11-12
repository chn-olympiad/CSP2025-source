#include<bits/stdc++.h>
using namespace std;
int n,m,f[11][11],i,j,r,a[105];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>r;
    a[1]=r;
    for(i=2;i<=n*m;i++)
      cin>>a[i];
    sort(a+1,a+n*m+1,cmp);
    int x=1;
    for(i=1;i<=m;i++){
    	if(i%2==1){
    		for(j=1;j<=n;j++){
    		  f[i][j]=a[x];
    		  x++;
    	    }
		}
		else{
			for(j=n;j>=1;j--){
				f[i][j]=a[x];
				x++;
			}
		}
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(f[i][j]==r){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
