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
		system("copy replace1.in replace.in");
		system("replace");
		system("fc replace.out replace1.ans");
		system("copy replace2.in replace.in");
		system("replace");
		system("fc replace.out replace2.ans");
		system("copy replace3.in replace.in");
		system("replace");
		system("fc replace.out replace3.ans");
		system("copy replace4.in replace.in");
		system("replace");
		system("fc replace.out replace4.ans");
	}
}
signed main(){
	gza::main();
}
