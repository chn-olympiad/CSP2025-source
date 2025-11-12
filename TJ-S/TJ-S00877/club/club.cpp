#include <cstdio>
#include <cstring>
using namespace std;//     which this person tries to go to
int t,n,a[100001][3],putrec[3][3],prevrec[3][3],ans;
//                            which is tried to be the best 'from'
int dp[3],prevdp[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		ans=0;
		memset(putrec,0,sizeof(putrec));
		memset(dp,0,sizeof(dp));
		memset(prevrec,0,sizeof(prevrec));
		memset(prevdp,0,sizeof(prevdp));
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			scanf("%d %d %d",&a[j][0],&a[j][1],&a[j][2]);
		}
		for(int j=1;j<=n;j++)//jst person
		{
			if(j%2==1)
			{
				int fromI=0,maxFr=0;
				for(int k=0;k<3;k++)//find max front
				{
					if(maxFr<prevdp[k])
					{
						fromI=k;
						maxFr=prevdp[k];
					}
				}
//				printf("putrec[][]=");
				for(int k=0;k<3;k++)//flush putrec[][]
				{
					for(int l=0;l<3;l++)
					{
						putrec[k][l]=prevrec[fromI][l];
//						printf("%d ",putrec[k][l]);
					}
//					putchar(' ');
				}
//				putchar('\n');
				for(int k=0;k<3;k++)
				{
					if(dp[k]<a[j][k]+maxFr)
					{
						dp[k]=a[j][k]+maxFr;
						putrec[k][k]++;
					}
				}
//				printf("dp[]=");
				for(int k=0;k<3;k++)
				{
//					printf("%d ",dp[k]);
				}
//				printf("\nputrec[][]=");
				for(int k=0;k<3;k++)
				{
					for(int l=0;l<3;l++)
					{
//						printf("%d ",putrec[k][l]);
					}
//					putchar(' ');
				}
//				printf("\n\n");
			}
			else
			{
				for(int k=0;k<3;k++)//the jst person is trying to go to the kst field
				{
					int fromI=0,maxFr=0;
					for(int l=0;l<3;l++)//find max front with lims
					{//l: trying front index
						if(prevrec[l][k]<n/2)
						{
							if(maxFr<prevdp[l])
							{
								fromI=l;
								maxFr=prevdp[l];
							}
						}
					}
//					printf("putrec[%d][]=",k);
					for(int l=0;l<3;l++)
					{
						putrec[k][l]=prevrec[fromI][l];
//						printf("%d ",putrec[k][l]);
					}
//					printf("\ndp[%d]=",k);
					if(dp[k]<a[j][k]+maxFr)
					{
						dp[k]=a[j][k]+maxFr;
						putrec[k][k]++;
					}
//					printf("%d\n",dp[k]);
				}
//				putchar('\n');
			}
			for(int k=0;k<3;k++)
			{
				for(int l=0;l<3;l++)
				{
					prevrec[k][l]=putrec[k][l];
				}
				prevdp[k]=dp[k];
			}
		}
		for(int j=0;j<3;j++)
		{
			ans=(ans>dp[j])?ans:dp[j];
		}
		printf("%d\n",ans);
	}
    return 0;
}
