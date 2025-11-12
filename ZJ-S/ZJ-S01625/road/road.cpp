#include<bits/stdc++.h>
using namespace std;
struct node {
	int x,y,w;
} a[2000005];
int n,m,k,fa[10500],c[10500],vis[10500],cnt;
long long Ans=2e18;
int find(int x) {
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
bool cmp(node x,node y) {
	return x.w<y.w;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)cin>>a[i].x>>a[i].y>>a[i].w;
	cnt=m;
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1,w; j<=n; j++) {
			cin>>w;
			a[++cnt]= {i+n,j,w};
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=0; i<(1<<k); i++) {
		for(int j=1; j<=k; j++)
			if(i&(1<<(j-1)))vis[j]=1;
			else vis[j]=0;
		int s=0,fk=0;
		long long ans=0;
		for(int i=1; i<=n+k; i++)fa[i]=i;
		for(int i=1; i<=k; i++)
			if(vis[i])++s,ans+=c[i];
		for(int i=1; i<=cnt; i++) {
			int x=a[i].x,y=a[i].y,w=a[i].w;
			if(x>n&&!vis[x-n])continue;
			int s1=find(x),s2=find(y);
			if(s1!=s2) {
				fa[s1]=s2;
				ans+=w;
				fk++;
				if(fk==n+s-1) {
					Ans=min(Ans,ans);
					break;
				}
			}
		}
	}
	cout<<Ans;
	return 0;
}