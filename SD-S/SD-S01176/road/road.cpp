#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+63;
const int M=2e6+63;
int n,m,k;
int fa[N];
ll c[15],a[15][N],czr[15];
ll ans;
int iread(){
	int x=0,fh=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			fh=-fh;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*fh;
}
ll lread(){
	ll x=0;
	int fh=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			fh=-fh;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*fh;
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	else{
		return fa[x]=find(fa[x]);
	}
}
struct edge{
	int u,v;
	ll w;
}e[M];
int tot;
void add(int u,int v,ll w){
	e[++tot].u=u;
	e[tot].v=v;
	e[tot].w=w;
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=iread();
	m=iread();
	k=iread();
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		u=iread();
		v=iread();
		w=lread();
		add(u,v,w);
	}
	bool flag=true; 
	for(int i=1;i<=k;i++){
		c[i]=lread();
		if(c[i]){
			flag=false;
		}
		for(int j=1;j<=n;j++){
			a[i][j]=lread();
			if(a[i][j]==0){
				czr[i]=j;
			}
		}
	}
	if(flag){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(j!=czr[i]){
					add(j,czr[i],a[i][j]);
				}
			}
		}
		sort(e+1,e+tot+1,cmp);
		for(int i=1,j=0;i<=tot;i++){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			int fu=find(u),fv=find(v);
			if(fu==fv){
				continue;
			}
			fa[fu]=fv;
			ans+=w;
			j++;
			if(j>=n-1){
				break;
			}
		}
	}
	else{
		ans=1e18;
		for(int l=0;l<(1<<k);l++){
			int tot2=tot;
			ll ans1=0;
			int n2=n;
			for(int i=1;i<=k;i++){
				if((l>>(i-1))&1){
					ans1+=c[i];
					n2++;
					for(int j=1;j<=n;j++){
						add(j,n2,a[i][j]);
					}
				}
			}
			for(int i=1;i<=n2;i++){
				fa[i]=i;
			}
			sort(e+1,e+tot+1,cmp);
			int j=0;
			for(int i=1;i<=tot;i++){
				int u=e[i].u,v=e[i].v,w=e[i].w;
				int fu=find(u),fv=find(v);
				if(fu==fv){
					continue;
				}
				fa[fu]=fv;
				ans1+=w;
				j++;
				if(j>=n2-1){
					break;
				}
			}
			if(j>=n2-1){
				ans=min(ans,ans1);
			}
			tot=tot2;
		}
	}
	printf("%lld",ans);
	return 0;
}
