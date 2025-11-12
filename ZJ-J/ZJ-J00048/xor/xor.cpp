#include<bits/stdc++.h>
using namespace std;
int a[500001],p[1048576];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,last,ans,sum;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(p,-1,sizeof(p));
	p[0]=0;
	sum=0;
	last=0;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		sum^=a[i];
		if(p[sum^k]>=last)
		{
			ans++;
			last=i;
		}
		p[sum]=i;
	}
	cout<<ans;
	return 0;
}
