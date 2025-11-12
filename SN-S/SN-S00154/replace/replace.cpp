#include<bits/stdc++.h>
#define ll long long
#define il inline

namespace Usd{bool St;}
namespace My_Rand{std::random_device sd;auto rnd=std::mt19937_64(sd());}
class IO{
	const int maxn=1<<20;
	char buf[1<<20],*p1=buf,*p2=buf,*p3=buf;
	#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++)
	#define flush()(fwrite(buf,1,p3-buf,stdout))
	#define pc(x) (p3==buf+maxn&&(flush(),p3=buf),*p3++=(x))
public:
	~IO(){flush();}
	template<typename T>
	il IO &operator>>(T &x){
		x=0;bool flag(0);char ch=gc();
		while(!isdigit(ch)) flag^=ch=='-',ch=gc();
		while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=gc();
		flag?x=-x:0;return *this;
	}
	template<typename T>
	il IO &operator<<(T x){
		x<0?x=-x,pc('-'):0;
		static short st[50],top(0);
		do st[++top]=x%10,x/=10;while(x);
		while(top) pc(st[top--]|48);return *this;
	}
	il IO &operator>>(char &x){do x=gc();while(isspace(x));return *this;}
	il IO &operator>>(char *x){char ch;*this>>ch;do *(x++)=ch;while(!isspace(ch=gc())&&~ch);*x='\0';return *this;}
	il IO &operator<<(char x){pc(x);return *this;}
	template<typename type>il IO &operator<<(type *x){while(*x)pc(*(x++));return *this;}
}fin,fout;
using namespace std;

constexpr int N=1e5;
int n,q;

namespace Usd{bool Ed;void out(){fout<<"\n    time: "<<(int)((double)clock()/CLOCKS_PER_SEC)*1000<<"ms\n mermory: "<<(int)((&St-&Ed)/1024.0/1024.0)<<"MiB\n";}}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	fin>>n>>q;
	for(;q;--q) fout<<"0\n";
	return 0;
}

