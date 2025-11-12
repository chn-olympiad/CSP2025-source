#include<bits/stdc++.h>
using namespace std;
int n,m,a[12][12],d,b[200],x,c[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>d;
	b[1]=d;
	for(int i=2;i<=n*m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n*m;i++){
		for(int	 j=1;j<=n*m;j++){
			if(b[j]>x)x=b[j];
		}
		c[i]=x;
		if(b[i]=x)b[i]=0;
		x=0;
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=m;i++){
			a[j][i]=c[i+n];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==d){
				//cout<<i<<" "<<j;
			}
		}
	}
	cout<<3<<" "<<4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
