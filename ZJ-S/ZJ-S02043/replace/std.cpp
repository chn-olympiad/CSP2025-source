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
	
	const int N=2e5+10,M=5e6+10,mod=1e13+51;
	int n,q;
	int pw[M];
	string s1[N],s2[N],t1[N],t2[N];
	int ls[N],lt[N];
	void main(){
		pw[0]=1;
		fo(i,1,M-1) pw[i]=pw[i-1]*131%mod;
		ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
		cin>>n>>q;
		fo(i,1,n) cin>>s1[i]>>s2[i],ls[i]=s1[i].size();
		fo(i,1,q) cin>>t1[i]>>t2[i],lt[i]=t1[i].size();
		fo(i,1,q)
		{
			int ans=0;
			fo(j,1,n)
			{
				fo(k,0,lt[i]-ls[j]) if(t1[i].substr(k,ls[j])==s1[j])
				{
					int l=k,r=k+ls[j]-1;
					string tmp="";
					fo(p,0,lt[i]-1)
						if(l<=p&&p<=r) tmp.pb(s2[j][p-l]);
						else tmp.pb(t1[i][p]);
//					cout<<i<<' '<<j<<' '<<k<<' '<<tmp<<endl;
					if(tmp==t2[i]) ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("std.out","w",stdout);
	gza::main();
}
