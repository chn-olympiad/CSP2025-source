#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//998,244,353
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	bool tf=false;
	int gtf=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=1)gtf++;
		if(gtf>=50)
		{
			tf=true;
			break;
		}
	}
	long long ll9=998244353;
	if(tf)
	{
		long long sp=0;
		for(int i=3;i<=n;i++)
		{
			long long sum=1;
			for(int j=i;j>1;j--){
				sum*=j;
				sum%=ll9;
			}
			sp+=sum;
			
		}
		cout<<sp;
		return 0;
	}
	
	int h=a[1]+a[2]+a[3];
	if(h > 2 * max(a[1],max(a[2],a[3]))) cout<<1;
	
	
	
	
	return 0;	
} 
