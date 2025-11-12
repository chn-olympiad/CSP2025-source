#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[105],b[15][15],c[15][15];
int x;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	int f=n,y=n*m;
	while(f){
		if((n-f)%2==0){
			for(int i=m;i>0;i--){
				b[f][i]=a[y];
				y--;
			}
		}
		else{
			for(int i=1;i<=m;i++){
				b[f][i]=a[y];
				y--;
			}
		}
		f--;
		if(f==0){
			break;
		}
	}
	for(int i=n;i>0;i--){
		for(int j=m;j>0;j--){
			c[n-i+1][m-j+1]=b[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(c[i][j]==x){
				cout<<i<<' '<<j;
			}
		}
	}
	return 0;
}
