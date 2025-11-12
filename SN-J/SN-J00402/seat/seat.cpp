#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[15][15],n,m,b[105],c,r;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n*m;i++){
		cin>>b[i];
	}
	for(int i=0;i<=n*m;i++){
		if(b[i]<b[i+1]){
			b[i]=b[i+1];
		}
	}
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			a[i][j]=b[i];
			c=i;
			r=j;
		}
		cout<<c<<" "<<r;
	}
	return 0;
}
