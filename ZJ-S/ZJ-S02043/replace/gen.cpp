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
		cout<<2236<<' '<<1581<<endl;
		fo(i,1,2236)
		{
			string s="";
			fo(j,1,i) s.pb((char)(rand()%26+'a'));
			pc('x'),pc('b'),cout<<s<<' ';
			pc('x'),pc('c'),cout<<s<<'\n';
		}
		fo(i,1,1581)
		{
			string s="";
			fo(j,1,1581) s.pb((char)(rand()%26+'a'));
			pc('x'),pc('b'),cout<<s<<' ';
			pc('x'),pc('c'),cout<<s<<'\n';
		}
	}
}
signed main(){
	freopen("replace.in","w",stdout);
	gza::main();
}
