#include<iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n,a[10005]={0},max=-1,he=0,ans=0;
	cin>>n;
	if(n==3)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(max<a[i])
			{
				max=a[i];
			}
			he=he+a[i];
		}
		if(he>2*max)
		{
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	if(n>3)
	{
		int l=1,c=3;
	
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]; 
		 } 
		 for(int i=1;i<=n-2;i++)
		 {	he=0;
		max=-1;
		l=1;
		for(int t=1;t<=n-c+1;t++)
		{
		max=-1;he=0;
			for(int j=l;j<l+c;j++)
		 	{
		 		he=he+a[j];
		 		if(a[j]>max)
		 		{
		 			max=a[j];
				 }
				 
			 }
			 if(max*2<he)
			 {
			 	ans++;
			 }
			 l++;
			 max=-1;
		}
		 c++;	
		 }
		 cout<<ans;
	}
	return 0;
 } 
