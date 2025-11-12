#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define ri register int
#define mp make_pair
#define pb push_back
using namespace std;
namespace IO{
	#define gh() getchar()
	inline int r(){
		int a=1,b=0;
		char c=gh();
		while(c>'9'||c<'0'){if(c=='-')a=-1,c=gh();}
		while(c<='9'&&c>='0'){b=(b<<1)+(b<<3)+(c^48);c=gh();}
		return a*b;
	}
	inline char gc(){char ch=gh();while(ch<=' ')ch=gh();return ch;}
	inline string gs(){char ch=gh();string S="";while(ch<=' ')ch=gh();while(ch>' '){S+=ch;ch=gh();}return S;}
	inline void wr(int x){
		if(x==0)return;if(x<0){x=-x;putchar('-');}
		wr(x/10);putchar((x%10)^48);
	}
	inline void ww(int x){if(x==0)putchar('0');else wr(x);putchar(' ');}
	inline void wln(int x){if(x==0)putchar('0');else wr(x);putchar('\n');}
	inline void w(int x){if(x==0)putchar('0');else wr(x);}
}
using namespace IO;
const int N=1e5+4;
namespace D1n0{
	int n,a[N][5],ans,in[N];
	vector<int>v[5];
	inline void move(int fr,int t1,int t2){
		memset(in,0,sizeof in);
		priority_queue<pii>p;
		for(auto it:v[fr]){
			in[it]=1;
			p.push(mp(a[it][t1]-a[it][fr],it));
			p.push(mp(a[it][t2]-a[it][fr],it));
		}
		int nwsiz=v[fr].size();
		while(nwsiz>n/2){
			pii t=p.top();p.pop();
			if(!in[t.se])continue;
			in[t.se]=0;
			ans+=t.fi;
			--nwsiz;
		}
	}
	inline void sol(){
		n=r();
		v[1].clear();v[2].clear();v[3].clear();ans=0;
		for(ri i=1;i<=n;++i){
			a[i][1]=r(),a[i][2]=r(),a[i][3]=r();
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])v[1].pb(i);
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])v[2].pb(i);
			else v[3].pb(i);
		}
		if(v[1].size()>n/2){
			move(1,2,3);
		}else if(v[2].size()>n/2){
			move(2,1,3);
		}else if(v[3].size()>n/2){
			move(3,1,2);
		}
		wln(ans);
	}
	inline void Zyt(){
		int T=r();
		while(T--)sol();
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	D1n0::Zyt();
}
