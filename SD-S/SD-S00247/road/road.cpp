#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define fi first
#define se second
#define pii std::pair<int,int>
#define vint std::vector<int>
#define all(x) (x).begin(),(x).end()
#define debug(...) fprintf(stderr,##__VA_ARGS__)

template<typename T>
void read(T &x){
	x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') x=x*10+(int)(c-'0'),c=getchar();
	x*=f;
}

std::stack<char>st;
template<typename T>
void print(T x){
	if(x==0) putchar('0');
	if(x<0) putchar('-'),x=-x;
	while(x) st.push((char)('0'+x%10)),x/=10;
	while(st.size()) putchar(st.top()),st.pop();
}

template<typename T>
void printsp(T x){
	print(x),putchar(' ');
}

template<typename T>
void println(T x){
	print(x),putchar('\n');
}

template<typename T,typename I>
bool chkmax(T &a,I b){
	if(a<b) return a=b,1;
	return 0;
}

template<typename T,typename I>
bool chkmin(T &a,I b){
	if(a>b) return a=b,1;
	return 0;
}

template<typename T,typename I>
void addedge(std::vector<T>*vec,I u,I v){
	vec[u].push_back(v);
}

template<typename T,typename I,typename K>
void addedge(std::vector<T>*vec,I u,I v,K w){
	vec[u].push_back({v,w});
}

template<typename T,typename I>
void addd(std::vector<T>*vec,I u,I v){
	addedge(vec,u,v),addedge(vec,v,u);
}

template<typename T,typename I,typename K>
void addd(std::vector<T>*vec,I u,I v,K w){
	addedge(vec,u,v,w),addedge(vec,v,u,w);
}

bool Mbe;

const ll inf=1e18,MOD1=998244353,MOD2=1e9+7;

const int maxn=1e4+12,maxm=1e6+10;

int n,m,k,c[15],ti[maxn],tim,cnt,z[12];

pii r[maxn];

ll cost,ans;

vint vec;

struct info{
	int u,v;
	ll w;
}e[maxm],b[maxn],a[12][maxn];

bool cmp(info x,info y){
	return x.w<y.w;
}

namespace dsu{
	int to[maxn],num,sz[maxn];
	void init(int x){
		num=x;
		for(int i=1;i<=x;i++) to[i]=i,sz[i]=1;
	}
	int go(int x){
		if(to[x]==x) return x;
		return to[x]=go(to[x]);
	}
	int merge(int x,int y){
		x=go(x),y=go(y);
		if(x==y) return num;
		if(sz[x]>sz[y]) std::swap(x,y);
		return to[x]=y,sz[y]+=sz[x],--num;
	}
}

using namespace dsu;

void add(info x){
	if(go(x.u)==go(x.v)) return ;
	cost+=x.w,merge(x.u,x.v);
}

//void add(int &z,info x){
//	if(ti[x.u]==tim) return ;
//	h[++z]=x;
//	ti[x.u]=tim;
//}

bool Men;

signed main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	debug("%.6lfMB\n",(&Mbe-&Men)/1048576.0);
	read(n),read(m),read(k),ans=inf;
	for(int i=1;i<=m;i++) read(e[i].u),read(e[i].v),read(e[i].w);
	std::sort(e+1,e+m+1,cmp);
	dsu::init(n);
	for(int i=1;i<=m;i++){
		if(go(e[i].u)==go(e[i].v)) continue;
		merge(e[i].u,e[i].v),a[k+1][++cnt]=e[i];
		cost+=e[i].w;
	}
	a[k+1][cnt+1].u=n,a[k+1][cnt+1].v=n,a[k+1][cnt+1].w=inf;
	chkmin(ans,cost);
	for(int i=0;i<k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++) read(r[j].fi),r[j].se=j;
		std::sort(r+1,r+n+1);
		for(int j=1;j<=n;j++) a[i][j].u=r[j].se,a[i][j].v=n+1,a[i][j].w=r[j].fi;
	}
//	println(ans);
//println(cnt);
	for(int i=1;i<(1<<k);i++){
		cost=0;
		int s=0;
		vec.clear(),vec.push_back(k+1),z[k+1]=1;
		for(int j=0;j<k;j++){
			if(((i>>j)&1)==0){
//				println(j);
				continue;
			}
			vec.push_back(j),z[j]=1;
			s++;
			cost+=c[j];
			for(int p=1;p<=n;p++) a[j][p].v=n+s;
		}
		init(n+s);
		while(num>1){
			info best;
			best.w=inf;
			int id=-1;
			for(int i:vec)
				if(z[i]<=n&&a[i][z[i]].w<best.w) best=a[i][z[i]],id=i;
			z[id]++;
			add(best);
		}
		chkmin(ans,cost);
	}
	println(ans);
	debug("%.6lfms\n",1e3*clock()/CLOCKS_PER_SEC);
}

