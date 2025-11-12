#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010,M=998244353;
int n,a[N];
//int c[N][N];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>a[3]*2) ans++;
		cout<<ans%M<<"\n";
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		int fz=1;
		for(int j=n;j>i;j--)
		{
			fz*=j%M;
			fz%=M;
		}
		int fm=1;
		for(int j=1;j<=n-i;j++)
		{
			fm*=j%M;
			fm%=M;
		}
		int fs=fz/fm;
		//c[i][n]=fs;
		ans+=fs%M;
		ans%=M;
	}
	cout<<ans%M<<"\n";
	return 0;
}
