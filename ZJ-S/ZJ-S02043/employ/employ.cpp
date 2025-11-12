#include<bits/stdc++.h>
using namespace std;
namespace gza{
	#define int long long
	#define R read()
	#define pc putchar
	#define pb push_back
	#define fo(i,a,b) for(int i=a;i<=b;i++)
	#define rep(i,a,b) for(int i=a;i>=b;i--)
	#define m1(a,b) memset(a,b,sizeof a)
	#define MT int TTT=R;while(TTT--)
	namespace IO{
		inline int read()
		{
			int x=0,flg=0;
			char ch=getchar();
			while(!isdigit(ch)){if(ch=='-') flg=1;ch=getchar();}
			while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
			if(flg) return -x;
			return x;
		}
		template<typename T>inline void write(T x)
		{
			if(x<0) pc('-'),x=-x;
			if(x>9) write(x/10);
			pc(x%10+'0');
		}
	}
	using namespace IO;
	
	const int N=18,mod=998244353;
	int n,m;
	int s[20];
	int c[20];
	int f[1<<N][20];
	void main(){
		n=R,m=R;
		fo(i,0,n-1) scanf("%1lld",&s[i]);
		fo(i,0,n-1) c[i]=R;
		fo(i,0,n-1) f[(1<<i)][(c[i]==0||s[0]==0)]=1;
		fo(i,1,(1<<n)-1) fo(j,0,n) if(f[i][j])
		{
			fo(k,0,n-1) if(!(i>>k&1))
			{
				(f[i|(1<<k)][j+(c[k]<=j||s[__builtin_popcount(i)]==0)]+=f[i][j])%=mod;
			}
		}
		int ans=0;
		fo(i,0,n-m) (ans+=f[(1<<n)-1][i])%=mod;
		write(ans);
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	gza::main();
}
