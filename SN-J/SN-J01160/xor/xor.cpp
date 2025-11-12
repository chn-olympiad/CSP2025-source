#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
int n,k;
int a[M];
int b[M];
int c[M];//c[i]为i~n ok数组最小值 
int ok[M];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;i+j<=n;j++)
		{
			if((b[i+j]^b[i-1])==k)
			{
				ok[i]=i+j;
				break;
			}
		}
		if(ok[i]==0) ok[i]=n+1;
	}
	c[n+1]=0x7fffffff;
	for(int i=n;i>0;i--)
	{
		c[i]=min(c[i+1],ok[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i=c[i]+1)
	{
		if(c[i]!=n+1) ans++;
	}
	cout<<ans<<"\n";
	return 0; 
}
