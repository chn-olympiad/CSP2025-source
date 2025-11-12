#include<bits/stdc++.h>

using namespace std;
int n,a[10000005];
int main()
{
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum=0,ma=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			sum=0;
			for(int s=i;s<=j;s++)
			{
				sum+=a[s];
				ma=max(ma,a[s]);
			}
			if(sum>ma*2&&j-i+1>=3)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
//sto sto shangshanruoshui,rp++ orz orz 
//sto sto shangshanruoshui,rp++ orz orz
//sto sto shangshanruoshui,rp++ orz orz
//freopen("polygon.in","r",stdin);(zhapian)
