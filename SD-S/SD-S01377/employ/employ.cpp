#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
int n,m;
char s[505];
int c[505];
ll inc[505],finc[505];
const ll mod=998244353;
ll ksm(ll a,ll b)
{
	ll mul=1;
	while(b)
	{
		if(b&1)
		{
			mul*=a;
			mul%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return mul;
}
void init()
{
	inc[0]=1;
	for(int i=1;i<=500;i++)
		inc[i]=inc[i-1]*i%mod;
	return ;
}
bool b[505];
int now[505];
int ans;
void dfs(int x)
{
	if(x>n)
	{
		int notnum=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				notnum++;
				continue;
			}
			if(notnum>=c[now[i]])
				notnum++;
		}
//		for(int i=1;i<=n;i++)
//			cout<<now[i]<<' ';
//		cout<<'\n';
//		cout<<notnum<<"\n";
		ans+=((n-notnum)>=m);
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!b[i])
		{
			b[i]=1;
			now[x]=i;
			dfs(x+1);
			b[i]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	init();
	scanf("%d%d",&n,&m);
	cin>>s+1;
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(n<=10)
	{
		dfs(1);
		cout<<ans<<"\n";
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=n;i++)
		if(s[i]=='0')
		{
			flag=0;
			break;
		}
	if(flag)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			cnt+=(c[i]==0);
		if(n-cnt>=m)
			cout<<inc[n]<<"\n";
		else
			cout<<"0\n";
		return 0;
	}
	return 0;
	//Thanks
}
