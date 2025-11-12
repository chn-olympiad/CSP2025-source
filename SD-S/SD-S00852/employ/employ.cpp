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
const int N=505;
const int IINF=0x3f3f3f3f;
const ll LINF=0x3f3f3f3f3f3f3f3fll;

inline void FileIO(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
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

int n,m;
char a[N];
int c[N];

const ll mod=998244353;

inline ll Mod(ll x){return (x>=mod)?(x-mod):(x);}
inline void Add(ll &x,ll y){x=Mod(x+y);}

namespace Subtask1{
	int p[N];
	
	void Solve(){
		for(int i=1;i<=n;i++) p[i]=i;
		int ans=0;
		do{
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(cnt>=c[p[i]]||a[i]=='0') ++cnt;
			}
			ans+=(cnt<=n-m); 
		}while(next_permutation(p+1,p+n+1));
		printf("%d\n",ans);
	}
}

namespace Subtask2{
	ll f[(1<<18)][18];
	
	void Solve(){
		f[0][0]=1;
		for(int s=0;s<(1<<n);s++){
			int pc=__builtin_popcount(s);
			for(int i=0;i<=n;i++){
				if(!f[s][i]) continue;
				for(int j=0;j<n;j++){
					if(s>>j&1) continue;
					if(a[pc+1]=='0'||i>=c[j+1]) Add(f[s|(1<<j)][i+1],f[s][i]);
					else Add(f[s|(1<<j)][i],f[s][i]);
				}
			}
		}
		ll ans=0;
		for(int i=0;i<=n-m;i++) Add(ans,f[(1<<n)-1][i]);
		printf("%lld\n",ans);
	}
}

signed main(){
	//静心，longlong，大小，空间，格式，文件，复杂度
	FileIO();
	read(n),read(m);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++) read(c[i]);
	if(n<=10) Subtask1::Solve();
	else Subtask2::Solve();
	return 0;
}

/*
3 2
101
1 1 2
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/

