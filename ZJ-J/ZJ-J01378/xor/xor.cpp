#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],d[500001],dd[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(i==1)
		  d[i]=a[i];else
		  d[i]=d[i-1]^a[i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)
		{	
			if(j!=0)
			{
				if((d[i]^d[j-1])==k)
				{
					dd[i]=max(dd[i],dd[j-1]+1);
				}
			}else
				if(d[i]==k)
					dd[i]=max(dd[i],1);
		}
		dd[i]=max(dd[i],dd[i-1]);
	}
	cout<<dd[n];
	return 0;
}