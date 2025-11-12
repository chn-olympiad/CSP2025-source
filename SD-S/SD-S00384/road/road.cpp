#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,k,fa[11000],c[20],b[20][11000],cnt;
long long ans;
bool flag=0;
struct f{
	int u,v,w;
	friend bool operator < (f q1,f q2){
		return q1.w<q2.w;
	}
}a[maxn<<1];
int fin(int x){
	if(fa[x]==x) return x;
	return fa[x]=fin(fa[x]);
}
void solve(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(a+1,a+cnt+1);
	for(int i=1;i<=cnt;i++){
		int l1=fin(a[i].u),l2=fin(a[i].v);
		if(l1==l2) continue;
		ans+=a[i].w;
		fa[l1]=l2;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	cnt=m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			flag=1;
		}
		int pos,minn=1e9+10;
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
			if(minn>b[i][j]){
				minn=b[i][j];
				pos=j;
			}
		}
		if(minn!=0){
			flag=1;
		}
		c[i]+=minn;
		for(int j=1;j<=n;j++){
			cnt++;
			a[cnt]={pos,j,b[i][j]};
		}
	}
	solve();
 	cout<<ans;
	return 0;
}
