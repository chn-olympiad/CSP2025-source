#include<bits/stdc++.h>
#define int long long
#define For(i,j,k) for(int i=j;i<=k;++i)
#define dFor(i,j,k) for(int i=j;i>=k;--i)
#define FIO(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
using namespace std;
namespace DEBUG{
	template<class T> void _debug(const char *s,T x){cout<<s<<'='<<x<<'\n';}
	template<class F,class...Nxt> void _debug(const char *s,F x,Nxt...nxt){
		int d=0;
		while(*s!=','||d) d+=*s=='(',d-=*s==')',cout<<*s++;
		cout<<'='<<x<<',';
		_debug(s+1,nxt...);
	}
	#define debug(...) _debug(#__VA_ARGS__,__VA_ARGS__)
}
using namespace DEBUG;
const int inf=1e18;
const int Mmod=998244353;
const int MAXN=505;
int n,m,a[MAXN],c[MAXN],ans;
bitset<MAXN>s;
bool flag15=true;
int num[MAXN],inv[MAXN],pos[MAXN],tot;
inline int Qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=res*x%Mmod;
		x=x*x%Mmod;
		k>>=1;
	}
	return res;
}
inline int A(int N,int M){return num[N]*inv[M];}
//inline void solve15(){
//	sort(c+1,c+n+1);ans=1;
//	For(i,1,MAXN-1) num[i]=num[i-1]*i%Mmod;
//	inv[MAXN-1]=Qpow(num[MAXN-1],Mmod-2);
//	int l=1,r=1;
//	while(l<=n){
//		while(r+1<=n&&c[r+1]==c[l]) ++r;
//		int len=r-l+1,rest=;
//	}
//	cout<<ans;
//	exit(0);
//}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	FIO("employ");
	cin>>n>>m;
	For(i,1,n){char ch;cin>>ch,s[i]=ch-'0',flag15&=s[i]==true;}
	For(i,1,n) cin>>c[i];
	//if(flag15==true) solve15();
	For(i,1,n) a[i]=i;
	do{
		int tot=0;
		For(i,1,n){
			if(tot>=c[a[i]]) ++tot;
			else if(s[i]==false) ++tot;
		}
		ans+=tot<=n-m;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}

