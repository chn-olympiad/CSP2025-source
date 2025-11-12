#include <bits/stdc++.h>
using namespace std;
int n,t,a[100005][4],e[205][105][105][105],c[100005][50005],maxx;
int main()
{
	//Ren5Jie4Di4Ling5%
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--)
	{
		cin>>n;//QAQºÃÄÑ°¡ 
		if (n<=200)
		{
			for (int i=1;i<=n;i++)
			{
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			}
			//cout<<"fkg"<<e[3][1][1][1]<<"duhfk";
			for (int i=1;i<=n;i++)
			{
				for (int j=0;j<=i && j<=n/2;j++)
				{
					for (int l=0;l<=i-j && l<=n/2;l++)
					{
						for (int f=0;f<=i-j-l && f<=n/2;f++)
						{
							if (j)
								e[i][j][l][f]=max(e[i-1][j-1][l][f]+a[i][1],e[i][j][l][f]);
							if (l)
								e[i][j][l][f]=max(e[i-1][j][l-1][f]+a[i][2],e[i][j][l][f]);
							if (f)
								e[i][j][l][f]=max(e[i-1][j][l][f-1]+a[i][3],e[i][j][l][f]);
							maxx=max(e[i][j][l][f],maxx);
						}
					}
				}
			}
			cout<<maxx<<endl;
		}
		else
		{
			for (int i=1;i<=n;i++)
			{
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			}
			//cout<<"fkg"<<e[3][1][1][1]<<"duhfk";
			for (int i=1;i<=n;i++)
			{
				for (int j=0;j<=i && j<=n/2 && i-j<=n/2;j++)
				{
					c[i][j]=max(c[i-1][j-1]+a[i][1],c[i][j]);
					c[i][j]=max(c[i-1][j]+a[i][2],c[i][j]);
					maxx=max(c[i][j],maxx);
				}
			}
			cout<<maxx<<endl;
		}
		memset(e,0,sizeof(e));
		maxx=0;
	}
	return 0;
}
