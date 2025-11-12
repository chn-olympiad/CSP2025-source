#include<bits/stdc++.h>
using namespace std;
int n,m,k,s[11][10100],c[11],a[1010][1010],f[10100];
long long ans,sum=1e18;
struct node {
	int u,v,w;
};
vector<node>e,e1;
bool cmp(node a,node b) {
	return a.w<b.w;
}
int getfa(int x) {
	if(f[x]==x)return x;
	else return f[x]=getfa(f[x]);
}
void merge(int x,int y) {
	x=getfa(x),y=getfa(y);
	if(x!=y)f[x]=y;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,0x3f,sizeof(a));
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back(node {u,v,w});
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>s[i][j];
		}
	}
	for(int i=0; i<=pow(2,k)-1; i++) {
		ans=0;
		e1=e;
		for(int j=1; j<=n; j++) {
			for(int h=1; h<=n; h++) {
				a[j][h]=1e9+7;
			}
		}
		for(int j=1; j<=k; j++) {
			if((i/(int)pow(2,j-1))%2) {
				ans+=c[j];
				for(int h=1; h<=n; h++) {
					for(int o=h+1; o<=n; o++) {
						a[h][o]=min(a[h][o],s[j][h]+s[j][o]);
					}
				}
			}
		}	
		for(int j=1; j<=n; j++) {
			for(int h=j+1; h<=n; h++) {
				if(a[j][h]!=1e9+7)e1.push_back(node {j,h,a[j][h]});
			}
		}
		sort(e1.begin(),e1.end(),cmp);
		for(int j=1; j<=n; j++)f[j]=j;
		int oz=0;
		for(int j=0; j<e1.size()&&oz<n-1; j++) {
			if(getfa(e1[j].u)!=getfa(e1[j].v)) {
				ans+=e1[j].w;
				merge(e1[j].u,e1[j].v);
				oz++;
			}
		}
		sum=min(sum,ans);
	}
	cout<<sum;
	return 0;
}
