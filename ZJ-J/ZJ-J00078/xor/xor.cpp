#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);	
	}
	int l=0,cnt=0;
	for(int r=1;r<=n;r++)
	{
		int cur=0;
		for(int j=r;j>l;j--)
		{
			cur^=a[j];
			if(cur==k)
			{
				l=r;
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
}