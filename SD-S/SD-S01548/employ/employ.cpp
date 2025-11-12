#include<iostream>
using namespace std;
#define mod 998244353
typedef long long ll;
ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
ll n,m;
const ll N=505; 
ll a[N],c[N];
bool b[N];
ll p[N];
ll ans=0;
void dfs(ll cc)
{
	if(cc==n+1)
	{
		ll cnt=0,dd=0;
		for(ll i=1;i<=n;i++)
		{
			if(dd>=c[p[i]]){
				dd++;
				continue;
			}
			if(a[i])cnt++;
			else dd++;
		}
		if(cnt>=m)ans++;
		return;
	}
	for(ll i=1;i<=n;i++)
	{
		if(!b[i])
		{
			p[cc]=i;
			b[i]=1;
			dfs(cc+1);
			b[i]=0; 
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	bool flag=1;	
	int cnt=0;
	for(ll i=1;i<=n;i++)
	{
		char x;
		cin>>x;
		a[i]=x-'0';
		if(x=='0')flag=0,cnt++;
	}

	for(ll i=1;i<=n;i++)
	{
		cin>>c[i];
		
	}
	if(cnt>m)
	{
		cout<<0;
		return 0;
	}
	if(n<=18)
	{
		dfs(1);
		cout<<ans%mod<<'\n';
	}
	else if(flag==1)
	{
		ans=1; 
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%mod;
			ans%=mod;
		}
		cout<<ans%mod;
	}
	return 0;
}

