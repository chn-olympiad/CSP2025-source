#include <iostream> 
#include <algorithm>
using namespace std;
int t,n,x=0,y=0,z=0,h;
int sor(int x,int y,int z)
{
	if(x>y&&x>z)return 0;
	if(y>x&&y>z)return 1;
	if(z>x&&z>y)return 2;
	return -1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		int a[n][2],x=0,y=0,z=0;
		int p=n/2,ans=0;int k1[n],k2[n],k3[n];
		for(int j=0;j<n;j++)
		{
			cin>>a[j][0]>>a[j][1]>>a[j][2];k1[j]=a[j][0];k2[j]=a[j][1];k3[j]=a[j][2];
		}
		for(int ii=0;ii<n;ii++)
		{for(int jj=ii;jj<n;jj++)
			if(k1[ii]>k1[jj])
			{
				swap(k1[ii],k1[jj]);
				swap(k2[ii],k2[jj]);
				swap(k3[ii],k3[jj]);
			}
			else if(k2[ii]<k2[jj])
			{
				swap(k1[ii],k1[jj]);
				swap(k2[ii],k2[jj]);
				swap(k3[ii],k3[jj]);
			}
			else if(k3[ii]>k3[jj])
			{
				swap(k1[ii],k1[jj]);
				swap(k2[ii],k2[jj]);
				swap(k3[ii],k3[jj]);
			}
		}
		for(int j=0;j<n;j++)
		{	
			if(sor(k1[j],k2[j],k3[j])==0)
			{
				ans+=k1[j];x++;
				if(x>p)
					{ans-=k1[j];
					if(max(k2[j],k3[j])==k2[j]){ans+=k2[j];y++;}else{ans+=k3[j];z++;}}
			}
			if(sor(k1[j],k2[j],k3[j])==1)
			{
				ans+=k2[j];y++;
				if(y>p)
					{ans-=k2[j];
					if(max(k1[j],k3[j])==k1[j]){ans+=k1[j];x++;}else{ans+=k3[j];z++;}}
			}
			if(sor(k1[j],k2[j],k3[j])==2)
			{
				ans+=k3[j];z++;
				if(z>p)
					{ans-=k3[j];
					if(max(k1[j],k2[j])==k1[j]){ans+=k1[j];x++;}else{ans+=k2[j];y++;}}
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;//气笑了我是怎么进第二轮的 
} 
