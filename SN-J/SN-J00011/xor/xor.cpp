#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int cnt=0,ans=0;
	string a[N];
	int b[N];
	int sum=0;
	int asd=0;
	cin>>n>>k;
	if(n<=2)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]=="0")
		{
			cnt++;
			b[i]=0;
		}
		if(a[i]=="1")
		{
			ans++;
			b[i]=1;
		}
	}
	if(k==0 && ans==n)
	{
		if(n%2==0)
		{
			cout<<n/2;
			return 0;
		}
		else
		{
			int x;
			x=(n-3)/2+1;
			cout<<x;
			return 0;
		}
	}
	else if((k==0 && cnt==n) || (k==1 && ans==n))
	{
		cout<<n;
		return 0;
	}
	else if(k==0 && ans<n)
	{
		int y;
		y=ans-1;
		for(int i=1;i<=n;i++)
		{
			if(sum!=1)
			{
				if(b[i]==1)
				{
					asd=1;
					for(int j=1;j<=i;j++)
					{
						if(b[i]==0)
						{
							y++;
						}
					}
					sum=1;
					
				}
			}
			else
			{
				
				if(b[i]==1)
				{
					asd++;
				}
			}
			if(asd==ans)
			{
				asd=n-ans;
				break;
			}
		}
		y+=asd;
		cout<<y;
		return 0;
	}
	cout<<ans;
	return 0;
}
