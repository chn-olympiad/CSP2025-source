//刘尚泽坤  SN-S00054  西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
int n,t,sum;
struct pe
{
	int d1,d2,d3;
	int max1,max2;
	int b1,b2;
	int cha;
}a[100005];
int num[5];
bool cmp(pe d,pe f)
{
	return d.cha>f.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n;
		sum=0;
		num[1]=0;
		num[2]=0;
		num[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			a[i].max1=max(a[i].d1,max(a[i].d2,a[i].d3));
			if(a[i].max1==a[i].d1)
			{
				a[i].b1=1;
			}
			else if(a[i].max1==a[i].d2)
			{
				a[i].b1=2;
			}
			else
			{
				a[i].b1=3;
			}
			if((a[i].d1>=a[i].d2&&a[i].d1<=a[i].d3)||(a[i].d1>=a[i].d3&&a[i].d1<=a[i].d2))
			{
				a[i].max2=a[i].d1;
				a[i].b2=1;
			}
			else if((a[i].d2>=a[i].d1&&a[i].d2<=a[i].d3)||(a[i].d2>=a[i].d3&&a[i].d2<=a[i].d1))
			{
				a[i].max2=a[i].d2;
				a[i].b2=2;
			}
			else
			{
				a[i].max2=a[i].d3;
				a[i].b2=3;
			}
			a[i].cha=a[i].max1-a[i].max2;
		}
		sort(a+1,a+1+n,cmp);
		//cout<<a[1].b2<<" "<<a[2].b1<<endl;
		for(int i=1;i<=n;i++)
		{
			if(num[a[i].b1]<n/2)
			{
				sum+=a[i].max1;
				num[a[i].b1]++;
			}
			else if(num[a[i].b2]<n/2)
			{
				sum+=a[i].max2;
				num[a[i].b2]++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
1
2
10 9 8
4 0 0
*/
