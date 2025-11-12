#include<bits/stdc++.h>
#define int long long
using namespace std;
int mi=1e18,n,m,k,i,c[20],cnt,f[20000],fa[20000],j,sum;
struct no{
	int u,v,w;
}a[2000010];
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
bool cmp(no t,no w){return t.w<w.w;}
void make_tree(int beginpr,int x){
	int i,u,v,w,sum=0,ans=0,sum2=0;
	for(i=1;i<=n+k;i++)fa[i]=i;
	for(i=1;i<=cnt;i++){
		u=a[i].u;v=a[i].v;w=a[i].w;
		if(!f[u])continue;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			fa[fu]=fv;
			ans+=w;
			sum++;
			if(u<=n&&v<=n)sum2++;
		}
		if(sum==x-1||sum2==n-1)break;
		if(ans+beginpr>=mi)return ;
	}
	if(sum==x-1)mi=min(mi,ans+beginpr);
}
void dfs(int id,int sum,int sum2){
	if(sum>=mi)return ;
	if(id==n+k+1){
		make_tree(sum,sum2);
		return ;
	}
	f[id]=1;
	dfs(id+1,sum+c[id-n],sum2+1);
	f[id]=0;
	dfs(id+1,sum,sum2);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
	cnt=m;
	for(i=1;i<=k;i++){
		cin>>c[i];sum+=(c[i]==0);
		for(j=1;j<=n;j++){
			cin>>a[++cnt].w;
			a[cnt].u=i+n;a[cnt].v=j;
		}
	}
	if(sum!=k){
		for(i=1;i<=n;i++)f[i]=1;
		sort(a+1,a+1+cnt,cmp);
		dfs(n+1,0,n);
		cout<<mi;
	}
	else {
		for(i=1;i<=n+k;i++)f[i]=1;
		sort(a+1,a+1+cnt,cmp);
		make_tree(0,n+k);
		cout<<mi;
	}
	return 0;
}