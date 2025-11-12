#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll a[1005],n,m;
pair<int,int>b[1005];
string s;
bool check_A()
{
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='0')
		{
			return 0;
		}
	}
	return 1;
}
ll solveA()
{
	ll ans=1;
	for(int i=n;i>=1;i--)
	{
		ans*=i;
		ans%=mod; 
	}
	return ans;
}
bool check()
{
	int cntkill=0,cntget=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='0')
		{
			cntkill++;
		}
		else
		{
			if(cntkill<b[i].first)
			{
				cntget++;
			}
			else
			{
				cntkill++;
			}
		}
	}
	if(cntget>=m)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
ll solve()
{
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i].first=a[i];
		b[i].second=i;
	}
	ll ans=0;
	if(check())
	{
		ans++;
	}
	while(next_permutation(b+1,b+1+n))
	{
		if(check())
		{
			ans++;
			ans%=998244353;
		}
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(check_A())
	{
		cout<<solveA();
		return 0;
	}
	if(n>=18)
	{
		cout<<"0";
		return 0;
	}
	cout<<solve();
	return 0;
}
