#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,maxn=0;
	cin >>n>>k;
	for(int i=1;i<=n;i++) cin >>a[i];
	for(int i=1;i<=n;i++)
	{
		int sum=1;
		for(int j=i;j<=n;j++)
		{
			sum=sum^j;
		}
		if(sum==k) maxn=max(maxn,n-i+1);
	}
	cout <<maxn;
	return 0;
}
