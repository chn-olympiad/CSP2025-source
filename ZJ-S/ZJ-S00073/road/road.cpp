#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+17;
const ll inf=1e18;
int n,k,m,f[N],val[N],a[11][N];
ll res=inf;
struct edge{
	int u,v,w;
}e[2000001],tmp[2000001];
inline int find(int u){
	return (f[u]==u?u:f[u]=find(f[u]));
}
inline bool cmp(edge a,edge b){
	return a.w<b.w;
}
inline int rd(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void dfs(int x,int s){
	if(x==k+1){
		ll sum=0;
		for(int i=1;i<=m;i++)tmp[i]=e[i];
		int cnt=m,g=n;
		for(int i=1;i<=k;i++){
			if((s>>i-1)&1){
				sum+=val[i];
				g++;
//				g++;
//				tmp[++cnt]={g,g-1,val[i]};
				for(int j=1;j<=n;j++)tmp[++cnt]={g,j,a[i][j]};
			}
		}
		for(int i=1;i<=g;i++)f[i]=i;
		sort(tmp+1,tmp+1+cnt,cmp);
		int cc=0;
		for(int i=1;i<=cnt;i++){
			int u=find(tmp[i].u),v=find(tmp[i].v);
			if(u!=v){
				f[u]=v;
				sum+=1ll*tmp[i].w;
				cc++;
			}
			if(cc==g-1)break;
		}
		res=min(res,sum);
		return;
	}
	dfs(x+1,s|(1<<x-1));
	dfs(x+1,s);
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    n=rd();m=rd();k=rd();
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=m;i++)e[i].u=rd(),e[i].v=rd(),e[i].w=rd();
	bool ff=1;
	for(int i=1;i<=k;i++){
		val[i]=rd();
		if(val[i]!=0){
			ff=0;
		}
		bool f2=0;
		for(int j=1;j<=n;j++)a[i][j]=rd(),f2|=(a[i][j]==0);
		if(!f2)ff=0;
	}
	if(ff){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e[m+(i-1)*n+j]={i+n,j,a[i][j]};
			}
		}
		sort(e+1,e+1+m+n*k,cmp);res=0;
		int cnt=0;
		for(int i=1;i<=m;i++){
			int u=find(e[i].u),v=find(e[i].v);
			if(u!=v){
				f[u]=v;
				res+=1ll*e[i].w;
				cnt++;
			}
			if(cnt==n+k-1)break;
		}
		cout<<res<<"\n";
		return 0;
	}
	dfs(1,0);
	cout<<res;
	return 0;
}

