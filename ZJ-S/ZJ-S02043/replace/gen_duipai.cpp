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
		puts("10 1000");
		fo(i,1,10)
		{
			fo(j,1,3) pc(rnd()%3+'a');
			pc(' ');
			fo(j,1,3) pc(rnd()%3+'a');
			puts("");
		}
		fo(i,1,1000)
		{
			string s1="",s2="";
			fo(j,1,5) s1.pb(rnd()%3+'a');
			fo(j,1,5) s2.pb(rnd()%3+'a');
			while(s1==s2)
			{
				s2="";
				fo(j,1,5) s2.pb(rnd()%3+'a');
			}
			cout<<s1<<' '<<s2<<'\n';
		}
	}
}
signed main(){
	freopen("replace.in","w",stdout);
	gza::main();
}
