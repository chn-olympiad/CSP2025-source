#include<bits/stdc++.h>
using namespace std;
const int MA=1000005;
int b[MA],k,a[MA][3],a1[MA][3],a2[MA][3],a3[MA][3];
int main() 
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	 	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		k=n/2;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				
			}
		}
		ans=0;
		if(a[1][2]==0&&a[1][3]==0)
		{
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			for(int i=n;i>k;i--)
			{
				ans+=b[i];
			}
		}else if(n==2)
		{
			b[1]=a[1][1]+a[2][2];
			b[2]=a[1][1]+a[2][3];
			b[3]=a[1][2]+a[2][1];
			b[4]=a[1][2]+a[2][3];
			b[5]=a[1][3]+a[2][1];
			b[6]=a[1][3]+a[2][2];
			int maxx=0;
			for(int j=1;j<=6;j++)
			{
				maxx=max(maxx,b[j]);
			}
		
			ans=maxx;
		}else
		{
			int max1=0;
			for(int i=1;i<=n;i++)
			{
				max1=max(a[i][1],a[i][2]);
				max1=max(max1,a[i][3]);
				ans+=max1;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
