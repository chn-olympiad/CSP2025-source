#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	int b[n+1][m+1];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[0];
	sort(a,a+n*m);
	int c[m*n];
	for(int i=0;i<m*n;i++){
		c[i]=a[m*n-i-1];
	}
	int u=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(c[u]==r){
					cout<<j<<" "<<i;
					return 0;
				}
				b[j][i]=c[u];
				u++;
			}
			
		}else{
			for(int j=n;j>0;j--){
				if(c[u]==r){
					cout<<j<<" "<<i;
					return 0;
				}
				b[j][i]=c[u];
				u++;
			}
		}
	}
	return 0;
}
