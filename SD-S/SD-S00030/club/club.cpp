#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rg register
#define pii pair<int,int>
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
const int N=1e5+10;
int t,n,los;
int sum[4],ans[4];
pii a[N][4];
vector<pair<int,int> > v[4];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		los=0;
		for(int i=1;i<=3;++i)
		{
			v[i].clear();
			sum[i]=ans[i]=0;
		}
		iread(n);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=3;++j)
			{
				iread(a[i][j].first);
				a[i][j].second=j;
			}
			sort(a[i]+1,a[i]+4);
			++sum[a[i][3].second];
			rg int pun=a[i][3].first-a[i][2].first;
			v[a[i][3].second].emplace_back(-pun,i);
		}
		for(int i=1;i<=3;++i)
		{
			if(sum[i]>n/2)
			{
				sort(v[i].begin(),v[i].end());
//				sum[i]=n/2;
				int l=v[i].size();
				for(int k=n/2;k<l;++k)// update
					los+=-v[i][k].first;
			}
			for(int j=0;j<sum[i];++j)
				ans[i]+=a[v[i][j].second][3].first;
		}
		cout<<ans[1]+ans[2]+ans[3]-los<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

