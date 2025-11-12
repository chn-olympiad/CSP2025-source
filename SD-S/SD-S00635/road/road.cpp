#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,f[11000],c[20],vis[20],ans;
struct opp{
	int u,v,w,q;
}a[20001000];
bool cmp(opp x,opp y){
	return x.w+c[x.q]<y.w+c[y.q];
}
int fa(int x){
	if(f[x]==x)return x;
	return f[x]=fa(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	int w[11000],tot=m;
	for(int t=1;t<=k;t++){
		cin>>c[t];
		for(int i=1;i<=n;i++){
			cin>>w[i];
			for(int j=1;j<i;j++){
				a[++tot].u=i;
				a[tot].v=j;
				a[tot].w=w[i]+w[j];
				a[tot].q=t;
			}
		}
	}
	sort(a+1,a+1+tot,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=tot;i++){
		int x=fa(a[i].u),y=fa(a[i].v);
		if(x!=y){
			if(x>y)f[x]=fa(y);
			else f[y]=fa(x);
			ans+=a[i].w;
			vis[a[i].q]++;
		}
	}
	for(int i=1;i<=k;i++){
		if(vis[i]){
			ans+=c[i];
		}
	}
	cout<<ans;
}
