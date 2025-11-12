#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	long long a[100]={},a1[100]={0},max1,max2,max3,max4[10]={},max5[10]={},sum=0,ans;
	while(t--)
	{
		cin>>n;
		max1=0;
		max2=n/2;
		while(n--)
		{	
			for(int j=0;j<3;j++)
			{
				cin>>a[j];
				if(max4[0]+max4[1]+max4[2] > a[0]+a[1]+a[2])
				{
					max5[0]=max4[0];
					max5[1]=max4[1];
					max5[2]=max4[2];
				}
			}
			if(a[0]>a[1] && a[0]>a[2]) 
			{
				max1+=a[0];
				a1[0]++;
			}
			if(a[1]>a[0] && a[1]>a[2]) 
			{
				max1+=a[1];
				a1[1]++;
			}
			if(a[2]>a[0] && a[2]>a[1]) 
			{
				max1+=a[2];
				a1[2]++;
			}
			max4[0]=a[0];
			max4[1]=a[1];
			max4[2]=a[2];
		}
		if(a1[0]<=max2 && a1[1]<=max2 && a[2]<=max2) cout<<max1;
		else
		{
			if(a1[0]>max2)
			{
				max1-=max5[0];
				max3=max(max5[1],max5[2]);
				max1+=max3;
				a1[0]--;
				if(max3==max5[1]) a1[1]++;
				else a1[2]++;
			} 
			else if(a1[1]>max2)
			{
				max1-=max5[1];
				max3=max(max5[0],max5[2]);
				max1+=max3;
				a1[1]--;
				if(max3==max5[0]) a1[0]++;
				else a1[2]++;
			} 
			else if(a1[2]>max2)
			{
				max1-=max5[2];
				max3=max(max5[0],max5[1]);
				max1+=max3;
				a1[2]--;
				if(max3==max5[0]) a1[0]++;
				else a1[1]++;
			}
			cout<<max1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
