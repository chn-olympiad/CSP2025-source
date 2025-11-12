#include<bits/stdc++.h>
using namespace std;
int z,n,a[100010][13][15],i,macnt[15],maxn=INT_MIN,masum[15],t[2];
bool f[13];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>z;
	for(int num=1;num<=z;num++)
	{
		cin>>n;
		macnt[num]=n/2;
		for(i=1;i<=n;i++)
		{
			cin>>a[i][1][num]>>a[i][2][num]>>a[i][3][num];
		}
		if(n==2)
		{
			for(int j=1;j<=n;j++)
			{
				maxn=INT_MIN;
				for(int i=1;i<=3;i++)
				{
					if(f[i]!=macnt[num])
					{
						if(maxn<=a[j][i][num])
						{
							f[i]++;
							maxn=a[j][i][num];
						}
					}
				}
				masum[num]+=maxn;
			}
		}
		else if(n==10000)
		{
			if(a[1][2][num]==0&&a[1][3][num]==0)
			{
				for(int i=1;i<=macnt[num];i++)
				{
					for(int j=1;j<=n;j++)
					{
						if(maxn<=a[j][1][num])
						{
							t[1]=j;
							maxn=a[j][1][num];
						}
					}
					if(f[1]!=macnt[num])
					{
						f[1]++;
						maxn=INT_MIN;
						a[t[1]][1][num]=INT_MIN;
						masum[num]+=maxn;
					}
				}
			}
			else
			{
				while(1)
				{
					for(int j=1;j<=n;j++)
					{
						for(int i=1;i<=2;i++)
						{
							if(maxn<=a[j][2][num])
							{
								t[1]=j;
								t[2]=i;
								maxn=a[j][i][num];
							}
						}
					}
					if(f[1]!=macnt[num]&&f[2]!=macnt[num])
					{
						f[t[2]]++;
						maxn=INT_MIN;
						a[t[1]][t[2]][num]=INT_MIN;
						masum[num]+=maxn;
					}
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(maxn<=a[i][j][num])
					{
						t[1]=i;
						maxn=a[i][j][num];
					}
				}
				if(f[1]!=macnt[num]&&f[2]!=macnt[num]&&f[3]!=macnt[num])
				{
					f[t[1]]++;
					maxn=INT_MIN;
					a[t[1]][1][num]=INT_MIN;
					masum[num]+=maxn;
				}
			}
		}
	}
	for(int i=1;i<=z;i++)
	{
		cout<<masum[i]<<endl;
	}
	return 0;
}