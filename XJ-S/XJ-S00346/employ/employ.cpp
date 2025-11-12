#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int M=1e5+5;
int n,m,k;
int u[N],v[N],w[N];
int a[M],b[M],aa[11][M];
int dfs(int k){
	int x=INT_MAX,s=0,sum=0;
	if(s==1)
		return sum;
	for(int i=1;i<=n;i++){
		if(u[i]==k&&x>w[i]){
			x=w[i];
			s=v[i];
			w[i]=INT_MAX;
		}
		if(v[i]==k&&x>w[i]){
			x=w[i];
			s=u[i];
			w[i]=INT_MAX;
		}
	}
	sum+=x;
	dfs(s);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(int j=1;j<=k;j++)
		for(int q=0;q<=n;q++)cin>>aa[j][q];
	cout<<dfs(1);
	return 0;
}

