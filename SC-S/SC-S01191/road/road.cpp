#include<bits/stdc++.h> 
using namespace std;
long long n,m,k,u[1000100],v[1000100],w[1000100],c[20],a[20][10010],num;
long long s[10101][10100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		s[u[i]][v[i]]=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[c[i]][j];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			for(int q=1;q<=k;q++)
				s[i][j]=min((a[q][i]+a[q][j]+c[q]),s[i][j]);
			num+=s[i][j]; 
		}
	}
	cout<<num;
	return 0;
}