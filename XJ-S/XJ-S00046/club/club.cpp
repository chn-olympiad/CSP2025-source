#include<iostream>
using namespace std;
int a[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=3; j++)
			{
				cin>>a[i];
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n-1; j++)
			{
				if(a[j]<a[j+1])
				{
					swap(a[j],a[j+1]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<a[i];
		}
	}
	return 0;
}
