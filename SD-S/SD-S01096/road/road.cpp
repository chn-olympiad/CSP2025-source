#include<bits/stdc++.h>
using namespace std;
long long n,m,k,noww,fa[100010],di[100],minn=40000000000000;
bool v[100],pan,zpan;
struct edge{
	int f,t;
	long long d;
}e[3000050];
void add(int f,int t,int d){
	e[++noww].f=f;
	e[noww].t=t;
	e[noww].d=d;
}
bool cmp(edge a,edge b){
	return a.d<b.d;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
long long solve(){
	int pan=0,ans=0;
//	for(int i=1;i<=noww;i++){
//		if(e[i].f>n&&!v[e[i].f])continue;
//		x=e[i].t;
//	}
//	for(int i=1;i<=k;i++){
//		if(v[i])v1[i+n]=1;
//	}

	for(int i=1;i<=noww;i++){
		int f=e[i].f,t=e[i].t;
		long long d=e[i].d;
		if(f>n&&!v[f-n])continue;
		if(f<=n&&find(f)!=find(t)||f>n&&v[f-n]&&find(f)!=find(t)){
			fa[find(f)]=find(t);
			ans+=d;
//			cout<<e[i].f<<' '<<e[i].t<<' '<<e[i].d<<endl;
		}
	}
//	cout<<endl;
//	for(int i=1;i<=noww;i++){
//		int f=e[i].f,t=e[i].t;
//		long long d=e[i].d;
//		if(f>n&&!v[f-n])continue;
////		cout<<e[i].f<<' '<<e[i].t<<' '<<e[i].d<<endl;
//		if(!pan||v1[f]!=v1[t]||!v1[f]&&!v1[]){
//			v1[f]=1;
//			v1[t]=1;
//			pan=1;
//			ans+=d;
////			cout<<e[i].f<<' '<<e[i].t<<' '<<e[i].d<<endl;
//		}
//	}
////	cout<<endl;
//	for(int i=1;i<=noww;i++){
//		int f=e[i].f,t=e[i].t;
//		long long d=e[i].d;
//		if(f>n)continue;
//		if(find(f)!=find(t)){
//			fa[find(f)]=find(t);
//			ans+=d;
//			cout<<f<<' '<<t<<' '<<d<<endl;
//		}
//	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
//		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		pan=1;
		cin>>di[i];
//		cout<<di[i]<<endl;
		for(int j=1;j<=n;j++){
			int d;
			cin>>d;
			if(d)pan=0;
			add(n+i,j,d);
//			add(j,n+i,d);
		}
		if(!di[i]&&pan)zpan=1;
	}
	if(zpan){
		cout<<0<<endl;
		return 0;
	}
	sort(e+1,e+m+n*k+1,cmp);
//	for(int i=1;i<=n*k+m;i++)cout<<e[i].f<<' '<<e[i].t<<' '<<e[i].d<<endl;
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=0;j<k;j++){
			v[j+1]=i&(1<<j);
//			cout<<v[j+1]<<' ';
		}
//		cout<<endl;
		long long ans=solve();
//		cout<<ans<<' ';
		for(int j=1;j<=k;j++)
			if(v[j]){
				ans+=di[j];
//				cout<<j<<endl;;
			}
//		cout<<ans<<endl;
		minn=min(minn,ans);
	}
	cout<<minn<<endl;
	return 0;
}
//Ren5Jie4Di4Ling5%
