#include<bits/stdc++.h>
using namespace std;
int len;
int n;
int a[4]={};
int c1,c2,c3;
int c4,c5,c6,c7,c8,c9;
int maxn=0,num=0,num1,ans=0;
int max1=0,max2=0,max3=0;
int id1,id2,id3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>len;
	for(int t=0;t<len;t++)
	{
		maxn=0;
		num=0;
		num1=0;
		ans=0;
		for(int i=0;i<4;i++) a[i]=0;
		cin>>n;
		if(n==2)
		{
			cin>>c4>>c5>>c6>>c7>>c8>>c9;
			for(int i=0;i<3;i++)
			{
				if(i==0) num1+=c4;
				if(i==1) num1+=c5;
				if(i==2) num1+=c6;
				if(i==0) num1+=max(c8,c9);
				if(i==1) num1+=max(c7,c9);
				if(i==2) num1+=max(c7,c8);
				num=max(num,num1);
				num1=0;
			}
			num1=0;
			for(int i=0;i<3;i++)
			{
				if(i==0) num1+=c7;
				if(i==1) num1+=c8;
				if(i==2) num1+=c9;
				if(i==0) num1+=max(c5,c6);
				if(i==1) num1+=max(c4,c6);
				if(i==2) num1+=max(c4,c5);
				ans=max(ans,num1);
				num1=0;
			}
			cout<<max(num,ans);
			continue;
		}
		for(int r=0;r<n;r++)
		{
			max1=0;
			max2=0;
			max3=0;
			id1=0;
			id2=0;
			id3=0;
			cin>>c1;
			if(c1>max1)
			{
				id1=1;
				max1=c1;
			}
			cin>>c2;
			if(c2>max1)
			{
				id1=2;
				max1=c2;
				max2=c1;
				id2=1;
			}
			else
			{
				max2=c2;
				id2=c2;
			}
			cin>>c3;
			if(c3>max1)
			{
				max3=max2;
				id3=id2;
				max2=max1;
				id2=id1;
				max1=c3;
				id1=3;
			}
			else if(c3>max2)
			{
				max3=max2;
				id3=id2;
				max2=c3;
				id2=3;
			}
			else
			{
				max3=c3;
				id3=3;
			}
			if(a[id1-1]<(n/2))
			{
				ans+=max1;
				a[id1-1]++;	
			}
			else if(a[id2-1]<(n/2))
			{
				ans+=max2;
				a[id2-1]++;
			}
			else
			{
				ans+=max3;
				a[id3-1]++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
