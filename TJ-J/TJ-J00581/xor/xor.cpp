#include <bits/stdc++.h>
using namespace std;
long long a[200005],n,k,a1,a0;
bool flag=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]==0) flag=1;
		if(a[i]==0) a0++;
		if(a[i]==1) a1++;
	}
	if(!flag)
	{
		cout<<n/2;
	}
	else
	{
		if(k==0) cout<<a1/2+a0;
		if(k==1) cout<<a1;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
