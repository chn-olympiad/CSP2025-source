#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=10050,M=1000001;
struct Node{
	int u,v,w;
	bool operator <(Node P)const{
		return w<P.w;
	}
}T[2*M],S[2*M],G[2*M];
int Set[N],Size[N],W[N][11],C[11],Num,Cnt,m;
inline bool cmp(Node l,Node r){
	return l.w<r.w;
}
inline void Merge(int x,int y){
	if(Size[x]<Size[y])
		Set[x]=y,Size[y]+=Size[x];
	else
		Set[y]=x,Size[x]+=Size[y];
}
int Find(int x){
	if(Set[x]==x)return x;
	return Set[x]=Find(Set[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		T[++Num]={u,v,w};
	}
	for(int i=1;i<=k;++i){
		cin>>C[i];
		for(int j=1;j<=n;++j)
			cin>>W[j][i];
	}
	for(int i=1;i<=n;++i)
		Set[i]=i,Size[i]=1;
	sort(T+1,T+1+Num);
	for(int i=1;i<=Num;++i){
		int u=T[i].u,v=T[i].v;
		u=Find(u),v=Find(v);
		if(u==v)	continue;
		if(Size[u]<Size[v])
			Set[u]=v,Size[v]+=Size[u];
		else
			Set[v]=u,Size[u]+=Size[v];
		S[++Cnt]={u,v,T[i].w};
	}
	int Ans=2e9;
	for(int i=(1<<k)-1;i>=0;i--){
		int Sum=0;m=Cnt;
		for(int j=1;j<=m;++j)
			G[j]=S[j];
		for(int j=1;j<=k;++j)
			if(i&(1<<(j-1))){
				for(int t=1;t<=n;++t)
					G[++m]={t,n+j,W[t][j]};
				Sum+=C[j];
			}	
		sort(G+1,G+1+m);
		for(int i=1;i<=n+k;++i)
			Set[i]=i,Size[i]=1;
		for(int i=1;i<=m;++i){
			int u=G[i].u,v=G[i].v;
			u=Find(u),v=Find(v);
			if(u==v)	continue;
			Merge(u,v),Sum+=G[i].w;
			if(Sum>=Ans)break;
		}
		if(Sum<Ans)Ans=Sum;
	}
	cout<<Ans<<'\n';
	return 0;
}
