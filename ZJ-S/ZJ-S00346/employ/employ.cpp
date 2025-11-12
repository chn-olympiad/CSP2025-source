#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define ri register int
#define mp make_pair
#define pb push_back
using namespace std;
namespace IO{
	#define gh() getchar()
	inline int r(){
		int a=1,b=0;
		char c=gh();
		while(c>'9'||c<'0'){if(c=='-')a=-1,c=gh();}
		while(c<='9'&&c>='0'){b=(b<<1)+(b<<3)+(c^48);c=gh();}
		return a*b;
	}
	inline char gc(){char ch=gh();while(ch<=' ')ch=gh();return ch;}
	inline string gs(){char ch=gh();string S="";while(ch<=' ')ch=gh();while(ch>' '){S+=ch;ch=gh();}return S;}
	inline void wr(int x){
		if(x==0)return;if(x<0){x=-x;putchar('-');}
		wr(x/10);putchar((x%10)^48);
	}
	inline void ww(int x){if(x==0)putchar('0');else wr(x);putchar(' ');}
	inline void wln(int x){if(x==0)putchar('0');else wr(x);putchar('\n');}
	inline void w(int x){if(x==0)putchar('0');else wr(x);}
}
using namespace IO;
const int N=19,p=998244353;
namespace D1n0{
	int c[N],n,m,dp[1<<N][N];
	string s;
	inline void Zyt(){
		n=r();m=r();
		s=" "+gs();
		int cnt=0;
		for(ri i=1;i<=n;++i)if(s[i]=='1')++cnt;
		if(cnt<m||n>18){w(0);return;}
		for(ri i=1;i<=n;++i)c[i]=r();
		dp[0][0]=1;
		for(ri i=1;i<(1<<n);++i)
		for(ri j=0;j<=n;++j){
			int cnt=__builtin_popcount(i);
			for(ri k=1;k<=n;++k)
			if((i>>k-1)&1){
				if(c[k]<=j||s[cnt]=='0')dp[i][j+1]+=dp[i^(1<<k-1)][j];
				else dp[i][j]+=dp[i^(1<<k-1)][j];
			}
		}
		int ans=0;
		for(ri i=0;i<=n;++i)if(n-i>=m)ans+=dp[(1<<n)-1][i]%p;
		wln(ans%p);
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	D1n0::Zyt();
}
