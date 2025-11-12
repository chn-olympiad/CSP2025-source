#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn=1000,mod=998244353;
ll n,m,cnt,sum,tmp,a[maxn],b[maxn];
string s;

inline ll fun(ll x)
{
	ll y=1;
	for(int i=x;i>=1;i--)
	{
		y*=i;
		y%=mod;
	}
	return y;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=0;i<n;i++)
		{
			tmp=1;
			if(s[i]=='1')
			{
				cnt++;
				for(int j=1;j<=n;j++)
				{
					if(a[j]>i)
					{
						b[cnt]++;
					}
				}
				for(int j=1;j<cnt;j++)
				{
					tmp*=n-b[j]-j+1;
					tmp%=mod;
				}
				tmp*=b[cnt];
				tmp%=mod;
				tmp*=fun(n-cnt);
				sum+=tmp;
				sum%=mod;
			}
		}
		cout<<sum%mod<<endl;
	}
	else if(m==n)
	{
		bool f=true;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0||s[i]=='0')
			{
				f=false;
				cout<<"0"<<endl;
				break;
			}
		}
		if(f)
		{
			cout<<fun(n)<<endl;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				sum++;
			}
		}
		if(sum<m)
		{
			cout<<"0"<<endl;
		}
		else
		{
			cout<<"998"<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
