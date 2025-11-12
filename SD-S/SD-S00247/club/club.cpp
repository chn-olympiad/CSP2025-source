#include<bits/stdc++.h>
#define int long long
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

const int inf=1e18,MOD1=998244353,MOD2=1e9+7;

const int maxn=1e5+10;

int T,n,a[maxn][4],bel[maxn],s[4],m;

pii b[maxn];

void calc(){
	int ans=0;
	for(int i=1;i<=n;i++) ans+=a[i][bel[i]];
	println(ans);	
}

bool Men;

signed main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	debug("%.6lfMB\n",(&Mbe-&Men)/1048576.0);
	read(T);
	while(T--){
		s[1]=s[2]=s[3]=m=0;
		read(n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<4;j++) read(a[i][j]);
			int mx=-1,id=0;
			for(int j=1;j<4;j++) if(chkmax(mx,a[i][j])) id=j;
			s[id]++;
			bel[i]=id;
		}
		int mx=-1,id=0;
		for(int i=1;i<4;i++) if(chkmax(mx,s[i])) id=i;
		if(mx<=n/2){
			calc();
			continue;
		}
		for(int i=1;i<=n;i++){
			if(bel[i]!=id) continue;
			int mx=-1;
			for(int j=1;j<4;j++) if(j!=id) chkmax(mx,a[i][j]);
			b[++m]={a[i][id]-mx,i};
		}
		std::sort(b+1,b+m+1);
		for(int i=1;i<=s[id]-n/2;i++){
			int mx=-1,iid=0;
			for(int j=1;j<4;j++) if(j!=id&&chkmax(mx,a[b[i].se][j])) iid=j;
			bel[b[i].se]=iid;
		}
		calc();
	}
	debug("%.6lfms\n",1e3*clock()/CLOCKS_PER_SEC);
}

