#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,t,k,a[N];
int C(int x,int y)
{
	y=min(x-y,y);
	int ans=1;
	for(int i=1;i<=y;i++)
	{
		ans*=(x-i+1);
		ans/=i;
		ans%=998244353;
	}
	return ans;
}
void change(bool c[N],int x)
{
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		if(c[i]) v.push_back(i);
	}
	memset(c,false,sizeof(c));
	v[x-1]++;
	int i=x-1;
	while(v[x-1]>n)
	{
		i--;
		v[i]++;
		for(int j=i+1;j<x;j++)
		{
			v[j]=v[j-1]+1;
		}
	}
	for(int i=0;i<v.size();i++)
	{
		c[v[i]]=true;
	}
}
int out(int x)
{
	int sum=0;
	bool c[N];
	memset(c,false,sizeof(c));
	for(int i=1;i<=x;i++) c[i]=true;
	while(1)
	{
		int s=0,mx=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			if(c[i])
			{
				s+=a[i];
				mx=max(mx,a[i]);
			}
		}
		if(mx*2<s) sum++;
		bool f=false;
		for(int i=1;i<=x;i++)
		{
			if(!c[n-i+1]) f=true;
		}
		if(!f) break;
		change(c,x);
	}
	return sum;
}
void solve()
{
	int sum=0;
	int i=3;
	while(i<=n)
	{
		sum+=out(i);
		sum%=998244353;
		i++;
	}
	cout<<sum;
	return ;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1)
	{
		int sum=0;
		for(int i=3;i<=n;i++)
		{
			sum+=C(n,i);
			sum%=998244353;
		}
		cout<<sum;
		return 0;
	}
	sort(a+1,a+n+1);
	solve();
	
}

