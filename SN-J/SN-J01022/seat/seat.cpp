#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],s=0,p;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int l=1;l<=m;l++){
			cin>>a[s];
			s++;
		}
	}
	int big=0,x[n][m];
	for(int i=0;i<n*m;i++){
		big=0;
		for(int l=0;l<n*m;l++){
			if(a[l]>big){
				big=a[l];
				p=l;
			}
		}
		a[p]=0-1;
		for(int j=1;j<n;j++){
			for(int t=1;t<m;t++){
				if(j%2!=0) x[0+j][0+t]=big;
				else x[0+j][4-t]=big;
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int l=1;l<m;l++){
			if(x[n][m]==a[0]) cout<<i<<' '<<l;
		}
	}
	return 0;
}
