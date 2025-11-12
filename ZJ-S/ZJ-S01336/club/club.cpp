#include<bits/stdc++.h>
using namespace std;
int s,t,n,a[100005][5],b[100005],ans,maxa,a1,a2,a3,xz;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n==2)
		{
			int maxa=0;
			if(maxa<a[1][2]+a[2][3]) maxa=a[1][2]+a[2][3];
			if(maxa<a[1][3]+a[2][2]) maxa=a[1][1]+a[2][2];
			if(maxa<a[1][1]+a[2][2]) maxa=a[1][1]+a[2][2];
			if(maxa<a[1][2]+a[2][1]) maxa=a[1][2]+a[2][1];
			if(maxa<a[1][3]+a[2][1]) maxa=a[1][3]+a[2][1];
			if(maxa<a[1][1]+a[2][3]) maxa=a[1][1]+a[2][3];
			cout<<maxa<<endl;
			continue;
		}
		if(n==4)
		{
			int maxa=0;
			for(int i=1;i<=3;i++)
			{
				s=1;
				for(int j=1;j<=3;j++)
				{
					if(i==j) s++;
					for(int k=1;k<=3;k++)
					{
						if(i==k||j==k) s++;
						for(int l=1;l<=3;l++)
						{
							if(i==l||j==l||k==l) s++;
							
							if(s<=2)
							{
								maxa=max(maxa,a[1][i]+a[2][j]+a[3][k]+a[4][l]);
								cout<<maxa<<" "<<a[1][i]<<" "<<a[2][j]<<" "<<a[3][k]<<" "<<a[4][l]<<endl;
							}
							s--;
							}
						s--;	
					}
					s--;
				}
			}
			cout<<maxa<<endl;
			continue;
		}
		a1=0;a2=0;a3=0;xz=n/2;ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>a[i][2])
			{
				if(a[i][3]>a[i][1]&&a3<xz)
				{
					ans+=a[i][3];
					a3++;
				}
				else if(a1<xz)
				{
					ans+=a[i][1];
					a1++;
				}
				else
				{
					ans+=a[i][2];
					a2++;
				}
		}
		else
		{
			if(a[i][3]>a[i][2]&&a3<xz)
				{
					ans+=a[i][3];
					a3++;
				}
				else if(a2<xz)
				{
					ans+=a[i][2];
					a2++;
				}
				else
				{
					ans+=a[i][1];
					a1++;
				}	
		}
	}
	cout<<ans<<endl;
}
	fclose(stdin);fclose(stdout);
	return 0;
}