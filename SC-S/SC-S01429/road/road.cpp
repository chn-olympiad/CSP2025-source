#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define int long long
using namespace std;
const int inf=1e15+10;
struct node{
	int u,v,w;
	void rd(){
		cin>>u>>v>>w;
	}
};
node e[1000010];
int n,m,k,f[100010],ans,c[30],a[30][100010],cnt;
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
	f[find(x)]=find(y);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("a.in","r",stdin);
//  freopen("a.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		e[i].rd();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
		if(c[i]==0)
			for(int j=1;j<=n;j++)
				e[++m].u=m,e[m].v=j,e[m].w=a[i][j];
	}
	sort(e+1,e+m+cnt+1,cmp);
	for(int i=1;i<=m+cnt;i++)
		if(find(e[i].u)!=find(e[i].v)){
			merge(e[i].u,e[i].v);
			ans+=e[i].w;
		}
	cout<<ans<<endl;
	
	return 0;
}
