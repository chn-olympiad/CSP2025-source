#include <bits/stdc++.h>
using namespace std;
#define N 201
int a[N][N];
int b[N];
int d[N];							//每个社团容量 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		d[1]=n/2,d[2]=n/2,d[3]=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
				b[i]=max(b[i],a[i][j]);
			}
		}
		int ans=0;
		int vis=0;
		for(int i=1;i<=n;i++)
		{
			int cnt=0;
			for(int j=1;j<=3;j++)
			{
				if(d[j]!=0)
				{
					if(cnt<a[i][j])
					{
						cnt=a[i][j];
						vis=j;
					}
					if(j==3)
					{
						d[vis]--;
					}
				}
			}
			ans+=cnt;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}