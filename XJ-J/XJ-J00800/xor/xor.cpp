#include<bits/stdc++.h>
using namespace std;
const int N=1e5+500;
long long n,t,b[N],sum,cnt,vis[N],f[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long sum=b[i];
		for(int j=i-1;j>=0;j--)
		{
			f[i]=max(f[i],f[j]+(sum==t));
			sum^=b[j];
		}
	}
	cout<<f[n];
	return 0;
} 
