#include<bits/stdc++.h>
#define maxn (int)(1005)
#define maxm (int)(2e6+5)
using namespace std;
struct Edge{
	int u,v,w;
}e[maxm];
bool cmp(Edge x,Edge y){
	return x.w < y.w;
}
int f[maxn],size[maxn];
int n,m,k,c[15],a[15][maxn],sm[15];
inline int fa(int x)
{
	if(f[x]==x)return x;
	return f[x] = fa(f[x]);
}
inline bool un(int u,int v){
	int fu = fa(u),fv=fa(v);
	if(fu!=fv) {
		if(size[fu]>size[fv])swap(fu,fv);//make size[fu]<size[fv];
		f[fv]=fu;
		size[fv]+=fu;
		return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1; i<=n; i++) {
		f[i]=i,size[i]=1;
	}
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[i]={u,v,w};
	}
	if(k==0){;}
	else{
		for(int i=1;i<=k;i++){
			cin >> c[i];
			for(int j=1;j<=n;j++){
				cin >> a[i][j];
				if(a[i][j]==0){
					sm[i]=j;
				}
			}
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(j!=sm[i])e[++m]={sm[i],j,a[i][j]};
			}
		}
	}
	sort(e+1,e+1+m,cmp);
	long long ans = 0;
	int cnt=0;
	for(int i=1;i<=m;i++){
		//cout << e[i].u << " " << e[i].v << " " << e[i].w << endl; 
		if(cnt==n-1)break;
		int u = e[i].u,v= e[i].v,w=e[i].w;
		if(un(u,v)){
			ans+=w;
			cnt++;
		}
		
	}
	cout << ans;
}

/*
5 4 1
1 3 7
2 3 4
1 2 2
4 5 3
0 5 3 0 4 5
*/