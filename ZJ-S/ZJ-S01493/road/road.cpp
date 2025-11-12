#include <bits/stdc++.h>
using namespace std;
int n,m,k,cnt,f[10010];
struct pp{
	int u,v,w;
}a[1000010],b[200010];
bool cmp(pp a1,pp a2){return a1.w<a2.w;}
int find(int x){
	if(f[x]==x) return x;
	f[x]=find(f[x]);
	return f[x];
}
bool us[100010];
int e[100010];
long long ans;
void dfs(int u,long long s){
	if(u==k+1){
		long long s1=0;
		for(int i=1;i<=n+k;i++) f[i]=i;
		for(int i=1;i<=cnt;i++)
			if(us[b[i].u]){
				int u=find(b[i].u),v=find(b[i].v);
				if(u!=v){
					f[v]=u;
					s1+=b[i].w;
				}
			}
		ans=min(ans,s+s1);
		return;
	}
	us[u+n]=0;
	dfs(u+1,s);
	us[u+n]=1;
	dfs(u+1,s+e[u]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		int u=find(a[i].u),v=find(a[i].v);
		if(u!=v){
			f[v]=u;
			ans+=a[i].w;
			b[++cnt]=a[i];
		}
	}
	for(int i=1;i<=k;i++){
		cin>>e[i];
		for(int j=1;j<=n;j++){
			b[++cnt].u=i+n;
			b[cnt].v=j;
			cin>>b[cnt].w;
		}
	}
	for(int i=1;i<=n;i++) us[i]=1;
	sort(b+1,b+1+cnt,cmp);
	dfs(1,0);
	cout<<ans;
 return 0;
}
