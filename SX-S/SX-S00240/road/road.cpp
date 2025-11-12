#include<bits/stdc++.h>
#define N 50000
#define M 1000006
using namespace std;
#define int long long
inline int rd(){
	char ch=getchar();
	int x=0;
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
struct Edge{
	int u,v,w;
	bool operator<(const Edge &o)const{
		return w<o.w;
	}
}e[M],s[N],t[N];
int a[20][N],c[N],fa[N];
bool v[N];
int n,m,cur,k,Min;
inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void solve(){
	int sum=0;
	for(int i=1;i<=n+k;++i) fa[i]=i;
	for(int i=1;i<n;++i) t[i]=s[i];
	cur=n-1;
	for(int i=1;i<=k;++i){
		if(v[i]){
			sum+=c[i];
			for(int j=1;j<=n;++j) t[++cur]=(Edge){n+i,j,a[i][j]};
		}
	}
	sort(t+1,t+cur+1);
	for(int i=1;i<=cur;++i){
		int p=find(t[i].u),q=find(t[i].v);
		if(p!=q){
			fa[p]=q;
			sum+=t[i].w;
		}
	}
	Min=min(Min,sum);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	n=rd(),m=rd(),k=rd();
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		e[i].u=rd();
		e[i].v=rd();
		e[i].w=rd();
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;++i){
		int p=find(e[i].u),q=find(e[i].v);
		if(p!=q){
			s[++cur]=e[i];
			fa[p]=q;
			Min+=e[i].w;
		}
	}
	for(int i=1;i<=k;++i){
		c[i]=rd();
		for(int j=1;j<=n;++j) a[i][j]=rd();
	}
	for(int i=1;i<1<<k;++i){
		for(int j=0;j<k;++j) v[j+1]=(i>>j&1);
		solve();
	}
	cout<<Min;
	return 0;
}
