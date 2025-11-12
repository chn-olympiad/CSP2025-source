#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define lc (u<<1)
#define rc (u<<1|1)
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define Min(a,b) ((a)>(b)?(a)=(b);1)
#define Max(a,b) ((a)<(b)?(a)=(b);1)
using namespace std;
const int N=510,mod=998244353;
bool MS;int uesd,id;
int n,m;
int s[N];
int c[N];
void solve()
{
	
}
namespace force
{
	int f[(1<<18)][18];
	void getans()
	{
		f[0][0]=1;
		rep(i,0,(1<<n)-1)
		{
			int now=__builtin_popcount(i);
			rep(k,0,n)//k是当前已经有的合法个数 
			rep(j,1,n)
			if((1<<j-1)&i);//枚举下一个位置 
			else
			{
				if(now-k>=c[j]||s[now+1]==0)//不做贡献
				f[i|(1<<j-1)][k]+=f[i][k]; 
				else
				f[i|(1<<j-1)][k+1]+=f[i][k]; 
			}
		}
		int ans=0;
		rep(i,m,n)
		ans+=f[(1<<n)-1][i];
		cout<<ans%mod<<'\n';
	}//考虑前几个位置上的数 
}
namespace A
{
	int f[N][N];//填了i个数，此时前边合法的数量有j个 
	void getans()
	{
		int ans=0;
		rep(exp,0,n-m)//预期个数 
		{
			memset(f,0,sizeof f);
			f[0][0]=1;
			rep(i,1,n)
			{
				rep(j,0,i-1)
				{
					(f[i][j+1]+=f[i-1][j]*(min(exp+1,c[i])+j))%=mod;//这个点是合法的
					(f[i][j]+=f[i-1][j]*max(0ll,(i-1-j+1-c[i])))%=mod;//这个点是不合法的
				}
			}
			ans+=f[n][n-exp];
//			cout<<"failed with "<<exp<<" pos:"<<f[n][n-exp]<<'\n';
			ans%=mod;
		}
		cout<<ans<<'\n';
	}
}
namespace nm
{
	void getans()
	{
		rep(i,1,n)
		if(c[i]==0)
		{
			cout<<"0\n";
			return;
		}
		rep(i,1,n)
		if(s[i]==0)
		{
			cout<<"0\n";
			return;
		}
		int res=1;
		rep(i,1,n)
		res=res*i%mod;
		cout<<res<<'\n';
	}
}
bool MT;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	rep(i,1,n)
	{
		char u;
		cin>>u;
		s[i]=u-'0';
	}
	rep(i,1,n)
	cin>>c[i];
	sort(c+1,c+n+1);
	if(n<=18)
	{
		force::getans();
	}
	else if(n==m)
	{
		nm::getans();
	}
	else
	{
		A::getans();
	}
	cerr<<"Memory:"<<(&MS-&MT)/1048576.0<<"MB Time"<<clock()<<"ms\n";
}
/*
问题是，对于所有排列求权值>=k的排列个数

权值的定义是对于一个位置做贡献，当且仅当，在其前边没有做贡献的点的数量<c_i 个。

50min过了A会了BC，优势在我！

容易做的是18，记录哪些人被选了，以及当前败选的人数

五点半了还没想法就拼暴力

考虑A性质 

考虑首先插入被删除的点，然后考虑插入不被删除的点。

不被删除的点能插入的是一段前缀区间。

比如某个元素对于现在的非法序列，其能插入在i之前的空位上（也就是有i个位置可以插入，也就是等价于 min(len+1,ci)），<=其的合法数量有k个。
则最终贡献 i+k 的系数。

非法状态，同样考虑从小往大插入，则其能放入的是序列的一段前缀。 

所以dp就是简单的了，考虑设 $f_{i,j,k}$ 表示考虑了前i个元素，此状态预计要选j个非法状态，并且此时的已经选了k个合法状态了。

转移考虑当前元素是合法或者非法，非法则贡献其选择非法序列的一段后缀的系数。

合法则贡献 min(j+1,ci)+k 的系数。

写一发先试试

m=n似乎是一个唐诗点

注意到m=n首先要求c不能有0，其次要求s不能有0，那么这种状态下答案就是 n!了

44pts
*/