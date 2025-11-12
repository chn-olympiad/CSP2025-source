#include<iostream> 
using namespace std;
int a[20000];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,i,j,t;
	cin>>n;
	if(n%2==0)
	{
		for (int i=1;i<=n;i++)
		{
			cin>>i>>j>>t;
			if(i==n%2&&j==n%2&&t==n%2)
			{
				if(n%3==0)
				{
					a[i]++;
				}
			}
		}
		cout<<a<<endl;
	}
	return 0;
}
