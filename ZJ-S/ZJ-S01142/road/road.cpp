#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
const int maxn=1e4+7;
const int maxm=1e6+7;
const ll inf=1e18+7;
const int maxk=15;
pair<int, pair<int,int> > edge[maxm];
int c[maxk];
int a[maxk][maxn];
int fa[maxn];
int find(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}
bool query(int x,int y){
	int xx=find(x);
	int yy=find(y);
	return fa[yy]==xx;
}
void uni(int x,int y){
	int xx=find(x);
	int yy=find(y);
	fa[yy]=x;
}
bool vis[maxk];
pair<int, pair<int,int> > newedge[maxm*10];
ll fin=inf;
ll krus(){
	ll ans=0;
	int totbian=m,dian=n;
	for(int i=1;i<=m;i++) newedge[i]=edge[i];
	for(int i=1;i<=k;i++){
		if(!vis[i]) continue;
		ans+=c[i];
		dian++;
		for(int j=1;j<=n;j++) newedge[++totbian]={a[i][j],{dian,j}};
	}
	for(int i=1;i<=dian;i++) fa[i]=i;
	sort(newedge+1,newedge+1+totbian);
//	for(int i=1;i<=totbian;i++)
//		cout<<newedge[i].first<<" "<<newedge[i].second.first<<" "<<newedge[i].second.second<<endl;
//	cout<<totbian<<" "<<dian<<endl;
	int bian=0,cnt=1;
	while(bian<dian-1 && cnt<=totbian){
		int u=newedge[cnt].second.first;
		int v=newedge[cnt].second.second;
	//	cout<<cnt<<" "<<u<<" "<<v<<" "<<newedge[cnt].first<<endl;
		if(!query(u,v)){
			uni(u,v);
	//		cout<<u<<" "<<v<<" "<<newedge[cnt].first<<endl;
			ans+=newedge[cnt].first;
			bian++;
		}
		cnt++;
	}
//	cout<<ans<<endl;
	return ans;
}
ll sta;
void dfs(int x,int sum){
	if(sum>sta) return;
	if(x>k){
		fin=min(fin,krus());
		return;
	}
	dfs(x+1,sum);
	vis[x]=1;
	dfs(x+1,sum+c[x]);
	vis[x]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&edge[i].second.first,&edge[i].second.second,&edge[i].first);
	bool f=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0) f=1;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0) f=1;
		}
	}
	if(k!=0 && !f) printf("0\n");
	else{
		sta=krus();
		dfs(1,0);
		printf("%lld\n",fin);
	}
	return 0;
}
