#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
int n,m,k;
int vis[100005],f[1000005],t[1000005],v[10000005];
int c[15][100005];
int cnt=0,idx=1,temp[1000005],ans=0x3f3f3f3f,maxx,visc[15];
int flag=0;
void dfs(int i) {
	if(flag==1) {
		return ;
	}
	if(ans>cnt-maxx) {
		ans=cnt;
	}
	if(vis[f[i]]<2&&vis[t[i]]<2) {
		vis[f[i]]++;
		cnt+=v[i];
		vis[t[i]]++;
		maxx=max(v[i],maxx);
		dfs(i+1);
		vis[f[i]]--;
		cnt-=v[i];
		vis[t[i]]--;
		for(int j=1; j<=n; j++) {
			if(visc[j]==0&&vis[j]<2&&vis[t[i]]<2) {
				visc[j]=1;
				cnt+=c[j][0];
				cnt+=c[j][t[i]];
				vis[j]++;
				vis[t[i]]++;
				dfs(i+1);
				if(flag==1) {
					return ;
				}
				visc[j]=0;
				vis[j]--;
				vis[t[i]]--;
				cnt-=c[j][0];
				cnt-=c[j][t[i]];
			} else {
				if(vis[j]<2&&vis[t[i]]<2) {
					cnt+=c[j][0];
					cnt+=c[j][t[i]];
					vis[j]++;
					vis[t[i]]++;
					dfs(i+1);
					if(flag==1) {
						return ;
					}
					vis[j]--;
					vis[t[i]]--;
					cnt-=c[j][0];
					cnt-=c[j][t[i]];
				}
			}
		}
	}
	flag=1;
	return ;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>f[i]>>t[i]>>v[i];
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i][0];
		for(int j=1; j<=n; j++) {
			cin>>c[i][j];
		}
	}
	for(int i=1; i<=n; i++) {
		dfs(i);
	}
	cout<<ans;
	return 0;
}

