#include<bits/stdc++.h>
#define ll long long 
#define inf 1e9
using namespace std;
//const int inf=1e9;
const int N=1e4+5;
const int M=1e6+5;
const int K=15;
int n,m,k;
vector<vector<ll> >mp(N+K+1,vector<ll>(N+K+1,-1));
vector<vector<ll> >as(N+K+1,vector<ll>(N+K+1,inf));
vector<ll>c(N+K+1);
ll dj(int start){
	ll ans=0;
	vector<vector<ll> >as=mp;
	vector<ll>dis(N+K+1,inf);
	vector<bool>vis(N+K+1,0);
	dis[start]=0;
	for(int q=n-1;q>=1;q--){
		int now=inf;
		for(int i=1;i<=n;i++){
			if(dis[i]!=inf)now=min(now,i);
		}
		for(int i=1;i<=n;i++){
			if(as[now][i]!=-1){
				ans-=dis[i];
				dis[i]=min(dis[i],dis[now]+mp[now][i]);
				ans+=dis[i];
				mp[start][i]=0;
			}
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ll u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		mp[u][v]=mp[v][u]=w;
		int minn=min(u,v),maxn=max(u,v);
		as[minn][maxn]=min(as[minn][maxn],w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>mp[n+i][j];
			mp[j][n+i]=mp[n+i][j];
			for(int k=1;k<=j-1;k++){
				as[k][j]=min(as[k][j],mp[k][n+i]+mp[j][n+i]+c[i]);
			} 
		}
	}
	ll cnt=0,ans=inf;
	for(int i=1;i<=n;i++){
		cnt+=n*n;
		if(cnt>1e8)break;
		ans=min(ans,dj(i));
	}
	cout<<ans<<"\n";
	return 0;
}
/*
16:10 开始做题。
16:46 一点思路都没有。 
16:58 决定写特殊性质A。 
17:27 没写出来，样例都没过。╥﹏╥... 
	感觉这题要爆零了 
*/

/*
总结：
A题(club)可能有部分分；
B题(road)暴力都不会； 
C题(replace)暴力没调完； 
D题(employ)特殊性质A应该能过； 
应该不会爆零了。
2025.11.1
*/
