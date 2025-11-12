#include<bits/stdc++.h>
using namespace std;
const int maxn=20015,maxm=1000005;
long long n,m,k,tot,c[maxn],vv[maxn*2],f[maxn*2],ans=9999999999999999ll,minn=9999999999999999ll,v[110];
vector<pair<int,int> > ve[maxn*2];
struct no{
	int u,v,w;
}e[maxm*3];
int cm(no a,no b){
	return a.w<b.w;
}
int fd(int x){
	if(f[x]==x)return x;
	return f[x]=fd(f[x]);
}
inline int ck(int x){
//	if(x>n)cout<<v[x-n];
	if(x>n)return v[x-n];
	return 1;
}
int df(int a,long long now,int nowt){
	if(a>k){
		if(now>=ans)return 0;
//		cout<<now<<"\n\n";
		long long anss=0,noww=0;
		for(int i = 1;i<=n+k;i++){
			f[i]=i;
//			if(i<=k)cout<<v[i];
		}
		for(int i = 1;noww<n-1+nowt;i++){
//			cout<<i;
			if(ck(e[i].u) && ck(e[i].v) && fd(e[i].u)!=fd(e[i].v)){
				anss+=e[i].w;
				f[fd(e[i].u)]=fd(e[i].v);
				noww++;
//				cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
			}
		}
		
		ans=min(ans,anss+now);
		return 0;
	}
	df(a+1,now,nowt);
	v[a]=1;
	df(a+1,now+c[a],nowt+1);
	v[a]=0;
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i = 1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		ve[u].push_back({v,w});
		ve[v].push_back({u,w});
		e[++tot]=(no){u,v,w};
//		e[++tot]=(no){v,u,w};
	}
	int fl=1;
	for(int i = 1,u,v,w;i<=k;i++){
		cin>>c[i];
		for(int j = 1;j<=n;j++){
			cin>>w;
			ve[i].push_back({n+k,w});
			ve[n+k].push_back({i,w});
			e[++tot]=(no){j,n+i,w};
//			e[++tot]=(no){n+i,j,w};
		}
		if(c[i]){
			fl=0;
		}
	}
	sort(e+1,e+1+tot,cm);
	long long anss=0,noww=0;
	for(int i = 1;i<=n+k;i++){
		f[i]=i;
	}
	for(int i = 1;noww<n+k-1;i++){
		if(fd(e[i].u)!=fd(e[i].v)){
			anss+=e[i].w;
			f[fd(e[i].u)]=fd(e[i].v);
			noww++;
//			cout<<e[i].u<<" "<<e[i].v<<"\n";
		}
	}
	minn=anss;
	if(fl){
		cout<<minn;
		return 0;
	}
	df(1,0,0);
	cout<<ans; 
	return 0;
}

