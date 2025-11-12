#include<bits/stdc++.h>
using namespace std;
bool han(int x,int y)
{
	if(x>y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int b=a[1];
	sort(a+1,a+m*n+1,han);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			if(i%n==0)
			{
				if(i/n%2==1)
				{
					cout<<i/n<<" "<<n;
				}
				else
				{
					cout<<i/n<<" "<<1;
				}
			}
			else
			{
				int c=i/n+1;
				int d=i%n;
				if(c%2==1)
				{
					cout<<c<<" "<<d;
				}
				else
				{
					cout<<c<<" "<<n-d+1;
				}
			}
			fclose(stdin);
			fclose(stdout);
			
			return 0;
		}
	}
}
