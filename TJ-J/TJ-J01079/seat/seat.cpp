#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans,r,c;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	} 
	ans=b[1];
	sort(b+1,b+n*m+1); 
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			if(j%2!=0)a[m-j][n-i]=b[n*m-i*j+j];
			if(j%2==0)a[j][i]=b[n*m-i*j+j];
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			if(a[i][j]==ans){
				c=j;
				r=i;
				break;
			}else continue;
		}
	}
	cout<<c<<" "<<r;
	return 0;
} 
