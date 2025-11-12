#include<bits/stdc++.h>
using namespace std;
int a[500005];
int res[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	res[1]=0;
	for (int i=2;i<=500005;i++)
	{
		if(i%2==0)
		{
			res[i]=i/2;
		}
		else
		{
			res[i]=(i-1)/2;
		}
	}
	if(k==0)
	{
		cout<<res[n]<<endl;
	}
	else
	{
		cout<<res[n]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// 2 0
// 1 1
