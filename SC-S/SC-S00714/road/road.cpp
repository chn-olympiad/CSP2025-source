#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w,book;
}s[1200000];
int n,m,k,l[21],r[21][50011],fl[1210010],ans1[1210010],fa[50010],cnt,tot;
unsigned long long ans;
int get(int x){
	if(fa[x]==x)return x;
	get(fa[x]);
}
void merge(int x,int y){
	fa[x]=y;
}
bool cmp(node x,node y){
	if(x.w==y.w)return x.u<y.u;
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		s[i].u=a,s[i].v=b,s[i].w=c;
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	cnt=m;
	for(int i=1;i<=k;i++){
		scanf("%d",&l[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&r[i][j]);
			s[++cnt].u=i+n,s[cnt].v=j,s[cnt].w=r[i][j]+l[i],s[cnt].book=i;
		}
	}
	sort(s+1,s+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(tot+1==n){
			printf("%lld",ans);
			return 0;
		}
		int x=s[i].u,y=s[i].v;
		x=get(x),y=get(y);
		if(x==y)continue;
		ans=ans+s[i].w-l[s[i].book];
		if(s[i].book==0)tot++;
		else if(fl[s[i].book]==1)tot++,ans+=ans1[s[i].book],ans1[s[i].book]=0;
		else if(s[i].book>0)fl[s[i].book]=1,ans1[s[i].book]=s[i].w+l[s[i].book],ans-=s[i].w;
		merge(x,y);
	}
	return 0;
}