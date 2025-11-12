#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=510,mod=998244353;
ll n,m,ans,cntt;
bool cas=1;
string s;
ll c[N];
int a[19]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			cas=0;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]!=0) cntt++;
	}
	if(cntt<m)
	{
		cout<<0;
		return 0;
	}
//	cout<<cas<<endl;
	if(cas)
	{
//		cout<<cntt<<endl;
		ans=1ll;
		for(ll i=2;i<=cntt;i++)
		{
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	if(n<=18)
	{
		do
		{
			int rej=0,cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(rej>=c[a[i]])
				{
					rej++;
					continue;
				}
				if(s[i]=='0') rej++;
				else cnt++;
				if(cnt>=m)
				{
	//				for(int i=1;i<=n;i++)
	//				{
	//					cout<<a[i]<<" ";
	//				}
	//				cout<<endl;
					break;
				}
			}
			if(cnt>=m) ans++;
		}while(next_permutation(a+1,a+n+1));
		cout<<ans;
	}
	else
	{
		ans=1ll;
		for(ll i=1;i<=cntt;i++)
		{
			ans=ans*i%mod;
		}
		cout<<ans%mod;
	}
	return 0;
}//20pts

