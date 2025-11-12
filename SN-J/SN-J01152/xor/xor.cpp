#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[50010];
int sum;
int num;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[i]||a[j]==k)
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
