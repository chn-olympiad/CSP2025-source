#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("unmber.in","r",stdin);
    freopen("unmber.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1000];
	for(int i = 1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int x = a[1];
	for(int i = 1;i<n*m;i++)
	{
		for(int j = i+1;j<=n*m;j++)
		{
			if(a[j]>a[i])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	int z = 0;
	for(int i = 1;i<=n*m;i++)
	{
		if(a[i] == x)
		{
			z=i;
			break;
		}
	}
	int b = z/m,c = z%n;
	if(b%2 == 1&&c == 0)
	{
		cout<<b<<" "<<n;
	}
	else if(b%2 == 1&&c != 0)
	{
		cout<<b+1<<" "<<n-c+1;
	}
	else if(b%2 == 0&&c == 0)
	{
		cout<<b<<" "<<1;
	}
	else if(b%2 == 0&&c != 0)
	{
		cout <<b+1<<" "<<c;
	}
	
	return 0;
}
