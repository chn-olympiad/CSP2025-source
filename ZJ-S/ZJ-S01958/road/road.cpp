#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w;
}e[1000010];
int n,m,k,c[20],w[20][10010],f[10020],ans=1e18;
vector<node> v;
bool cmp(node x,node y){
	return x.w<y.w;
}
int fa(int x){
	return f[x]=f[x]==x?x:fa(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;++j){
			scanf("%d",&w[i][j]);
		}
	}
	sort(e+1,e+1+m,cmp);
	for(int p=0;p<(1<<k);++p){
		v.clear();
		int sum=n-1,res=0;
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
		for(int i=1;i<=k;++i){
			if((p>>(i-1))&1){
				f[n+i]=n+i;
				res+=c[i];
				sum++;
				for(int j=1;j<=n;++j){
					v.push_back({n+i,j,w[i][j]});
				}
			}
		}
		sort(v.begin(),v.end(),cmp);
		int vl=v.size();
		int i=1,j=0;
		while(sum){
			if(j>=vl||e[i].w<v[j].w){
				int rx=fa(e[i].u),ry=fa(e[i].v);
				if(rx!=ry){
					f[rx]=ry;
					res+=e[i].w;
					--sum;
				}
				++i;
			}
			else{
				int rx=fa(v[j].u),ry=fa(v[j].v);
				if(rx!=ry){
					f[rx]=ry;
					res+=v[j].w;
					--sum;
				}
				++j;
			}
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
