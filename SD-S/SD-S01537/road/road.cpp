#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,minn=4000000000000000000;
int tot;
struct node{
	int l,r,w,opt;
}e[4000006];
int v[15];
int fa[10000+50];
int rd(){
	char c;
	int f=1,k=0;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=(k<<3)+(k<<1)+(c&15);
		c=getchar();
	}
	return k*f;
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int Find(int x){
	if(x==fa[x]){
		return x;
	}
	fa[x]=Find(fa[x]);
	return fa[x];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd();
	m=rd();
	k=rd();
	for(int i=1;i<=m;i++){
		e[i].l=rd();
		e[i].r=rd();
		e[i].w=rd();
		e[i].opt=1;
		tot++;
	}
	for(int i=1;i<=k;i++){
		v[i]=rd();
		for(int j=1;j<=n;j++){
			e[++tot].l=n+i;
			e[tot].r=j;
			e[tot].w=rd();
			e[tot].opt=0;
		}
	}
	sort(e+1,e+tot+1,cmp);
	int uu=(1<<k);
	for(int i=0;i<uu;i++){
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
		}
		int ans=0;
		int nn=__builtin_popcount(i)+n;
		int id=i;
		int vis[15];
		for(int j=1;j<=k;j++){
			vis[j]=(id&1);
			if(vis[j]){
				ans+=v[j];
			}
			id=(id>>1);
		}
		for(int j=1;j<=tot;j++){
			if(e[j].opt==0){
				if(vis[e[j].l-n]!=1){
					continue;
				}
			}
			int u=e[j].l,v=e[j].r,w=e[j].w;
			int fx=Find(u),fy=Find(v);
			if(fx!=fy){
				fa[fx]=fy;
				nn--;
				ans+=w;
				if(nn==1||ans>=minn){
					break;
				}
			}
		}
		minn=min(minn,ans);
	}
	printf("%lld",minn);
	return 0;
}
