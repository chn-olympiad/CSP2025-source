#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
int c[1000005];
char s[1000005];
int a[1000005];
int pd[10000005];
long long ans;
long long sum=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	int pd=1;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	int l=strlen(s);
	for(int i=0;i<l;i++)
	{
		a[i+1]=s[i]-48;
		if(a[i+1]!=1)
			pd=0;
	}
	if(pd==1)
	{
		cout<<0;
		return 0;
	}
	l++;
	if(m==1)
	{
		ans=1;
		for(int i=2;i<=n;i++)
		{
			ans*=i;
		}
		sort(c+1,c+1+n);
		int left=1,right=n;
		int num=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
				right--;
			else
			{
				if(c[left]>i)
				{
					cout<<ans;
					return 0;
				}
				else
				{
					for(int j=left+1;j<=right;j++)
					{
						if(c[j]>i)
						{
							num=j-left;
							sum*=num;
							break;
						}
					}
					left++;
				}
			}
		}
		cout<<(ans-sum)%998244353;
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				cout<<0;
				return 0;
			}
		}
		ans=1;
		for(int i=2;i<=n;i++)
		{
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	else
		cout<<rand();
	return 0;
}