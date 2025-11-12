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
	
	const int N=1e5+10;
	int n,ans,lim;
	int a[N][3],chs[N];
	int cnt[3];
	void dfs(int x,int sum)
	{
		if(x>n)
		{
			if(cnt[0]<=lim&&cnt[1]<=lim&&cnt[2]<=lim) ans=max(ans,sum);
			return;
		}
		fo(i,0,2)
		{
			cnt[i]++;
			dfs(x+1,sum+a[x][i]);
			cnt[i]--;
		}
	}
	void solve()
	{
		ans=0,m1(cnt,0);
		n=R,lim=n/2;
		fo(i,1,n)
		{
			a[i][0]=R,a[i][1]=R,a[i][2]=R;
		}
		dfs(1,0);
		write(ans),puts("");
	}
	void main(){
		MT solve();
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("std.out","w",stdout);
	gza::main();
}
