#include <bits/stdc++.h> 
using namespace std;
int a[100005][3];
bool cmp(int x,int y)
{
	if(x>=y)
	{
		return true;
	}
	else
		return false;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int m=0,n;
		bool FA=true,FB=true;
		int fir[100005],sec[100005],trd[100006];
		cin>>n;
		int HIGH=n/2;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
				if(j==0)
				{
					fir[i]=a[i][j];
				}
				if(j==1)
				{
					if(a[i][j]!=0)
						FA=false;
					sec[i]=a[i][j];
				}
				if(j==2)
				{
					if(a[i][j]!=0)
					{
						FA=false;
						FB=false;
					}	
					trd[i]=a[i][j];
				}
			}
		}
		if(n==2)
		{
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(i==j)
						continue;
					m=max(m,a[1][i]+a[0][j]);
				}
			}
			cout<<m<<endl;
			continue; 
		}
		
		sort(fir,fir+n,cmp);
		sort(sec,sec+n,cmp);
		sort(trd,trd+n,cmp);
		if(FA)
		{
			for(int i=0;i<HIGH;i++)
			{
				m=m+fir[i];
			}
			cout<<m<<endl;
			continue;
		}

	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
