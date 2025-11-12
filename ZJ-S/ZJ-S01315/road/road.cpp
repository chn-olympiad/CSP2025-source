#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e4+5;
ll n,m,k;
ll r[maxn][maxn];
ll c[12],a[12][maxn];
bool ci[maxn],flg[12],lu[12][maxn];
ll s = 1;
ll ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		if(!r[u][v]){
			r[u][v] = w;
			r[v][u] = w;
		}
		else {
			r[u][v] = min(r[u][v],w);
			r[v][u] = min(r[v][u],w);
		}
	}
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		for(int j = 1;j<=n;j++)
			cin>>a[i][j];
	}
	ci[1] = 1;
	while(s<n){
		ll p = INT_MAX,q;
		for(int i = 1;i<=n;i++)
			if(ci[i]){
				for(int j = 1;j<=n;j++)
					if(r[i][j] && r[i][j]<p && !ci[j]){
						p = r[i][j];
						q = j;
					}
				for(int j = 1;j<=k;j++){
					for(int t = 1;t<=n;t++){
						if(flg[j] && !ci[t] && !lu[j][i] && a[j][i]+a[j][t]<p){
							p = a[j][i]+a[j][t];
							q = t;
							lu[j][i] = 1;
							lu[j][t] = 1;
						}
						else if(flg[j] && !ci[t] && lu[j][i] && a[j][i]+a[j][t]<p){
							p = a[j][t];
							q = t;
							lu[j][t] = 1;
						}
						else if(!flg[j] && !ci[t] && c[j]+a[j][i]+a[j][t]<p){
							p = c[j]+a[j][i]+a[j][t];
							q = t;
							flg[j] = 1;
						}
					}
				}
			}
		ci[q] = 1;
		s++;
		ans+=p;
	}
	cout<<ans;
	return 0;
}