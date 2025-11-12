#include<bits/stdc++.h>
using namespace std;
int a[5005],sum,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	else if(n==3)
	{
		if((a[1]+a[2]+a[3])<=(a[3]*2))
		{
			cout<<0;
		}
		else
		{
			cout<<1;
		}
		return 0;
	}
	else
	{
		for(int i=3;i<=n;i++)
		{
			for(int l=1;l<=i-2;l++)
			{
				for(int j=l;j<=i;j++)
				{
					sum+=a[j];	
				}
				if(sum>(a[i]*2))
				{
					ans++;
				}
				sum=0;
			}
		}
		cout<<ans;
	}
	return 0;
}
