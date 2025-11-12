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
	
	const int N=10010,M=1e6+10;
	int n,m,k,res,cnt;
	struct edg{
		int u,v,w,frm;
		inline bool operator< (const edg& A)const
		{
			return w<A.w;
		}
	}e[M];
	vector<edg> ori,vec;
	int p[N];
	void init()
	{
		fo(i,1,n) p[i]=i;
	}
	int find(int x)
	{
		return p[x]==x?x:p[x]=find(p[x]);
	}
	int c[11];
	pair<int,int> a[11][N];
	bool has[11];
	void main(){
		res=0,cnt=0;
		ori.clear(),vec.clear();
		n=R,m=R,k=R;
		fo(i,1,m) e[i].u=R,e[i].v=R,e[i].w=R,e[i].frm=0;
		sort(e+1,e+m+1),init();
		fo(i,1,m)
		{
			res+=e[i].w;
			ori.pb(e[i]);
		}
		for(auto i:ori) e[++cnt]=i;
		fo(i,1,k)
		{
			c[i]=R;
			fo(j,1,n) a[i][j].first=R,a[i][j].second=j;
			sort(a[i]+1,a[i]+n+1);
			fo(j,2,n) e[++cnt]={a[i][1].second,a[i][j].second,a[i][j].first,i};
		}
		sort(e+1,e+cnt+1);
		fo(s,0,(1<<k)-1)
		{
			int pre=0;
			vec.clear();
			has[0]=1;
			fo(i,1,k) has[i]=s>>(i-1)&1;
			fo(i,1,k) if(has[i]) pre+=c[i]+a[i][1].first;
			fo(i,1,cnt) if(has[e[i].frm]) vec.pb(e[i]);
			sort(vec.begin(),vec.end());
			init();
			for(auto i:vec)
			{
				int x=find(i.u),y=find(i.v);
				if(x!=y)
				{
					p[x]=y,pre+=i.w;
				}
			}
			res=min(res,pre);
		}
		write(res),puts("");
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("std.out","w",stdout);
	gza::main();
}
