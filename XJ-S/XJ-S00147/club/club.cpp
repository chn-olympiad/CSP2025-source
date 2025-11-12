#include<iostream>
using namespace std;
int a[1000005][4],b[5]={0};
int main ()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m,i,j,k,t,sum=0,s;
	cin>>t;
	for(int m=1;m<=t;m++)
	{
		cin>>n;
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=3;k++)
			{
				cin>>a[j][k];
			}
		}
		int lmax=0;
		sum=0;
		b[1]=0;
		b[2]=0;
		b[3]=0;
		for(i=n;i>=1;i--)
		{
			lmax=0;
			int flag=0;
			for(j=1;j<=3;j++)
			{
				if(a[i][1]==0&&a[i][2]==0&&a[i][3]==0)
				{
					break;
				}
				if(a[i][j]>=lmax&&b[j]+1<=n/2)
				{
					lmax=a[i][j];
					s=j;
				}
			}
			b[s]++;
			sum+=lmax;
			a[i][1]=0;
			a[i][2]=0;
			a[i][3]=0;
		}
		cout<<sum;
	}	
	return 0;
}
