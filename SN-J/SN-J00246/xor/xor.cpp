#include<bits/stdc++.h>
#define ll long long
#define il inline

namespace Usd{bool St;}
namespace My_Rand{std::random_device sd;auto rnd=std::mt19937_64(sd());}
class IO{
	const int maxn=1<<20;
	char buf[1<<20],*p1=buf,*p2=buf,*p3=buf;
	#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++)
	#define flush() (fwrite(buf,1,p3-buf,stdout))
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
		x<0?(x=-x,pc('-')):0;
		static short st[50],top(0);
		do st[++top]=x%10,x/=10;while(x);
		while(top) pc(st[top--]|48);return *this;
	}
	il IO &operator>>(char &x){do x=gc();while(isspace(x));return *this;}
	il IO &operator>>(char *x){char ch;*this>>ch;do *(x++)=ch;while(!isspace(ch=gc())&&~ch);*x=gc();return *this;}
	il IO &operator<<(char x){pc(x);return *this;}
	template<typename type>il IO &operator<<(type *x){while(*x) pc(*(x++));return *this;}
}fin,fout;
namespace _Hash_Table{
	using My_Rand::rnd;
	using uns=unsigned;
	using ull=unsigned ll;
	template<typename T1,typename T2>
	struct Node{T1 key;T2 val;};
	template<uns Siz,uns Mod,typename T1,typename T2>
	class Hash_Table{
		int nxt[Siz+5],hd[Mod],len;
		Node<T1,T2> e[Siz+5];
		il uns hash(ull x)const{
			static const ull Fix=rnd();
			x+=Fix;x=(x^(x<<13));x=(x^(x>>7));x=(x^(x<<17));
			return (x^(x>>31))%Mod;
		}
		il int find(int u,int type){
			uns v=hash(u);
			for(int i=hd[v];i;i=nxt[i])
				if(e[i].key==u) return i;
			if(type){
				e[++len].key=u,e[len].val=0,nxt[len]=hd[v],hd[v]=len;
				return len;
			}
			return -1;
		}
	public:
		il T2 &operator[](const T1 &x){return e[find(x,1)].val;}
		il bool count(const T1 &x){return find(x,0)!=-1;}
	};
}
using namespace std;
using _Hash_Table::Hash_Table;

constexpr int N=5e5;
int n,k,a[N+5],ans,f[N+5],mx[N+5];
Hash_Table<N*3,133331,int,int> lst;

namespace Usd{bool Ed;void out(){fout<<"\n    time: "<<(int)((double)clock()/CLOCKS_PER_SEC*1000)<<"ms\n mermory: "<<(int)((&St-&Ed)/1024.0/1024.0)<<"MiB\n";}}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	fin>>n>>k;
	for(int i=1;i<=n;++i) fin>>a[i];
	for(int i=2;i<=n;++i) a[i]^=a[i-1];
	lst[0]=0;
	for(int i=1;i<=n;++i){
		if(lst.count(a[i]^k)) f[i]=mx[lst[a[i]^k]]+1;
		lst[a[i]]=i;
		mx[i]=max(mx[i-1],f[i]);
	}
	fout<<mx[n]<<"\n";
	return 0;
}
