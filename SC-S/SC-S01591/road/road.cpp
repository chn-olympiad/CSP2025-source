#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb emplace_back
#define mk make_pair
#define ll long long
#define fi first
#define se second
#ifdef int
#define inf ((1e18)+10)
#else 
#define inf ((1e9)+10)
#endif
//#define ls (now<<1)
//#define rs (now<<1|1)
//#define mid ((l+r)>>1)
using namespace std;
bool Mst;
const int Max=2e5+10;
const int mod=998244353;
const double eps=1e-9;


inline int read(){
	int res=0,v=1;
	char c=getchar();
	while(c<'0'||c>'9'){v=(c=='-'?-1:1);c=getchar();}
	while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+(c^48);c=getchar();}
	return res*v;
}

struct Eg{
	int x,y,z;
	Eg(int x=0,int y=0,int z=0):x(x),y(y),z(z){;}
	bool operator <(const Eg a)const{return z<a.z;}
};
int n,m,k,NN=0;
Eg a[Max*10],b[Max],c[11][Max],tmp[Max];
int fa[Max],val[Max],dep[Max];
int FindFa(int x){return x==fa[x]?x:fa[x]=FindFa(fa[x]);}
int merge(int x,int y){
	x=FindFa(x);y=FindFa(y);
	if(x==y)return 0;
	if(dep[x]>dep[y])swap(x,y);
	dep[y]=max(dep[y],dep[x]+1);
	fa[x]=y;return 1;
}

ll GetAns(Eg *a,Eg *b,Eg *c,int n,int N,int M){
	int i=1,j=1;
	ll ans=0;int num=0;for(int i=1;i<=n+k;++i)fa[i]=i,dep[i]=1;
	while(i<=N&&j<=M&&num<n-1){
		Eg now;
		if(a[i]<b[j]){
			now=a[i++];
		}else now=b[j++];
		if(merge(now.x,now.y)){ans+=now.z;c[++num]=(now);}
	}
	while(i<=N&&num<n-1){if(merge(a[i].x,a[i].y)){ans+=a[i].z;c[++num]=(a[i]);}++i;}
	while(j<=M&&num<n-1){if(merge(b[j].x,b[j].y)){ans+=b[j].z;c[++num]=(b[j]);}++j;}
	return ans;
}

ll Ans=0;
Eg Tmp[11][Max];

void dfs(Eg *a,int dep,ll ans,int num,int N){
	if(dep==k+1)return;dfs(a,dep+1,ans,num,num-1);
	ll res=GetAns(a,c[dep],Tmp[dep],num+1,N,n)+val[dep]+ans;
	Ans=min(Ans,res);dfs(Tmp[dep],dep+1,ans+val[dep],num+1,num);
}


bool Med;
signed main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		int x,y,z;
		x=read();y=read();z=read();
		a[i]=(Eg(x,y,z));
	}
	for(int i=1;i<=k;++i){
		val[i]=read();
		for(int j=1;j<=n;++j){
			c[i][j]=(Eg(i+n,j,read()));
		}
		sort(c[i]+1,c[i]+1+n);
	}
	sort(a+1,a+1+m);
	Ans=GetAns(a,b,tmp,n,m,0);NN=0;//cout << Ans << "-------\n";
	dfs(tmp,1,0,n,n-1);cout << Ans << '\n';
	return 0;
}
/*
嘟嘟嘟，k 很小/wul
考虑直接暴力枚举每个位置是否被修建，是 2^k 的
首先我们只需要保留原本边的最小生成树，一共有 O(n) 条边。
然后如果一个点被修建，那么吧边归并进去跑最小生成树。复杂度是 O(n*2^k) 的。
有 10 倍小常熟，写出搜索的形式，每层剪枝，保证每次最小生成树时是只有 2e4 条边。
*/