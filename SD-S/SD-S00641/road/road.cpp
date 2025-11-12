#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,h[2000],cnt,c[20],f[2000];
bool flag[20];
struct node{
	int From,to,nxt,val,id;
}edge[3001000];
void add(int A,int B,int C,int D){
	edge[++cnt].From=A;
	edge[cnt].to=B;
	edge[cnt].val=C;
	edge[cnt].id=D;
	edge[cnt].nxt=h[A];
	h[A]=cnt;
}
bool cmp(node x,node y){
	return x.val<y.val;
}
void bcj1(int A){
	while(f[A]!=f[f[A]])
		f[A]=f[f[A]];
}
void bcj2(int A,int B){
	bcj1(B);
	f[f[B]]=A;
}
int mintree(){
	int ans=0,num=1;
	for(int i=1;i<=n+k;i++)
		f[i]=i;
	for(int i=1;i<=cnt;i++){
		bcj1(edge[i].From);
		bcj1(edge[i].to);
		if(f[edge[i].From]==f[edge[i].to])
			continue;
		if(edge[i].From>n)
			if(!flag[edge[i].From-n])
				continue;
		if(edge[i].to>n)
			if(!flag[edge[i].to-n])
				continue;
		ans+=edge[i].val;
		bcj2(edge[i].From,edge[i].to);
		if(edge[i].From<=n&&edge[i].to<=n)
			num++;
	}
	for(int i=1;i<=k;i++)
		if(flag[i])
			ans+=c[i];
	return ans;
}
int dfs(int x){
	if(x>k)
		return mintree();
	int ans=dfs(x+1);
	flag[x]=1;
	ans=min(ans,dfs(x+1));
	flag[x]=0;
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w,1);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1,w;j<=n;j++){
			scanf("%lld",&w);
			add(j,n+i,w,2);
		}
	}
	sort(edge+1,edge+cnt+1,cmp);
	printf("%lld",dfs(1));
	return 0;
}
