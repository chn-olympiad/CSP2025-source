#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(false),cout.tie(false);
	int n,k;
	cin >> n >> k;
	bool b1=0,b=0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(a[i]!=1)
		{
			b1=1;
		}
		if(a[i]!=1&&a[i]!=0)
		{
			b=1;
		}
	}
	if(!b1)
	{
		cout << n/2;
		return 0;
	}
	else if(!b)
	{
		int sum1,sum2;
		for(int i=0;i<n;i++)
		{
			if(a[i]==0)
			{
				sum1++;
			}
			else
			{
				sum2++;
			}
		}
		if(k==0)
		{
			if(sum1%2==0&&sum2%2==0) cout << sum1/2+sum2/2;
			if(sum1%2==1&&sum2%2==0) cout << sum1/2+sum2/2+1;
			if(sum1%2==0&&sum2%2==1) cout << sum1/2+sum2/2;
			if(sum1%2==1&&sum2%2==1) cout << sum1/2+sum2/2;
		}
		else if(k==1)
		{
			if(sum2>sum1)
			{
				cout << sum2;
			}
			else
			{
				cout << min(sum1,sum2)+(max(sum1,sum2)-min(sum1,sum2))/3;	
			}
		}
	}
}

