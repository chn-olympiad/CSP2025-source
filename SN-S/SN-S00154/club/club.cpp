#include<bits/stdc++.h>
#define ll long long
#define il inline

namespace Usd{bool St;}
namespace My_Rand{std::random_device sd;auto rnd=std::mt19937_64(sd());}
class IO{
	const ll maxn=1<<20;
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

constexpr ll N=1e5;
ll T,n,ans;
pair<ll,ll> a[N+5][3];
struct node{ll a,b,c;bool operator<(node x)const{return (a^x.a)?a<x.a:((b^x.b)?b<x.b:c<x.c);}};
set<node> g[3];

namespace Usd{bool Ed;void out(){fout<<"\n    time: "<<(ll)((double)clock()/CLOCKS_PER_SEC)*1000<<"ms\n mermory: "<<(ll)((&St-&Ed)/1024.0/1024.0)<<"MiB\n";}}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	fin>>T;
	for(;T;--T){
		fin>>n;
		g[0].clear();
		g[1].clear();
		g[2].clear();
		ans=0;
		for(ll i=1;i<=n;++i){
			fin>>a[i][0].first>>a[i][1].first>>a[i][2].first;
			a[i][0].second=0;
			a[i][1].second=1;
			a[i][2].second=2;
			sort(a[i],a[i]+3);
			ll kkk=a[i][2].second;
			if((ll)g[kkk].size()>=n/2){
				ll j=(*g[kkk].begin()).c;
				if(a[i][2].first-a[i][1].first>a[j][2].first-a[j][1].first){
					g[kkk].erase({a[j][2].first-a[j][1].first,a[j][2].first,j});
					g[kkk].insert({a[i][2].first-a[i][1].first,a[i][2].first,i});
					ans+=a[i][2].first-a[j][2].first+a[j][1].first;
					g[a[j][1].second].insert({a[j][2].first-a[j][1].first,a[j][1].first,j});
				}
				else{
					g[a[i][1].second].insert({a[i][2].first-a[i][1].first,a[i][1].first,i});
					ans+=a[i][1].first;
				}
			}
			else{
				g[kkk].insert({a[i][2].first-a[i][1].first,a[i][2].first,i});
				ans+=a[i][2].first;
			}
		}
		fout<<ans<<"\n";
	}
	return 0;
}
