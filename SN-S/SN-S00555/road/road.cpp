#include<bits/stdc++.h>
using namespace std;
const int N=10001;
int u[N],v[N],w[N];
int n,m,k;
int a[N][N],c[N];
int sum=0,num=0,ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			 cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum=w[i]+u[i]+v[i];
			if(a[i][j]){
				num=c[j]+a[j][n];
			}
			ans=min(ans,sum+num);
		}
	}
	cout<<ans;
	
	return 0;
} 
