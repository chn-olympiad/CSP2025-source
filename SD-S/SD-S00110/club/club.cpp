#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
inline int read()
{
	int s=0;char c=getchar();bool f=0;
	for(;!isdigit(c);c=getchar())f|=(c=='-');
	for(;isdigit(c);c=getchar())s=(s<<1)+(s<<3)+(c^48);
	return f?-s:s;
}
const int mod=1e9+7;
inline int qpow(int x,int p)
{
	int res=1;
	while(p)
	{
		if(p&1)res=1ll*x*res%mod;
		x=1ll*x*x%mod;
		p>>=1;
	}
	return res;
}
const int N=1e5+7;
int n,dp[207][207],a[N][4],ans,flag[4];
inline void solve()
{
	int p;
	int lim=(n>>1);
	for(int k=1;k<=n;k++)
	{
		for(int i=k;i>=0;i--)
			for(int j=k-i;j>=0;j--)
			{
				p=k-i-j;
				if(p>0)dp[i][j]=max(dp[i][j],dp[i][j]+a[k][3]);
				if(i>0)dp[i][j]=max(dp[i][j],dp[i-1][j]+a[k][1]);
				if(j>0)dp[i][j]=max(dp[i][j],dp[i][j-1]+a[k][2]);
			}
	}
	for(int i=0;i<=lim;i++)
		for(int j=0;j<=lim;j++)
		{
			if(n-i-j<=lim)ans=max(dp[i][j],ans);
		}
	printf("%d\n",ans);
}
int aa[N];
bool cmp1(int ta,int tb){return ta>tb;}
inline void solveA()
{
	for(int i=1;i<=n;i++)aa[i]=a[i][1];
	sort(aa+1,aa+1+n,cmp1);
	int lim=(n>>1);
	for(int i=1;i<=lim;i++)ans+=aa[i];
	printf("%d\n",ans);
}
int bdp[(N>>1)];
inline void solveB()
{
	memset(bdp,0,sizeof(bdp));
	for(int i=1;i<=n;i++)
		for(int j=i;j>=0;j--)
		{
			bdp[i]=max(bdp[i]+a[i][2],bdp[i]);
			if(j>0)bdp[i]=max(bdp[i-1]+a[i][1],bdp[i]);
		}
	printf("%d\n",bdp[(n>>1)]);
}
inline void init()
{
	flag[1]=flag[2]=flag[3]=flag[0]=0;
	memset(dp,0,sizeof(dp));
	ans=0;
	n=read();
	int lim=(n>>1);
	for(int k=1;k<=n;k++)
	{
		for(int j=1;j<=3;j++)
			a[k][j]=read(),flag[j]|=(int)(a[k][j]>0);
	}
	flag[0]=flag[1]+flag[2]+flag[3];
	if(n<=200)
	{
		solve();
	}
	else if(flag[0]<=1)
	{
		solveA();
	}else if(flag[0]==2)solveB();
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int tt=read();
	for(;tt;tt--)
	{
		init();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
inline int read()
{
	int s=0;char c=getchar();bool f=0;
	for(;!isdigit(c);c=getchar())f|=(c=='-');
	for(;isdigit(c);c=getchar())s=(s<<1)+(s<<3)+(c^48);
	return f?-s:s;
}
const int mod=1e9+7;
inline int qpow(int x,int p)
{
	int res=1;
	while(p)
	{
		if(p&1)res=1ll*x*res%mod;
		x=1ll*x*x%mod;
		p>>=1;
	}
	return res;
}
const int N=1e5+7;
const int INF=0x3f3f3f3f;
int n,cnt[4],ans;
struct Node{
	int a[4],id,mid;
	bool operator <(const Node &B)const
	{
		return a[0]>B.a[0];
	}
}a[N],b[N];
inline void mmax(int x)
{
	for(int i=x;i<=n;i++)
	{
		b[i].a[0]=-INF;
		for(int j=1;j<=3;j++)
			if(cnt[j]>0&&b[i].a[j]>b[i].a[0])b[i].a[0]=b[i].a[j],b[i].mid=j;
	}
}
inline void init()
{
	n=read();
	ans=0;
	cnt[1]=cnt[2]=cnt[3]=(n>>1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)a[i].a[j]=read();
		for(int j=1;j<=3;j++)b[i].a[j]=a[i].a[j]+a[i].a[j]-(a[i].a[1]+a[i].a[2]+a[i].a[3]),b[i].id=i;
	}
	mmax(1);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
	{
//		cout<<b[i].id<<" "<<b[i].mid<<endl;
		ans+=a[b[i].id].a[b[i].mid];
		cnt[b[i].mid]--;
		if(cnt[b[i].mid]<=0)
		{
			mmax(i+1);
			sort(b+1+i,b+1+n);
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int tt=read();
	for(;tt;tt--)
	{
		init();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//1,4,5 AC
//2,3 WA
*/
