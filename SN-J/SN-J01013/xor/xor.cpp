#include<bits/stdc++.h>
using namespace std;
int a[5*100000+5];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int cnt = 0;
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		cnt^=a[i];
		if(cnt == k)
		{
			sum++;
			cnt=0;
		}
	}
	cout<<sum;
	return 0;
}
