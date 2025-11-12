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
	void solve()
	{
		ans=0,m1(cnt,0);
		n=R,lim=n/2;
		fo(i,1,n)
		{
			a[i][0]=R,a[i][1]=R,a[i][2]=R;
			int maxx=a[i][0],pos=0;
			if(a[i][1]>maxx) maxx=a[i][1],pos=1;
			if(a[i][2]>maxx) maxx=a[i][2],pos=2;
			cnt[pos]++,ans+=a[i][pos],chs[i]=pos;
		}
		if(cnt[0]<=lim&&cnt[1]<=lim&&cnt[2]<=lim) write(ans),puts("");
		else
		{
			int maxx=cnt[0],pos=0;
			if(cnt[1]>maxx) maxx=cnt[1],pos=1;
			if(cnt[2]>maxx) maxx=cnt[2],pos=2;
			vector<int> vec;
			fo(i,1,n) if(chs[i]==pos)
			{
				int tmp=-1;
				fo(j,0,2) if(j!=pos) tmp=max(tmp,a[i][j]);
				vec.pb(a[i][chs[i]]-tmp);
			}
			sort(vec.begin(),vec.end());
			fo(i,0,maxx-lim-1) ans-=vec[i];
			write(ans),puts("");
		}
	}
	void main(){
		MT solve();
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	gza::main();
}
