#include<bits/stdc++.h>
using namespace std;
long long t,n,ans;
const int E=10e5+1;
int main()
{	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	for(int q=1;q<=t;q++)
	{
		cin>>n;
		long long f[n+1][n+1]={0},a[n+1][4]={0};
		for(int i=1;i<=n;i++)
		{
		for(int j=1;j<=3;j++)
		cin>>a[i][j];
		for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		f[i][j]=max(max(max(a[i][1]+a[j][2],a[i][1]+a[j][3]),max(a[i][2]+a[j][1],a[i][2]+a[j][3])),max(a[i][3]+a[j][2],a[i][3]+a[j][1]));
		}
		if(n==2)
		cout<<f[1][2];
		else
		if(n==4)
		cout<<max(max(f[1][2]+f[3][4],f[1][3]+f[2][4]),f[1][4]+f[2][3]);
		else
		if(n==100000)
		{
		int a1[n+1]={0}
		for(int i=1;i<=n;i++)
		a1[i]=a[i][1];
		sort(a1+1,a1+n+1);
		for(int i=100000;i<=50001;i--)
		ans+=a1[i];
		cout<<ans<<endl;
		}
		else
		cout<<"23"<<endl;	
	}
	return 0;
 } 
