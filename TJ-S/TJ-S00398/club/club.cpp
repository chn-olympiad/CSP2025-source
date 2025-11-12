#include<bits/stdc++.h>
using namespace std;
long long a[10005][1005][5],ans[10005][1005],n[1005],t,k[10005][1005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>n[i];
		for(int j=1;j<=n[i];j++)
		{
			cin>>a[i][j][1]>>a[i][j][2]>>a[i][j][3];  
			if(a[i][j][1]>a[i][j][2]>a[i][j][3]||a[i][j][1]>a[i][j][3]>a[i][j][2]&&k[i][1]<=n/2)
			{
				k[i][1]++;
				ans[i][1]+=a[i][j][1];
			}
			else if(a[i][j][2]>a[i][j][3]>=a[i][j][1]||a[i][j][2]>a[i][j][1]>a[i][j][3]&&k[i][2]<=n/2)
			{
				k[i][2]++;
				ans[i][2]+=a[i][j][2];
			}
			else if(a[i][j][3]>a[i][j][2]>a[i][j][1]||a[i][j][3]>a[i][j][1]>a[i][j][2]&&k[i][3]<=n/2)
			{
				k[i][3]++;
				ans[i][3]+=a[i][j][3];
			}
			if(a[i][j][1]>a[i][j][2]>a[i][j][3]||a[i][j][1]>a[i][j][3]>a[i][j][2]&&k[i][3]<=n/2)
			{
				k[i][1]++;
				ans[i][1]+=a[i][j][1];
			}
			else if(a[i][j][2]>a[i][j][3]>=a[i][j][1]||a[i][j][2]>a[i][j][1]>a[i][j][3]&&k[i][2]<=n/2)
			{
				k[i][2]++;
				ans[i][2]+=a[i][j][2];
			}
			else if(a[i][j][3]>a[i][j][2]>a[i][j][1]||a[i][j][3]>a[i][j][1]>a[i][j][2]&&k[i][1]<=n/2)
			{
				k[i][3]++;
				ans[i][3]+=a[i][j][3];
			}if(a[i][j][1]>a[i][j][2]>a[i][j][3]||a[i][j][1]>a[i][j][3]>a[i][j][2]&&k[i][1]<=n/2)
			{
				k[i][1]++;
				ans[i][1]+=a[i][j][1];
			}
			else if(a[i][j][2]>a[i][j][3]>=a[i][j][1]||a[i][j][2]>a[i][j][1]>a[i][j][3]&&k[i][2]<=n/2)
			{
				k[i][2]++;
				ans[i][2]+=a[i][j][2];
			}
			else if(a[i][j][3]>a[i][j][2]>a[i][j][1]||a[i][j][3]>a[i][j][1]>a[i][j][2]&&k[i][1]<=n/2)
			{
				k[i][3]++;
				ans[i][3]+=a[i][j][3];
			}
		}
	 } 
	return 0;
	
}
