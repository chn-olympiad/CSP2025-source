#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int maxs=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxs=max(maxs,a[i]);
	}
	if(n==3 && maxs<=10)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
		}
		if(sum>maxs*2)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}