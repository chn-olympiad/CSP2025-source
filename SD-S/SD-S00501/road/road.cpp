#include<bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define tmax(a,b) (a)=max((a),(b))
#define tmin(a,b) (a)=min((a),(b))
#define all(x) (x).begin(),(x).end()
#define cout(x) cout<<fixed<<setprecision(x)

using namespace std;
typedef long long LL;typedef pair<int,int> PII;
typedef vector<int> vi;typedef vector<PII> vp;
typedef array<int,3> a3;typedef vector<a3> va3;

const int N=1e4+20,M=1e6+5,K=15,KK=(1<<10)+5;
int n,m,k,c[K],fa[N+K],e[KK][N+K],ed[KK][N+N+K+K],tot[KK];
LL ans;
a3 g[M+K*N];

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int lowbit(int x){
	return x&(-x);
}
bool cmp(int i,int j){
	return g[i][0]<g[j][0];
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g[i]={w,u,v};
		ed[0][i]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1,a;j<=n;j++){
			cin>>a;
			g[m+(i-1)*n+j]={a,i+n,j};
		}
	}
	sort(ed[0]+1,ed[0]+m+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1,u,v,w;i<=m;i++){
		w=g[ed[0][i]][0],u=g[ed[0][i]][1],v=g[ed[0][i]][2];
		u=find(u),v=find(v);
		if(u!=v){
			fa[u]=v;
			e[0][++tot[0]]=ed[0][i];
			ans+=w;
		}
	}
	for(int s=1;s<(1<<k);s++){
		LL res=0;
//		cout<<s<<"\n";
		for(int i=1;i<=k;i++){
			if(s>>(i-1)&1){
				res+=c[i];
			}
		}
//		no;
		int bit=lowbit(s),mm=tot[s^bit],nk=0,tmp=bit;
		while(tmp){
			nk++;
			tmp>>=1;
		}
//		no;
		for(int i=1;i<=mm;i++){
			ed[s][i]=e[s^bit][i];
		}
//		no<<nk<<"?\n";
		for(int i=1;i<=n;i++){
			ed[s][++mm]=m+(nk-1)*n+i;
		}
//		no;
		sort(ed[s]+1,ed[s]+1+mm,cmp);
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
//		no<<mm<<"\n";
		for(int i=1,u,v,w;i<=mm;i++){
//			if(s==78) cout<<i<<" "<<ed[s][i]<<"!\n";
			w=g[ed[s][i]][0],u=g[ed[s][i]][1],v=g[ed[s][i]][2];
			u=find(u),v=find(v);
			if(u!=v){
				fa[u]=v;
				e[s][++tot[s]]=ed[s][i];
				res+=w;
			}
		}
//		no;
		tmin(ans,res);
	}
	cout<<ans;
	return 0;
}

