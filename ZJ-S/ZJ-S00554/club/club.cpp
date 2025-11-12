#include<bits/stdc++.h>
using namespace std;
int m,a[100100][5],max_,maxi=3,maxj=3,ans,n,flag[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int q=0;q<n;q++)
	{
		flag[0]=0;
		flag[1]=0;
		flag[2]=0;
		flag[3]=0;
		//in
		cin>>m;
		
   		for(int i=0;i<m;i++) 
		{	                
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
 			}
		}
		//max
		for(int k=0;k<m;k++)
		{
			max_ = -1;		
			for(int i=0;i<m;i++) 
			{	                
				for(int j=0;j<3;j++)
				{
					if(a[i][j]>max_ and flag[j]<m/2)
					{
						max_ = a[i][j];
						maxi=i;
						maxj=j;
					}
	 			}
			}
			if(max_ != -1)
			{
				ans += max_;
			}
			flag[maxj]+=1;
			for(int j=0;j<3;j++)
				{
					a[maxi][j]=-1;
 				}
		}
		cout<<ans<<endl;
		ans = 0;
	}
	return 0;
}
