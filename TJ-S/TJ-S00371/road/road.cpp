#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define endl '\n'
const int N=1e7+10,INF=0x7ffff;
int n,m,k;
struct edge{
	int a,b,w;
}e[N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fa[N];
int init(){
	for(int i=1;i<=m+k*n;i++){
		fa[i]=i;
	}
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int kruscal(){
	int ans=0,cnt=0;
	init();
//	cout<<1+m+k*n<<"\n";
	sort(e+1,e+1+m+k*n-(k!=0),cmp);
	for(int i=1;;i++){
		if(find(e[i].a)!=find(e[i].b)){
			ans+=e[i].w;
			
//			cout<<find(e[i].a)<<" "<<find(e[i].b)<<endl;
			fa[find(e[i].b)]=find(e[i].a);
//			cout<<e[i].a<<" "<<e[i].b<<" "<<e[i].w<<endl;
			cnt++;
			if(cnt==n+k-1){
				break;
			}
		}
	} 
	return ans;
}
signed main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]=(edge){u,v,w};
//		e[v][u]=w;
	}
	int minn=INF;
	for(int i=1;i<=k;i++){
//		cout<<1<<'\n';
		int tmp;
		cin>>tmp;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
//			cout<<m+(i-1)*n+j<<" ";
			e[m+(i-1)*n+j]=(edge){n+i,j,w};
//			e[j][m+i]=w;
		}
//		minn=min(kruscal()+tmp,minn);
	}
	cout<<kruscal();
	return 0;
}

