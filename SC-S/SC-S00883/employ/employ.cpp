#include<bits/stdc++.h>
#define fir first
#define sec second
#define int long long
#define pii pair<int,int>
#define fep(i,s,e) for(int i=s;i<e;i++)
#define pef(i,s,e) for(int i=s;i>e;i--)
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define per(i,s,e) for(int i=s;i>=e;i--)
namespace FastIO{
	template<typename T>inline void read(T &x){
		x=0;int f=1;char c=getchar();
		for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	}
	template<typename T,typename ...Args>
	inline void read(T &x,Args &...args){
		read(x);read(args...);
	}
	template<typename T>void print(T x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)print(x/10);
		putchar((x%10)^48);
	}
}
using namespace std;
using namespace FastIO;
const int N=20,mod=998244353;
int n,m,c[N],ans,a[N],fl[N];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n,m);
	cin>>s;
	rep(i,1,n){
		read(c[i]);
		a[i]=i;
	}
	while(true){
		rep(i,1,n)fl[i]=0;
		int now=0;
		rep(i,1,n){
			if(s[i-1]=='0'&&fl[a[i]]==0){
				now++;fl[a[i]]=1;
			}
			if(now>=c[a[i]]&&fl[a[i]]==0){
				now++;fl[a[i]]=1;
			}
		}
		if(n>=m+now){
			ans++;
			ans%=mod;
		}
		if(!next_permutation(a+1,a+n+1))break;
	}
	print(ans);
	return 0;
}
