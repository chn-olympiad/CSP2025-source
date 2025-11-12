#include<iostream>
using namespace std;
long long t,n;
long long love[100005][4],want[100005][4];
long long swich[100005];
long long club[4][100005],num[4];
long long where[100005];
long long anss[100005];
long long sha=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>love[j][1]>>love[j][2]>>love[j][3];
			if(love[j][1]>=love[j][2]&&love[j][1]>=love[j][3])
			{
				want[j][1]=1;
				if(love[j][2]>=love[j][3])
				{
					want[j][2]=2;
				}
				else
				{
					want[j][2]=3;
				}
			}
			else
			{
				if(love[j][2]>=love[j][1]&&love[j][2]>=love[j][3])
				{
					want[j][1]=2;
					if(love[j][1]>=love[j][3])
					{
						want[j][2]=1;
					}
					else
					{
						want[j][2]=3;
					}
				}
				else
				{
					want[j][1]=3;
					if(love[j][1]>=love[j][2])
					{
						want[j][2]=1;
					}
					else
					{
						want[j][2]=2;
					}
				}
			}
			swich[j]=love[j][want[j][1]]-love[j][want[j][2]];
		}			
		num[1]=0;
		num[2]=0;
		num[3]=0;
		sha=0;
		for(int j=1;j<=n;j++)
		{
			where[j]=want[j][1];
			num[want[j][1]]++;
			club[want[j][1]][num[want[j][1]]]=j;
		}
		while(num[1]-sha>n/2)
		{
			long long little=100005,ohno=0;
			for(int j=1;j<=num[1];j++)
			{
				if(swich[club[1][j]]<little)
				{
					ohno=club[1][j];
					little=swich[club[1][j]];
				}
			}
			where[ohno]=want[ohno][2];
			sha++;
			swich[ohno]=100005;
		}
		while(num[2]-sha>n/2)
		{
			long long little=100005,ohno=0;
			for(int j=1;j<=num[2];j++)
			{
				if(swich[club[2][j]]<little)
				{
					ohno=club[2][j];
					little=swich[club[2][j]];
				}
			}
			where[ohno]=want[ohno][2];
			sha++;
			swich[ohno]=100005;
			
		}
		while(num[3]-sha>n/2)
		{
			long long little=100005,ohno=0;
			for(int j=1;j<=num[3];j++)
			{
				if(swich[club[3][j]]<little)
				{
					ohno=club[3][j];
					little=swich[club[3][j]];
				}
			}
			where[ohno]=want[ohno][2];
			sha++;
			swich[ohno]=100005;
		}
		long long ans=0;
		for(int j=1;j<=n;j++)
		{
			ans+=love[j][where[j]];
		}
		anss[i]=ans;
	}
	for(int i=1;i<=t;i++)
	{
		cout<<anss[i]<<endl;
	}
	return 0;
}
