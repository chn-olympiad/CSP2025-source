#include<bits/stdc++.h>
using namespace std;
#define int long long
set<int> pq;
int cnt;
int n,m,k,p,minn=0x3f3f3f3f3f3f3f3f;
int a[15][1005],c[15];
int sum[15];
struct node {
	int l,r,z;
} q[200005];
int cmp(node a,node b) {
	return a.z<b.z;
}
bool vis[15];
void solve() {
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u,v,z;
		cin>>u>>v>>z;
		q[++cnt].l=u;
		q[cnt].r=v;
		q[cnt].z=z;
	}
	if(k==0){
		sort(q+1,q+cnt+1,cmp);
		int ans=0,tot=0;
		for(int j=1; j<=cnt; j++) {
			if(pq.size()!=n&&tot!=n-1){
				int u=q[j].l,v=q[j].r,pos=pq.size();
				pq.insert(u);
				pq.insert(v);
				if(pq.size()!=pos) {
					ans+=q[j].z;
					tot++;
//					cout<<n<<" "<<u<<" "<<v<<" "<<q[j].z<<"\n";
				}
			}else{
				break;
			}
		}
		minn=min(minn,ans);
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
			q[++cnt].l=n+i;
			q[cnt].r=j;
			q[cnt].z=a[i][j]+c[i];
		}
		sort(q+1,q+cnt+1,cmp);
		memset(sum,0,sizeof sum);
		memset(vis,0,sizeof vis);
		int ans=0,tot=0;
		int need=n;
		pq.clear();
		for(int j=1; j<=cnt; j++) {
			if(pq.size()!=n&&tot!=need-1){
				int u=q[j].l,v=q[j].r,pos=pq.size();
				if(u<=n){
					pq.insert(u);
				}
				if(v<=n){
					pq.insert(v);
				}
				if(pq.size()!=pos) {
					ans+=q[j].z;
//					cout<<n<<" "<<u<<" "<<v<<" "<<q[j].z<<"\n";
					if(u>n) {
						sum[u]++;
						if(!vis[u]){
							need++;
							vis[u]=1;
						}
//						cout<<sum[u]<<"\n";
					}
					if(v>n) {
						sum[v]++;
						if(!vis[v]){
							need++;
							vis[v]=1;
						}
//						cout<<sum[v]<<"\n";
					}
					tot++;
				}
			}else{
				break;
			}
		}
		for(int j=1;j<=i;j++){
			ans-=(sum[n+j]>=1)*c[j];
		}
		minn=min(minn,ans);
	}
	cout<<minn;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();
	return 0;
}
