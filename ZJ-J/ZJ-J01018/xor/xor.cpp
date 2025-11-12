#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k;
int a[N];
int pre[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		pre[i]=pre[i-1]^a[i];
	if (k==0)
	{
		cout<<n/2;
		return 0;
	}
	else if (k==1)
	{
		int j=1;
		int num=0;
		for (int i=1;i<=n;i++)
		{
			if ((pre[i]^pre[j])==k)
				num++,j=i;
		}
	}
	else
	{
		int j=1;
		int num=0;
		for (int i=1;i<=n;i++)
		{
			if ((pre[j]^pre[i-1])==k)
				num++,j=i;
			else
				j++;
		}
		cout<<num;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
