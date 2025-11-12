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
	
	mt19937 rnd(time(0));
	void main(){
		int n=10,m=20,k=5;
		printf("%lld %lld %lld\n",n,m,k);
		fo(i,1,m)
		{
			if(i<=n-1) write(i),pc(' '),write(i+1),pc(' '),write(rnd()%10),puts("");
			else
			{
				int u=rnd()%n+1,v=rnd()%n+1,w=rnd()%10;
				while(u==v) u=rnd()%n+1;
				write(u),pc(' '),write(v),pc(' '),write(w),puts("");
			}
		}
		fo(i,1,k)
		{
			write(rnd()%10),pc(' ');
			fo(j,1,n) write(rnd()%10),pc(' ');
			puts("");
		}
	}
}
signed main(){
	freopen("road.in","w",stdout);
	gza::main();
}
