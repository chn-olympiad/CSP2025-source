#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,mu,mv,ti;
long long ans;
long long mw;
long long u[1500000],v[1500000],w[1500000],t[15],fa[10005],vis[1500000];
int fin(int x){
	if(fa[x]==x)return x;
	else return fa[x]=fin(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
		cnt++;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++){
		cin>>t[i];
		for(int j=1;j<=n;j++){
			cin>>w[cnt];
			u[cnt]=i;
			v[cnt]=j;
			cnt++;
		}
		ans+=t[i];
	}
	int cntt=0;
	while(cntt<(n-1)){
		mw=1000000005;
		for(int i=0;i<cnt;i++){
			if(mw>w[i]&&(fin(u[i])==fin(v[i]))==0&&vis[i]==0){
				mu=u[i];
				mv=v[i];
				mw=w[i];
				ti=i;
			}
		}
		vis[ti]=1;
		ans+=w[mw];
		cntt++;
		fa[mv]=fa[mu];
	}
	cout<<ans;
	return 0;
}