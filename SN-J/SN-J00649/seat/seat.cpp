//SN-J00649  林靖轩  西安辅轮中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt,sum,pan=0;
int a[110];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	cnt=a[1];
	sort(a+1,a+n*m+1);
//	for(int i=1;i<=n*m;i++)
//		cout<<a[i]<<" ";
	for(int i=n*m;i>=1;i--)
		if(a[i]==cnt)
		{
			sum=n*m+1-i;
			break;
		}
//		cout<<sum<<"\n";

	
	
	if(sum%n==0)
	{
		cout<<sum/n<<" ";
		if((sum/n)%2==1)pan=1;
		else pan=2;
		
		
		if(pan==1)cout<<n;
		else cout<<1;
	}
	else
	{
		cout<<sum/n+1<<" ";
		
		if((sum/n+1)%2==1)pan=1;
		else pan=2;
		
		
		
		if(pan==1)
		{
			if(sum%n==0)
			cout<<1;
			else 
			cout<<sum%n;
		}
		else
		{
			if(sum%n==0)
			cout<<n;
			else 
			cout<<n-sum%n+1;
		}
	}
	
	return 0;
}

