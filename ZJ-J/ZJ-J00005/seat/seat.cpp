#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a,b[N],c[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		if(i==1) a=b[i];
	}
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a==b[i]) a=n*m-i+1;
	}
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			c[j][i]=(i-1)*n+j;
		}
	}
	for(int i=2;i<=m;i+=2){
		for(int j=n;j>=1;j--){
			c[j][i]=(i-1)*n+(n-j+1);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]==a){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
