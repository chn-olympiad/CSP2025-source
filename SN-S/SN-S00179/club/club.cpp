//岳颢晨 SN-J00179 西安滨河学校 
#include<bits/stdc++.h>
bool f(int a,int b)
{
	if(a>b)
	{
		return 1;
	 } 
	return 0;
}
using namespace std;
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,a[100000],b[100000],c[100000];
		cin>>n;
		int max1=n/2;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
		}
		sort(a+1,a+1+n,f);
		sort(b+1,b+1+n,f);
		sort(c+1,c+1+n,f);
		int sum1=0,sum2=0,sum3=0;
		for(int j=1;j<=n;j++)
		{
			sum1+=a[j];
			sum2+=b[j];
			sum3+=c[j];
		}
		if(max(sum1,max(sum2,sum3))==sum1)
		{
			int sum4=0;
			for(int k=1;k<=max1;k++)
			{
				sum4+=a[k];
			}
			for(int k=max1-1;k<=n-max1;k++)	
			{
				if(b[k]>c[k])
				{
					sum4+=b[k];
				}
				else
				{
					sum4+=c[k];
				}
			}
			cout<<sum4<<endl;
		}
		if(max(sum1,max(sum2,sum3))==sum2)
		{
			int sum5=0;
			for(int j=1;j<=max1;j++)
			{
				sum5+=b[j];
			}
			for(int j=max1-1;j<=n-max1;j++)	
			{
				if(a[j]>c[j])
				{
					sum5+=a[j];
				}
				else
				{
					sum5+=c[j];
				}
			}
			cout<<sum5<<endl;
		}
		if(max(sum1,max(sum2,sum3))==sum3)
		{
			int sum6=0;
			for(int j=1;j<=max1;j++)
			{
				sum6+=c[j];
			}
			for(int j=max1-1;j<=n-max1;j++)	
			{
				if(a[j]>b[j])
				{
					sum6+=a[j];
				}
				else
				{
					sum6+=b[j];
				}
			}
			cout<<sum6<<endl;
		}
	}
	return 0;
}

