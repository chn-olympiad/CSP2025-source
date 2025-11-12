#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
void read(int &x){x=0;char ch=getchar();while(ch<'0'||ch>'9')ch=getchar();while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}}
const int N=10005,M=10000001;
ll ans=0;
int n,m,k,u,v,w,c[15],a[N],fl[15],fa[N],tot=0;
int find(int x){if(fa[x]==x)return x;return fa[x]=find(fa[x]);}
struct node{
	ll u,v,w;
	int _;
	bool operator < (const node&other) const {
		return w<other.w;
	}
}e[M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;++i){
		read(u),read(v),read(w);
		e[++tot]={u,v,w,0};
	}
	if(k==0){
		sort(e+1,e+tot+1);
		ll ans=0;
		for(int i=1;i<=n;++i)
			fa[i]=i;
		for(int i=1;i<=tot;++i){
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx!=fy)
				fa[fx]=fy,ans+=e[i].w;
		}
		printf("%lld\n",ans);
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=k;++i){
		read(c[i]);
		if(c[i]>0)
			flag=0;
		for(int j=1;j<=n;++j){
			read(a[j]);
			if(a[j]>0)
				flag=0;
			for(int l=1;l<j;++l)
				e[++tot]={j,l,a[l]+a[j]+c[i],i};
		}
	}
	if(flag==1){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;++i)
		fa[i]=i;
	sort(e+1,e+tot+1);
	for(int i=1;i<=tot;++i){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy)
			fa[fx]=fy,ans+=e[i].w,fl[e[i]._]++;
	}
	for(int i=1;i<=k;++i){
		if(fl[i]>0)
			ans-=(c[i]*(fl[i]-1));
	}
	printf("%lld\n",ans);
	return 0;
}
