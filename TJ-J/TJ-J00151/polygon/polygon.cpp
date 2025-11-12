#include<bits/stdc++.h>
using namespace std;
int n,num[5005],ans,sum[5005],liu,ming,hao=1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ming=n;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	if(n<3)
	{
		ans=0;
	}
	if(n==3)
	{
		if((num[0]<(num[1]+num[2]))&&(num[2]<(num[1]+num[0]))&&(num[1]<(num[0]+num[2])))
		{
			ans=1;
		}
		else
		{
			ans=0;
		}
	}
	else{
	
		for(int i=3;i<=n;i++)
		{
			hao=1;
			for(int j=1;j<=i;j++)
			{
				
				hao=hao*ming;
				ming--;
				hao=hao/j;
				ans=ans+hao;
			}
			
		}
	}
	cout<<ans;
	return 0;	
}
