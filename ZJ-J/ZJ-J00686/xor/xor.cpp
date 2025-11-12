#include<bits/stdc++.h>
using namespace std;
int n,k,x,cnt;
int a[5000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			if((a[r]^a[l-1])==k)
			{
				cnt++;
				l=r+1;
			}
		}
	}
	printf("%d",cnt);
	return 0;
} 