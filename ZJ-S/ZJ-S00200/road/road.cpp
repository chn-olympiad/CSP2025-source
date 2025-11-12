#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5,M=1e6+5;
int n,tmpn,m,k,tot,c[N],a[12][N];
ll ans=2e18;
struct edge{
	int u,v,w;
}e[M+N*10],tmp[M];
inline int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int fa[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
ll kruscal(){
//	cout<<"tot"<<tot<<endl;
//	for(int i=1;i<=tot;i++)
//		cout<<"edge"<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<endl;
	ll res=0;
	sort(e+1,e+1+tot,cmp);
	for(int i=1;i<=tmpn;i++)
		fa[i]=i;
	int cnt=0;
	for(int i=1;i<=tot;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv){
			res+=e[i].w;
//			cout<<"add"<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<"res"<<res<<endl;
			fa[fu]=fv;
			cnt++;
			if(cnt==tmpn-1)return res;
		}
	}
//	cout<<"kruscal "<<res<<endl;
	return res;
}
bool judge(){
	for(int i=1;i<=k;i++)
		if(c[i])return 0;
	for(int i=1;i<=k;i++){
		bool ok=0;
		for(int j=1;j<=n;j++)
			if(!a[i][j])ok=1;
		if(!ok)return 0;
	}
	return 1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	tot=m;
	for(int i=1;i<=m;i++)
		tmp[i].u=read(),tmp[i].v=read(),tmp[i].w=read();
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)
			a[i][j]=read();
	}
	if(judge()){
//		cout<<"sper"<<endl;
		ans=0;
		for(int i=1;i<=m;i++)
			e[i]=tmp[i];
		tot=m;
		tmpn=n+k;
		for(int i=1;i<=k;i++){
			ans+=c[i];
			for(int j=1;j<=n;j++){
				e[++tot]={n+i,j,a[i][j]};
			}
		}
		cout<<ans+kruscal()<<endl;
		return 0;
	}
	for(int s=0;s<1<<k;s++){
		for(int i=1;i<=m;i++)
			e[i]=tmp[i];
		ll res=0;
		tmpn=n;
		for(int i=1;i<=k;i++){
			if((s>>(i-1)&1)){
				tmpn++;
				res+=c[i];
				for(int j=1;j<=n;j++)
					e[++tot]={n+i,j,a[i][j]};
			}
		}
		res+=kruscal();
		ans=min(ans,res);
		tot=m;
	}
	cout<<ans<<endl;
	return 0;
}
