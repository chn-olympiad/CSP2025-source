#include<bits/stdc++.h>
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
const int Mmod=1e9+7;
const int MAXN=400005;
int n,Q;
string s1[MAXN],s2[MAXN];
typedef unsigned long long ull;
ull base=20280031;
inline ull Hash(string S){ull res=0;For(i,0,S.size()-1) res=res*base+S[i];return res;}
ull bit[MAXN],w1[MAXN],w2[MAXN],h1[MAXN],h2[MAXN],b1[MAXN],b2[MAXN];
map<pair<ull,ull>,int>mp;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	FIO("replace");
	bit[0]=1;For(i,1,MAXN-1) bit[i]=bit[i-1]*base;
	cin>>n>>Q;
	For(i,1,n) cin>>s1[i]>>s2[i],w1[i]=Hash(s1[i]),w2[i]=Hash(s2[i]),mp[make_pair(w1[i],w2[i])]++;
	For(T,1,Q){
		string t1,t2;int res=0,len1,len2;
		cin>>t1>>t2,len1=t1.size(),len2=t2.size();t1='.'+t1,t2='.'+t2;
		h1[0]=0;For(i,1,len1) h1[i]=h1[i-1]*base+t1[i];b1[len1+1]=0;dFor(i,len1,1) b1[i]=b1[i+1]+t1[i]*bit[len1-i];
		h2[0]=0;For(i,1,len2) h2[i]=h2[i-1]*base+t2[i];b2[len1+1]=0;dFor(i,len2,1) b2[i]=b2[i+1]+t2[i]*bit[len2-i];
		For(l,1,len1){
			if(h1[l-1]!=h2[l-1]) break;
			dFor(r,len1,l){
				int L=l,R=len2-len1+r;
				if(L>R||b1[r+1]!=b2[R+1]) break;
				ull T1=h1[r]-h1[l-1]*bit[r-l+1],T2=h2[R]-h2[L-1]*bit[R-L+1];
				int w=mp[make_pair(T1,T2)];
				res+=mp[make_pair(T1,T2)];
			}  
		}
		cout<<res<<'\n';
	}
	return 0;
}

