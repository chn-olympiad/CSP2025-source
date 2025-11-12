#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int flag1=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)
		{
			flag1=1;
			break;
		}
	}
	if(flag1==0&&k==0)
	{
		int x=n/2;
		cout << x;
		return 0;
	}
	int flag2=0,p=0,q=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>1)
		{
			flag2==1;
			break;
		}
		if(a[i]==0)
		{
			p++;
		}
		if(a[i]==1)
		{
			q++;
		}
	}
	if(flag2==0&&k<=1)
	{
		if(k==0)
		{
			int x=p;
			cout << x;
			return 0;
		}
		if(k==1)
		{
			int x=q;
			cout << x;
			return 0;
		}
	}
	return 0;
}
