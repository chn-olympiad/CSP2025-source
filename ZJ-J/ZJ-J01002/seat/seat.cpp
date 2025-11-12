#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int g,sum=1;
	for(int i=0;i<n*m;i++)
	{
		int x;
		cin >> x;
		if(i==0)
		{
			g=x;
		}
		else
		{
			if(x>g)
			{
				sum++;
			}
		}
	}
	int cnt1,cnt2;
	if(sum%n==0)
	{
		cnt1=sum/n;
		cnt2=n;
	}
	else
	{
		cnt1=sum/n+1;
		cnt2=sum%n;
	}
	if(cnt1%2==1)
	{
		cout << cnt1 << " ";
		cout << cnt2;
	}
	if(cnt1%2==0)
	{
		cout << cnt1 << " ";
		cout << n-cnt2+1;
	}
}
