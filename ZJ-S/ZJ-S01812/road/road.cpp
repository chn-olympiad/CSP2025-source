#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}edge[1000005],road[11][10005],lines[11][1200005];
int vi[11];
int fa[10015];
int num,ln;
unsigned long long ans,res;
bool cmp(node a,node b){
	return a.w<b.w;
}
int findfa(int x){
	if(fa[x]!=x)return fa[x]=findfa(fa[x]);
	else return fa[x];
}
void qsort(int l1,int l2,int t,int d){
	int left=1,right=1;
	lines[t-1][l1+1].w=2e9;
	road[d][l2+1].w=2e9;
	while(left+right<l1+l2){
		if(lines[t-1][left].w<=road[d][right].w){
			lines[t][left+right-1].u=lines[t-1][left].u;
			lines[t][left+right-1].v=lines[t-1][left].v;
			lines[t][left+right-1].w=lines[t-1][left].w;
			left++;
		}
		else {
			lines[t][left+right-1].u=road[d][right].u;
			lines[t][left+right-1].v=road[d][right].v;
			lines[t][left+right-1].w=road[d][right].w;
			right++;
		}
	}
	return ;
}
bool visit[11];
void dfs(int d,int h,int l,int pst,int t){
	if(d==k+1)return;
	dfs(d+1,h,l,pst,t);
	if(visit[d]==1)return;
	qsort(l,n,t,d);
	for(register int i=1;i<=n+k;i++)
		fa[i]=i;
	int i=0,num=0,ans=pst+vi[d];
	while(num<h){
		i++;
		fa[lines[t][i].u]=findfa(fa[lines[t][i].u]);
		fa[lines[t][i].v]=findfa(fa[lines[t][i].v]);
		if(fa[lines[t][i].u]!=fa[lines[t][i].v]){
			ans+=lines[t][i].w;
			fa[fa[lines[t][i].u]]=fa[lines[t][i].v];
			num++;
		}
		if(ans>res){
			if(l==ln)visit[d]=1;
			return;
		}
	}
	if(ans<res){
		res=ans;
		dfs(d+1,h+1,l+n,pst+vi[d],t+1);
	}
	else if(l==ln)visit[d]=1;
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(register int i=1;i<=n;i++)
		fa[i]=i;
	for(register int i=1;i<=m;i++)
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	sort(edge+1,edge+m+1,cmp);
	int ln=0;
	while(num<n-1){
		ln++;
		fa[edge[ln].u]=findfa(fa[edge[ln].u]);
		fa[edge[ln].v]=findfa(fa[edge[ln].v]);
		if(fa[edge[ln].u]!=fa[edge[ln].v]){
			ans+=edge[ln].w;
			fa[fa[edge[ln].u]]=fa[edge[ln].v];
			num++;
		}
	}//ÎŞkÇé¿ö 
	if(k==0){cout<<ans;return 0;}
	for(register int i=1;i<=k;i++){
		scanf("%d",&vi[i]);
		for(register int j=1;j<=n;j++){
			road[i][j].u=n+i;
			road[i][j].v=j;
			scanf("%d",&road[i][j].w);
		}
		sort(road[i]+1,road[i]+1+n,cmp);
	}
	for(register int i=1;i<=ln;i++){
		lines[0][i].u=edge[i].u;
		lines[0][i].v=edge[i].v;
		lines[0][i].w=edge[i].w;
	}
	res=ans;
	dfs(1,n,ln,0,1);
	cout<<res;
	return 0;
}
