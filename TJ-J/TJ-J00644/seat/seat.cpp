#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[1005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{
			int p;
			if(i%n==0)
			{
				cout<<i/n<<" ";
				p=i/n;
			}
			else 
			{
				cout<<i/n+1<<" ";
				p=i/n+1;
			}
			if(p%2==0)
			{
				if(i%n==0)
				{
					cout<<1;
				}
				else cout<<n-i%n+1;
			}
			else
			{
				if(i%n==0)
				{
					cout<<n;
				}
				else cout<<i%n;
			}
		}
	}
	return 0;
}
