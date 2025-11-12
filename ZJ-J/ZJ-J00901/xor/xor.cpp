#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans=0;
	scanf("%d%d",&n,&k);
	for(long long i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
		{
			ans++;
		}
	}
	if(k==0)
	{
		printf("%d",ans/2);
	}
	else
	{
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}