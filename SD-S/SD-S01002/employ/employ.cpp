#include<bits/stdc++.h>
#define int long long
using namespace std;

bool Beginning;

#define mp(x,y) make_pair(x,y)
#define PII pair<int,int>
#define se second
#define fi first

const int mod=998244353;
namespace Memory_Love{
	int read(){ int x=0; bool flag=1; char ch=getchar();
		while(ch<'0' || ch>'9'){if(ch=='-') flag=0;ch=getchar();}
		while(ch>='0' && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
		return (flag? x:-x);}
	void write(int x,char ch=0){ if(x<0) x=-x,putchar('-');
		static short s[35],top=-1; do{s[++top]=x%10;x/=10;}while(x);
		while(~top) putchar(s[top--]+48); if(ch) putchar(ch);}
	int gcd(int a,int b){return (b==0? a:gcd(b,a%b));}
	int lcm(int a,int b){return a/gcd(a,b)*b;}
	int ksm(int a,int b,int p){int ans=1%p;while(b){if(b&1) ans=ans*a%p;a=a*a%p,b>>=1;}return ans;}
	int exgcd(int a,int b,int &x,int &y){if(!b){x=1,y=0; return a;}int d=exgcd(b,a%b,y,x);y-=a/b*x;return d;}
	char GetChar(){char ch=getchar();while(ch!='0' && ch!='1') ch=getchar();return ch-'0';} 
} using namespace Memory_Love;
const int N=505;
int n,m,a[N],c[N];

namespace SubTaskA
{
	bool Check()
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=1) return false;
		}
		return true;
	}
	int solve()
	{
		int i,ans=1,Num=0;
		for(i=1;i<=n;i++) Num+=(a[i]==0); 
		for(i=1;i<=n;i++) (ans*=i)%=mod;
		return ans;
	}
}

namespace Baoli
{
	int dp[(1<<20)][20],Num[N];
	int solve()
	{
		int i,j,k,S;
		for(i=1;i<=n;i++)
		{
			if(a[i]==0) Num[i]=0;
			else Num[i]=Num[i-1]+1;
		}
		for(i=1,dp[0][0]=1;i<=n;i++)
		{
			for(k=1;k<=n;k++)
			for(S=1;S<(1<<n);S++)
			{
				if(__builtin_popcount(S)!=i) continue;
				for(j=0;j<n;j++)
				{
//					for(last=0;last<=n;last++)
					{
						if((S>>j&1) && Num[i-1]<c[j+1])
						{
							int x=(Num[i-1]<c[j+1]);
							(dp[S][k+(a[i]==0 && x)]+=dp[(S^(1<<j))][k])%=mod; 	
						}
					}
				}
			}
		}
		int ans=0;
		for(i=m;i<=n;i++) (ans+=dp[(1<<n)-1][i])%=mod;
		return ans;
	}
}

bool Ending;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("employ1.in","r",stdin);
	int i; n=read(),m=read();
	for(i=1;i<=n;i++) a[i]=GetChar();
	for(i=1;i<=n;i++) c[i]=read();
	if(m>n){write(0,'\n');return 0;}
	if(SubTaskA::Check()) write(SubTaskA::solve(),'\n');
	else write(Baoli::solve(),'\n');
	cerr<<"\nused "<<(abs(&Ending-&Beginning)/1048576)<<" MB\n";
	return 0;
}
