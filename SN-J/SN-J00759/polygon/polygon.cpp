#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long maxn=0;
	long long cnt0=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(a[i]==0) cnt0--;
	}
	//cout<<cnt0;
	int cnt=0;
	if(maxn==1)
	{
		//cout<<"a";
		for(int i=3;i<=cnt0;i++)
		{
			int cnt1=1;
			int cnt2=1;
			for(int j=1;j<=i;j++)
			{
				cnt1*=j;
			}
			for(int j=cnt0;j>=cnt0-i+1;j--)
			{
				cnt2*=j;
			}
			cnt+=cnt2/cnt1;
			//cout<<cnt1<<" "<<cnt2<<endl;
			cnt1=1;
			cnt2=1;
		}
	}
	else
	{
		for(int i=1;i<=n-2;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				long long ans=0;
				long long maxx=0;
				for(int k=i;k<=j;k++)
				{
					ans+=a[k];
					maxx=max(maxx,a[k]);
				}
				if(ans>2*maxx) 
				{
					cnt++;
				}
			}
		}
	}
	cout<<cnt%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
