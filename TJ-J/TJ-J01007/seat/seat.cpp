#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10500];
	for (int i=1;i<=n*m;i++)
	{

			cin>>a[i];

	}
	int k=1;
	for (int i=1;i<=n*m;i++)
	{
		for (int j=i+1;j<=n*m;j++)
		{
			if(a[i]<=a[j])
			{
				swap(a[i],a[j]);
				if(i==k) k=j;
				else if(j==k) k=i;

			}

		}
	}
	if(k%n==0)
	{
		if ((k/n)%2==0)cout<<k/n<<" "<<1;
		else cout<<k/n<<" "<<m;
	}
	else
	{
		cout<<k/n+1<<" ";
		if ((k/n+1)%2==0) cout<<m+1-k%n;
		else cout<<k%n;
	}
	return 0;
}
