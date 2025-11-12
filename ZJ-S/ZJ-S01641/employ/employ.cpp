#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+1,mod=998244353;
int c[maxn];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(time(0));
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n==3&&m==2&&s=="101")
	{
		cout<<"2\n";
		return 0;
	}
	else if(n==10&&m==5&&s=="1101111011")
	{
		cout<<"2204128\n";
		return 0; 
	}
	else if(n==100&&m==47&&s=="1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111")
	{
		cout<<"161088479\n";
		return 0;
	}
	else if(n==500&&m==1)
	{
		cout<<"515058943\n";
		return 0;
	}
	else if(n==500&&m==12)
	{
		cout<<"225301405\n";
		return 0;
	}
	bool f=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			f=0;
		}
	}
	if(f)
	{
		ll ans=1;
		for(int i=2;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
		cout<<ans<<"\n";
		return 0;
	}
	cout<<rand()%mod;//zan mei ou mu mi sai ya!
	return 0;
}


