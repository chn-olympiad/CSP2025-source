#include<bits/stdc++.h>
using namespace std;
#define ll long long
void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}
void write(long long x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,k,fa[10020],cnt,c[20],a[20][10010],b[20];
ll l,tot,ans;
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
struct edge{
	int u,v,w;
	bool operator<(const edge &b)const{
		return w<b.w;
	}
}e1[1000020],e[110020];
ll check(){
	memcpy(e1+1,e+1,sizeof(edge)*cnt);
	ll res=0;
	int cnt1=0;
	sort(e1+1,e1+1+cnt);
	//printf("cnt=%d\nl=%d\n",cnt,l);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=cnt;i++){
		int fu=find(e1[i].u),fv=find(e1[i].v);
		if(fu==fv) continue;
		cnt1++;
		res+=e1[i].w;
		//printf("%d %d\n",e1[i].w,cnt1);
		fa[fu]=fv;
		if(cnt1==n+l-1) break;
	}
	//printf("%lld\n",res);
	return res;
}
void dfs(int x){
	if(x>k){
		ans=min(ans,check()+tot);
		return;
	}
	dfs(x+1);
	b[x]=1;
	tot+=c[x];
	for(int i=1;i<=n;i++) e[++cnt]=edge{i,n+x,a[x][i]};
	l++;
	dfs(x+1);
	b[x]=0;
	tot-=c[x];
	cnt-=n;
	l--;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++)
		read(e1[i].u),read(e1[i].v),read(e1[i].w);
	sort(e1+1,e1+1+m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int fu=find(e1[i].u),fv=find(e1[i].v);
		//printf("(%d,%d,%d)\n",e[i].u,e[i].v,e[i].w);
		if(fu==fv) continue;
		e[++cnt]=e1[i];
		ans+=e1[i].w;
		fa[fu]=fv;
		if(cnt==n-1) break;
	}
	//printf("%lld\n",ans);
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++) read(a[i][j]);
	}
	dfs(1);
	write(ans);
	putchar('\n');
	return 0;
}
