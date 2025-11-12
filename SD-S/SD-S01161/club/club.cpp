#include<bits/stdc++.h>
using namespace std;
long long min_ll=-999999999999;
long long a[100009][4],b1[100009][4],b2[100009][4],b3[100009][4],p[4],num[4],total=0; 
int ma(int a1,int a2,int a3)
{
	if(a1>=max(a2,a3)) return 1;
	if(a2>=max(a1,a3)) return 2;
	return 3;
}
int max1(int a2,int a3)
{
	if(a2>a3) return 2;
	return 3;
}
int max2(int a1,int a3)
{
	if(a1>a3) return 1;
	return 3;
}
int max3(int a1,int a2)
{
	if(a1>a2) return 1;
	return 2;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	for(int m=1;m<=t;m++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			for(int j=1;j<=3;j++)
			{
				b1[i][j]=a[i][j]-a[i][1];
				b2[i][j]=a[i][j]-a[i][2];
				b3[i][j]=a[i][j]-a[i][3];
				if(b1[i][j]>0) b1[i][j]=min_ll;
				if(b2[i][j]>0) b2[i][j]=min_ll;
				if(b3[i][j]>0) b3[i][j]=min_ll;
			}
			int k=ma(a[i][1],a[i][2],a[i][3]);
			num[k]++;
			total+=a[i][k];
		}
		while(num[1]>n/2||num[2]>n/2||num[3]>n/2)
		{
			long long maxx=min_ll,m=0,pi=0;
			if(num[1]>n/2)
			{
				for(int i=1;i<=n;i++)
				{
					int f=max1(b1[i][2],b1[i][3]);
					if(maxx<b1[i][f]) 
					{
						m=f;
						maxx=b1[i][f];
						pi=i;
					}
				}
				total+=maxx;
				num[1]--;num[m]++;b1[pi][m]=min_ll;
			}
			if(num[2]>n/2) 
			{
				for(int i=1;i<=n;i++)
				{
					int f=max2(b2[i][1],b2[i][3]);
					if(maxx<b2[i][f])
					{
						m=f;
						maxx=b2[i][f];
						pi=i;
					}
				}
				total+=maxx;
				num[2]--;num[m]++;b2[pi][m]=min_ll;
			}
			if(num[3]>n/2) 
			{
				for(int i=1;i<=n;i++)
				{
					int f=max3(b3[i][1],b3[i][2]);
					if(maxx<b3[i][f])
					{
						m=f;
						maxx=b3[i][f];
						pi=i;
					}
				}
				total+=maxx;
				num[3]--;num[m]++;b3[pi][m]=min_ll;
			}
			}
		cout<<total<<endl;
		total=num[1]=num[2]=num[3]=0;
	}
	return 0;
}
