#include <bits/stdc++.h>
using namespace std;
const int N=1000001,M=1001,mod=998244353;
int n,a[N],s,ans,F,f;
long long q[N];
bool cmp (int x,int y)
{
	return x>y;
}
int main ()
{
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);cout.tie (0);
	cin >>n;
	for (int i=1;i<=n;i++)
	{
		cin >>a[i];
		if (a[i]>1) F=1;
		if (a[i]==1) f++;
	}
	if (n<3) return cout <<0,0;
	if (n==3&&max (a[1],max (a[2],a[3]))*2<a[1]+a[2]+a[3]) return cout <<1,0;
	if (n==3&&max (a[1],max (a[2],a[3]))*2>=a[1]+a[2]+a[3]) return cout <<0,0;
	if (F==1)
	{
		sort (a+1,a+1+n,cmp);
		for (int i=1;i<=n-2;i++)
		{
			s=a[i];
			for (int j=n;j>=i;j--)
			{
				s=s+a[j];
				if (s>a[i]*2&&j-i>=2)
				{
					ans=ans+(j-i)+(n-j+1)*(j-i-1);
					ans=ans%mod;
					break;
				}
			}
		}
		cout <<ans%mod;
	}
	if (F==0)
	{
		for (int i=3;i<=f;i++) q[i]=a[i-1]+(i-2)*(i-2)+q[i-2],q[i]=q[i]%mod;
		cout <<q[f]%mod;
	}
	return 0;
}
