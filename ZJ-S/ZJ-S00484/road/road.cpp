#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;i++)
#define UF(i,a,b) for(int i=a;i>=b;i--)
#define look_memory cerr<<abs(&M2-&M1)/1024.0/1024<<'\n'
#define look_time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<'\n'
using namespace std;
#define LL long long
bool M1;
const int N=1e4+100;
const int M=1e6+100;
struct edge{
	int u,v,w;
}e[M];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int n,m,k,res;
int f[N];
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
int join(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return 0;
	f[fx]=fy;
	return 1;
}
void Kruskal(){
	for(int i=1;i<=m;i++){
		if(join(e[i].u,e[i].v)){
			res+=e[i].w;
		}
	}
}

void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	res=0;
	sort(e+1,e+m+1,cmp);
	Kruskal();
	cout<<res<<'\n';
}
bool M2;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int Time=clock();
	int T=1;
//  cin>>T;
	while(T--){
		solve();
	}
	//look_memory;
	//look_time;
	return 0;
}
