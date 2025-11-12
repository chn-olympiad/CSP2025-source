#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[1000];
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int xr=b[1];
	sort(b+1,b+n*m+1);
	int bh=n*m;
	for(int j=1;j<=m;j++){
		for(int k=1;k<=n;k++){
			a[j][k]=b[bh];
			bh--;
		}
	}
	for(int j=1;j<=m;j++){
		for(int k=1;k<=n;k++){
			if(a[j][k]==xr)cout<<j<<" "<<k;
		}
	}
	return 0;
}
