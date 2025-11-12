#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
int n,m,k;
struct o{
	int u,v,w;
}a[maxn];
bool cmp(o x,o y){
	 return x.w<y.w;
}
int f[maxn];
int find(int x){return x==f[x]? x:f[x]=find(f[x]);}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[i]=(o){u,v,w};
	}
	sort(a+1,a+1+m,cmp);
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++){
		int u=find(a[i].u),v=find(a[i].v),w=a[i].w;
		if(u==v)continue;
		ans+=w;
		f[u]=v;
		cnt++;
		if(cnt==n-1)break;
	}
	cout<<ans;
	return 0;
}
