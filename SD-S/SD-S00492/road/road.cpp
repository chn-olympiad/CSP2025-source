#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e7+5,inf=0x3f3f3f3f3f3f3f3f;
int n,m,k;
struct node{
	int u,v,w;
};
node e[N],new_e[N];
int a[11][10005],p[110005],ans=inf,c[15],num[15];
bool vis[15];
void copy(){
	for(int i=1;i<=m;++i){
		new_e[i]=e[i];
	}
	return ;
}
void init(int sum){
	for(int i=1;i<=sum;i++){
		p[i]=i;
	}
}
int find(int x){
	if(p[x]!=x)p[x]=find(p[x]);
	return p[x];
}
bool comp(node l,node r){return l.w<r.w;}
void RP_AC(int sum){
	init(sum);
	int cnt=m;
	copy();
	int temp=0;
	for(int i=1;i<=sum-n;++i){
		temp+=c[num[i]];
		for(int j=1;j<=n;++j){
			new_e[++cnt]={num[i]+n,j,a[num[i]][j]};
		}
	}
	sort(new_e+1,new_e+1+cnt,comp);
	for(int i=1;i<=cnt;++i){
	    int u=new_e[i].u,v=new_e[i].v,w=new_e[i].w;
	    int fu=find(u),fv=find(v);
	    if(fu!=fv){
	    	p[fu]=fv;
	    	temp+=w;
		}
		if(temp>ans)break;
	}
	ans=min(ans,temp);
	return;
}
void dfs(int t,int l,int vul){
	if(vul>ans)return;
	if(t==l+1){
		RP_AC(n+l);
		return ;
	}
	for(int i=1;i<=k;++i){
		if(!vis[i]&&num[t-1]<i){
			num[t]=i;
			vis[i]=1;
			dfs(t+1,l,vul+c[i]);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;++i){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e[i]={u,v,w};
	}
	bool is_A=1;
	for(int i=1;i<=k;++i){
		scanf("%lld",&c[i]);
		if(c[i])is_A=0;
		for(int j=1;j<=n;++j){
			scanf("%lld",&a[i][j]);
			if(a[i][j])is_A=0;
		}
	}
	if(is_A){
		cout<<0;
		return 0;
	}
	for(int i=0;i<=k;++i){
		if(i==0){
			RP_AC(n);
		}
		else dfs(1,i,0);
	}
	printf("%lld",ans);
	return 0;
}
/*
最小生成树
考虑暴力！！！ 
*/

