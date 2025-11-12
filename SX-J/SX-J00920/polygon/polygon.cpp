#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e6+10,M=998244353;
int n,a[N],r;
ll ans,f[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		r+=a[i];
	}
	sort(a+1,a+1+n);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=r;j++) 
		{
			ans+=f[j];
			ans%=M;
		}
		for(int j=r;j>=a[i];j--)
		{
			f[j]+=f[j-a[i]];
			f[j]%=M;
		}
	}
	cout<<ans;
	return 0;
}