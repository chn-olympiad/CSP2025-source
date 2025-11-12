#include<bits/stdc++.h>
using namespace std;
const int N=5e6+100;
int f[N],vis[N],l[N];
struct lj{
	int u,v,w;
}a[N];
bool cmp(lj p,lj q){
	return p.w<=q.w;
}
int fd(int x){
	if(f[x]==x) return x;
	else return fd(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		int c;cin>>c;
		for(int j=1;j<=n;j++){
			int x;cin>>x;
		}
	}
	sort(a+1,a+m+1,cmp);
	int cnt=0;long long ans=0;
	for(int i=1;i<=m;i++){
		int x=a[i].u,y=a[i].v;
		if(fd(x)==fd(y)) continue;
		ans+=a[i].w;f[x]=fd(y);
		cnt++;
		if(cnt==n-1) break;
	}
	cout<<ans;
}





