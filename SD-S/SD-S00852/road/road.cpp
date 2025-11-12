#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define ull unsigned long long
#define Ckmax(x,y) x=max((x),(y))
#define Ckmin(x,y) x=min((x),(y))
using namespace std;
const int N=1e4+25,M=1e6+5,K=13;
const int IINF=0x3f3f3f3f;
const ll LINF=0x3f3f3f3f3f3f3f3fll;

inline void FileIO(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}

template<typename Type>
inline void read(Type &res){
	Type x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	res=x*f;
}

int n,m,k;
int fa[N],siz[N];
int cnt[K],c[K],cnt2[K];

int Find(int x){
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}

void Merge(int u,int v){
	if(siz[u]>siz[v]) swap(u,v);
	fa[u]=v,siz[v]+=siz[u];
}

struct Edge{
	int u,v,w;
	
	bool operator<(const Edge& tmp)const{
		return w<tmp.w;
	}
}E[M],e[K][N],e2[K][110005],tmp[110005];

vector<int> S;

void Sort(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	Sort(l,mid),Sort(mid+1,r);
	int i=1,j=1,p=0;
	while(i<=cnt2[l]&&j<=cnt2[mid+1]){
		if(e2[l][i].w<e2[mid+1][j].w) tmp[++p]=e2[l][i],++i;
		else tmp[++p]=e2[mid+1][j],++j;
	}
	while(i<=cnt2[l]) tmp[++p]=e2[l][i],++i;
	while(j<=cnt2[mid+1]) tmp[++p]=e2[mid+1][j],++j;
	cnt2[l]+=cnt2[mid+1];
	for(i=1;i<=cnt2[l];i++) e2[l][i]=tmp[i];
}

ll Solve(int s){
	S.clear();
	S.push_back(0);
	ll res=0;
	for(int i=1;i<=k;i++)
		if(s>>(i-1)&1) S.push_back(i),res+=c[i];
//	printf("S: "); for(int i:S) printf("%d ",i); puts("");
	int sz=(signed)S.size();
	for(int i=0;i<sz;i++){
		cnt2[i]=cnt[S[i]];
		for(int j=1;j<=cnt[S[i]];j++) e2[i][j]=e[S[i]][j];
	}
	Sort(0,sz-1);
//	printf("E: "); for(int i=1;i<=cnt2[0];i++) printf("(%d,%d,%d) ",e2[0][i].u,e2[0][i].v,e2[0][i].w); puts("");
	for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<=cnt2[0];i++){
		int u=Find(e2[0][i].u),v=Find(e2[0][i].v);
		if(u==v) continue;
		res+=e2[0][i].w; Merge(u,v);
	}
	return res;
}

signed main(){
	//静心，longlong，大小，空间，格式，文件，复杂度
	FileIO();
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++){
		read(E[i].u),read(E[i].v),read(E[i].w);
	}
	sort(E+1,E+m+1);
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++){
		int u=Find(E[i].u),v=Find(E[i].v);
		if(u==v) continue;
		e[0][++cnt[0]]=E[i];
		Merge(u,v);
	}
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			e[i][j].u=i+n,e[i][j].v=j;
			read(e[i][j].w);
		}
		cnt[i]=n;
		sort(e[i]+1,e[i]+n+1);
	}
	ll ans=LINF;
	for(int s=0;s<(1<<k);s++){
		Ckmin(ans,Solve(s));
	}
	printf("%lld\n",ans);
	return 0;
}


/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
