#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,f[N],siz[N],cnt,key[N];
int t;
long long ans,c[N],w[13][N];
struct Edge{
	int u,v,id;
	bool use;
	long long w;
}e[M],a[M<<1];
bool cmp(Edge a,Edge b){
	t++;
	return a.w<b.w;
}
int find(int u){
	t++;
	return u==f[u]?u:f[u]=find(f[u]);
}
bool merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)return 0;
	if(siz[u]>siz[v])swap(u,v);
	f[u]=v,siz[v]+=siz[u],key[v]+=key[u];
	return 1;
}
long long work(bool b,long long add){
	long long ret=0;
	sort(a,a+cnt,cmp);
	for(int i=1;i<=n+k;i++)f[i]=i,siz[i]=1,key[i]=(i<=n);
//	if(!b){
//		for(int i=0;i<cnt;i++)printf("%d-%d:%lld\n",a[i].u,a[i].v,a[i].w);
//		printf("\n");
//	}
	for(int i=0;i<cnt;i++){
		if(merge(a[i].u,a[i].v))ret+=a[i].w;
		else if(b)e[a[i].id].use=0;
		if(!b&&ret+add>=ans)return ret+add;
		if(!b&&key[find(1)]==n)return ret+add;
	}
	return ret+add;
}
long long read(){
	long long ret=0;
	char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9')ret=ret*10+c-'0',c=getchar();
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		e[i].u=read(),e[i].v=read(),e[i].w=read();
		a[i].u=e[i].u,a[i].v=e[i].v,a[i].w=e[i].w,e[i].use=1,a[i].id=i;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)w[i][j]=read();
	}
	cnt=m,ans=work(1,0),cnt=0;
	for(int i=0;i<m;i++){
		if(e[i].use)e[cnt].u=e[i].u,e[cnt].v=e[i].v,e[cnt].w=e[i].w,cnt++;
	}
	m=cnt;
//	printf("%d\n",m);
	for(int i=1;i<(1<<k);i++){
		long long sum=0;
		cnt=0;
		for(int j=0;j<m;j++)a[cnt].u=e[j].u,a[cnt].v=e[j].v,a[cnt].w=e[j].w,cnt++;
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				sum+=c[j+1];
				for(int p=1;p<=n;p++)a[cnt].u=j+1+n,a[cnt].v=p,a[cnt].w=w[j+1][p],cnt++;
			}
		}
		ans=min(ans,work(0,sum));
//	printf("%lld\n",);
	}
	printf("%lld\n",ans);
	fclose(stdin),fclose(stdout);
	return 0;
}