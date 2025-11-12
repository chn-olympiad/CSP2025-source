#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rg register
#define INT_MAX 0x7fffffff
#define LL_INT_MAX 0x7fffffffffffffffll
#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
namespace io
{
	template<typename T> inline void iread(T &x)
	{
		x=0; char c=' '; int w=1;
		while(!isdigit(c)&&c!='-') c=getchar();
		if(c=='-'){w=-1; c=getchar();}
		while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	}
}
using io::iread;
const int N=2e3+10;
int n,m,sum;
string s[N][2],t0,t1;
int nxt[N][N];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i][0]>>s[i][1];
		int pre=0;
		nxt[i][0]=0;
		int l=s[i][0].size();
		for(int j=1;j<l;++j)
		{
			while(s[i][0][j]!=s[i][0][pre]&&pre) pre=nxt[i][pre];
			if(s[i][0][j]==s[i][0][pre]) nxt[i][j]=pre++;
		}
	}
	for(int i=1;i<=m;++i)
	{
		cin>>t0>>t1;
		if(t0.size()!=t1.size())
		{
			puts("0");
			continue;
		}
		sum=0;
		for(int i=1;i<=n;++i)
		{
			int la=t0.size(),lb=s[i][0].size();
			for(int k=0,j=0;k<la;++k)
			{
				while(t0[k]!=s[i][0][j]&&j) j=nxt[i][j];
				if(t0[k]==s[i][0][j]) ++j;
				if(j==lb)
				{
					bool f=true;
					int sss=0;
					int l=k-lb+1;
					for(;sss<l&&f;++sss)
						if(t0[sss]!=t1[sss])
							f=false;
					for(;sss<=k&&f;++sss)
						if(s[i][1][sss-l]!=t1[sss])
							f=false;
					for(;sss<la&&f;++sss)
						if(t0[sss]!=t1[sss])
							f=false;
					if(f) ++sum;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
4 2
xabcx 
*/
