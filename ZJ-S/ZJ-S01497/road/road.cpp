#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct tree{
	int nxt,to,l;
}Tr[20005];
struct Line{
	int l,u,v;
}L[100005];
int edg[15][10005],Head[10005],siz[10005],fa[10005],tot=0,tot1=0;
int add1(int u,int v,int x){
	Tr[++tot1].to=v;
	Tr[tot1].nxt=Head[u];
	Tr[tot1].l=x;
	Head[u]=tot1;
}
bool cmp(Line a,Line b){
	return a.l<b.l;
}
int read(){
	int ans=0,f=1;
	char s=getchar();
	while((s>'9'||s<'0')&&s!='-') s=getchar();
	if(s=='-') f=-1,s=getchar();
	while(s<='9'&&s>='0'){
		ans=(ans<<3)+(ans<<1)+s-'0';
		s=getchar();
	}
	return ans*f;
}
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	siz[x]=siz[fa[x]];
}
int main(){
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		int u,v,x;
		scanf("%d%d%d",&u,&v,&x);
		L[i].l=x;
		L[i].u=u;
		L[i].v=v;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(L+1,L+m+1,cmp);
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++) scanf("%d",edg[i][j]);
	int ans=0;
	for(int i=1;i<=m;i++){
		int fau=find(L[i].u),fav=find(L[i].v);
		if(fau==fav) continue;
		else{
			ans+=L[i].l;
			if(siz[L[i].u]>siz[L[i].v]) fa[L[i].v]=fa[L[i].u];
			else fa[L[i].u]=fa[L[i].v];
			siz[L[i].u]=siz[L[i].v]=siz[L[i].u]+siz[L[i].v];
		}
	}
	printf("%d\n",ans);
	return 0;
}