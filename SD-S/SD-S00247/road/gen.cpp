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

std::mt19937 byr(time(0));

const int lim=1e9+1;

int n=10000,m=1000000,k=10;

bool Men;

signed main(){
	freopen("road.in","w",stdout);
	debug("%.6lfMB\n",(&Mbe-&Men)/1048576.0);
	printf("%lld %lld %lld\n",n,m,k);
	for(int i=1;i<=m;i++) printf("%lld %lld %lld\n",byr()%n+1,byr()%n+1,byr()%lim);
	for(int i=1;i<=k;i++){
		printsp(byr()%lim);
		for(int j=1;j<=n;j++) printsp(byr()%lim);
		puts("");
	}
	debug("%.6lfms\n",1e3*clock()/CLOCKS_PER_SEC);
}

