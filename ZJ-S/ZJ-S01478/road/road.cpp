#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+30,M=1e6+10,inf=1e18;
ll fa[N],c[N],co[20][N],top;
ll n,m,k;
int find(int x){
	if(x!=fa[x])fa[x]=find(fa[x]);
	return fa[x];
}
struct st{
	ll u,v,val;
	bool operator<(const st&w)const{
		return val<w.val;
	}
}a[M],b[M],mi[N];
ll ku(ll node){
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(b+1,b+top+1);
	ll tot=0,res=0;
	for(int i=1;i<=top;i++){
		if(find(b[i].u)!=find(b[i].v)){
			fa[find(b[i].u)]=find(b[i].v);
			tot++;
			res+=b[i].val;
		}
		if(tot==node-1)break;
	}
	if(tot<node-1)return inf;
	return res;
}
ll read(){
	ll x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		a[i].u=read();
		a[i].v=read();
		a[i].val=read();
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)co[i][j]=read();
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(a+1,a+m+1);
	int tot=0;
	for(int i=1;i<=m;i++){
		if(find(a[i].u)!=find(a[i].v)){
			fa[find(a[i].u)]=find(a[i].v);
			b[++top]=a[i];
			tot++;
		}
		if(tot==n-1)break;
	}
	for(int i=1;i<=tot;i++)a[i]=b[i];
	ll ans=1e18;
	for(int i=0;i<1<<k;i++){
		top=n-1;
		for(int j=1;j<=n;j++){
			mi[j].val=inf;
			b[j]=a[j];
		}
		ll res=0,node=n;
		for(int j=0;j<k;j++)if(i>>j&1){
			res+=c[j+1];
			node++;
			for(int k=1;k<=n;k++){
				if(co[j+1][k]<mi[k].val){
					mi[k].val=co[j+1][k];
					mi[k].u=j+n+1;
					mi[k].v=k;
				}
			}
		}
		for(int j=1;j<=n;j++)b[++top]=mi[j];
		res+=ku(node);
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}