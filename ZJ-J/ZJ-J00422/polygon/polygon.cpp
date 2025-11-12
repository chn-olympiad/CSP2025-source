#include<bits/stdc++.h>
using namespace std;
int a[5005];
int res[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int x=-999999;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		x=max(x,a[i]);
	}
	
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*x)
		{
			cout<<1<<endl;

		}
		else
		{
			cout<<0<<endl;
		}
	}
	else
	{
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
