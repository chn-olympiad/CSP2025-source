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
	
	
	void main(){
		system("copy club1.in club.in");
		system("club");
		system("fc club.out club1.ans");
		system("copy club2.in club.in");
		system("club");
		system("fc club.out club2.ans");
		system("copy club3.in club.in");
		system("club");
		system("fc club.out club3.ans");
		system("copy club4.in club.in");
		system("club");
		system("fc club.out club4.ans");
		system("copy club5.in club.in");
		system("club");
		system("fc club.out club5.ans");
	}
}
signed main(){
	gza::main();
}
