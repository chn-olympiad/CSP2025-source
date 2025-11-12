#include<bits/stdc++.h>
using namespace std;
int n,t;
struct club
{
	int fr,second,third;
}num[100005];
int a[100005],b[100005],c[100005];
int flag[4][100005];
int flag1=0;
int flag2=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0)
	{
		t--;
		cin>>n;	
		for(int i=1;i<=n;i++)
		{
			a[i]=0;
			b[i]=0;
			c[i]=0;
		}	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i]; 
		if((b[i]!=0)||(c[i]!=0)){
			flag1=1;
		}
		if(c[i]!=0)
		{
			flag2=1;
		}
	}
	if(flag1==0)
	{
		sort(a+1,a+n+1);
		long long ans=0;
		for(int i=n;i>n/2;i--)
		{
			ans+=a[i];
		}
		cout<<ans<<endl;
		continue;
	}
	if(flag2==0)
	{
		sort(a+1,a+n+1);
		sort(a+1,a+n+1);
		long long ans=0;
		for(int i=n;i>n/2;i--)
		{
			ans+=a[i];
		}		
		for(int i=n;i>n/2;i--)
		{
			ans+=b[i];
		}		
		cout<<ans<<endl;
	}		
	}
	return 0;
	

} 