#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M1 10005
#define M2 1000005
#define M3 15
int n,m,k;
ll c[M3][M1];
int vis[1005][1005];
struct Edge{
	ll u,v,w;
};
int ct;
Edge e[2*M2];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int s[M1];
int find(int x){
	return (s[x]==x)?x:s[x]=find(s[x]);
}
int main(void){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		e[++ct]=Edge{x,y,z};
	}
	bool flag=true;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
			if(j==0)if(c[i][j]!=0)flag=false;
		}
	}
	if(flag){
		if(k>0){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					for(int kk=1;kk<=k;kk++){
						if(vis[i][j]==0||vis[i][j]>c[kk][i]+c[kk][j]){
							vis[i][j]=c[kk][i]+c[kk][j];
						}
					}
					e[++ct]=Edge{i,j,vis[i][j]};
				}	
			}	
		}
		sort(e+1,e+1+ct,cmp);
		ll ans=0;
		for(int i=1;i<=n;i++)s[i]=i;
		for(int i=1;i<=ct;i++){
			int x=e[i].u,y=e[i].v,z=e[i].w;
			if(find(x)!=find(y)){
				ans+=z;
				s[find(x)]=s[find(y)];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
