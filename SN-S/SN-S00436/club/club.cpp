#include<bits/stdc++.h>
using namespace std;
bool compare(int a,int b)
{
	return a>b;
}
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int times;
	int onenum[100],twonum[100],threenum[100],lone=0,ltwo=0,lthree=0;
	cin>>times;
	int a[4];
	for(int k=0;k<times;k++)
	{
		int n,s=0,one=0,two=0,three=0,succes=0;
		cin>>n;
		for(int i=0;i<100;i++)
		{
			onenum[i]=0;
			twonum[i]=0;
			threenum[i]=0;
		}
		for(int i=0;i<n;i++)
		{
			succes=0;
			for(int j=0;j<3;j++)
			{
				cin>>a[j];
			}
			if(a[0]>=a[1]&&a[0]>=a[2]&&succes==0)
			{
				onenum[i]=a[0];
				succes=1;
				lone++;
			
			}
			if(a[1]>=a[0]&&a[1]>=a[2]&&succes==0)
			{
				twonum[i]=a[1];
				succes=1;
				ltwo++;
			}
			if(a[2]>=a[0]&&a[2]>=a[1]&&succes==0)
			{
				threenum[i]=a[2];
				succes=1;
				lthree++;
			}
		}
		sort(onenum,onenum+100,compare);
		sort(twonum,twonum+100,compare);
		sort(threenum,threenum+100,compare);
		for(int i=0;i<n/2;i++)
		{
			s+=onenum[i];
			s+=twonum[i];
			s+=threenum[i];
		}
		cout<<s<<endl;
	}
	return 0;
}
