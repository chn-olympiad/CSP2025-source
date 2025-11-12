#include<bits/stdc++.h>
using namespace std;
int bcj[10100],siz[10100];
int find(int x){
	return (x==bcj[x]?x:bcj[x]=find(bcj[x]));
}
int marge(int x,int y){
	int fax=find(x),fay=find(y);
	if(siz[fax]>siz[fay]){
		bcj[fay]=fax;
		siz[fax]+=siz[fay];
	}else{
		bcj[fax]=fay;
		siz[fay]+=siz[fax];		
	}
}
int k,n,m,flag,who[10010],wcnt;
long long kl[11][10010],ans;
long long chenzhen[11];
struct node{
	long long u,v,w;
}e[1000010],e2[2000010];
bool cmp(node a,node b){
	return a.w<b.w;
}
int xk[11];
int add_edge(int a,int &ans){
	int cnt=wcnt;
	memset(e2,0,sizeof(e2));
	for(int i=1;i<=wcnt;i++){
		e2[i].u=e[who[i]].u,e2[i].v=e[who[i]].v,e2[i].w=e[who[i]].w;
	}
	for(int i=1;i<=a;i++){
		ans+=chenzhen[xk[i]];
		for(int j=1;j<=n;j++){
			e2[++cnt].u=j,e2[cnt].v=n+xk[i],e2[cnt].w=kl[xk[i]][j];
		}
	}
	return cnt; 
}
long long kul(int a){
	for(int i=1;i<=n;i++){
		bcj[i]=i,siz[i]=1;
	}
	for(int i=1;i<=a;i++){
		bcj[n+xk[i]]=n+xk[i],siz[n+xk[i]]=1;
	}
	int ansk=0;
	int cnt=add_edge(a,ansk);
	sort(e2+1,e2+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(find(e2[i].u)!=find(e2[i].v)){
			if(ans<ansk){
				return -1;
			}
			ansk+=e2[i].w;
			marge(e2[i].u,e2[i].v);
		}
	}
	return ans;
}
void dfs(int cnt,int xuc){
	if(cnt>k){
		if(xuc==0){
			return;
		}
		long long x=kul(xuc);
		if(x>0){
			ans=min(ans,x);
		}
		return;
	}
	dfs(cnt+1,xuc);
	xk[++xuc]=cnt;
	dfs(cnt+1,xuc);
	xk[xuc]=0;
	--xuc;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		bcj[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		e[i].u=x,e[i].v=y,e[i].w=z;
	}
	for(int i=1;i<=n;i++){
		bcj[i]=i,siz[i]=1;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			ans+=e[i].w;
			marge(e[i].u,e[i].v);
			who[++wcnt]=i;
		}
	}
	if(k==0){
		printf("&lld",ans);
		return 0;
	}	
	for(int i=1;i<=k;i++){
		flag=0;
		scanf("%lld",&chenzhen[i]);
		if(chenzhen[i]!=0){
			flag=1;
		}
		for(int j=1;j<=n;j++){
			scanf("%lld",&kl[i][j]);
			if(kl[i][j]!=0){
				flag=1;
			}
		}
	}
	if(!flag){
		printf("0");
		return 0;
	}
	dfs(1,0);
	printf("%lld",&ans);
    return 0;
}

