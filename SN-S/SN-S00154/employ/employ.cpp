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

constexpr int N=500,Mod=998244353;
int n,m,c[N+5],vis[N+5],ans=0;
int f[1<<19][20];
char ss[N+5];
void dfs(int nw,int lst_num){
	if(n-lst_num<m) return;
	if(nw==n+1){
		++ans;
		ans>=Mod?ans-=Mod:0;
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		vis[i]=1;
		if(lst_num>=c[i]||ss[nw-1]=='0') dfs(nw+1,lst_num+1);
		else dfs(nw+1,lst_num);
		vis[i]=0;
	}
}
int get_num(int s){
	int ret=0;
	for(;s;s-=(s&(-s))) ++ret;
	return ret;
}

namespace Usd{bool Ed;void out(){fout<<"\n    time: "<<(int)((double)clock()/CLOCKS_PER_SEC)*1000<<"ms\n mermory: "<<(int)((&St-&Ed)/1024.0/1024.0)<<"MiB\n";}}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fin>>n>>m>>ss;
	for(int i=1;i<=n;++i) fin>>c[i];
	if(n<=10){
		dfs(1,0);
		fout<<ans<<"\n";
		return 0;
	}
	if(n<=18){
		f[0][0]=1;
		for(int t=0;t<(1<<n);++t){
			int nw=get_num(t);
			for(int i=0;i<=nw;++i){
				for(int j=1;j<=n;++j){
					if((t|(1<<(j-1)))==t) continue;
					int s=t|(1<<(j-1));
					if(c[j]<=i||ss[nw]=='0') (f[s][i+1]+=f[t][i])%=Mod;
					else (f[s][i]+=f[t][i])%=Mod;
				}
			}
		}
		for(int i=m;i<=n;++i) (ans+=f[(1<<n)-1][i]);
		fout<<ans<<"\n";
		return 0;
	}
	dfs(1,0);
	fout<<ans<<"\n";
	return 0;
}
