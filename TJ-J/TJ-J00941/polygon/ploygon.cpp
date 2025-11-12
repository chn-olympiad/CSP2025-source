#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1000005;
const ll M=1005;
ll n,m,T,a[N],b[N],f[M][M],ans;
int main()
{
	
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		for(int j=0;j<=i-2;j++)
		{
			if(b[i]-b[j]>a[i]*2)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
