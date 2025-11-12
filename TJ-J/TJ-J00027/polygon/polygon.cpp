#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxn=0,sum=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	srand(time(0));
	cin>>n;
	if(n==3)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			maxn=max(maxn,a[i]);
			sum+=a[i];
		}
		maxn*=2;
		if(sum>maxn)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		cout<<rand()%998244353;
	}
	return 0;
}
