#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005]={0},k,he=0,ans,max=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=3) cout<<1;
	else
	{
		int c;
		if(c%2==1)
		{
			cout<<0;
		}
		else
		{
			cout<<1;
		}
	}
	return 0;
}
