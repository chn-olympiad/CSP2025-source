#include<cstdio>
#include<algorithm>
using namespace std;
int book[4]={0};
int a[100002][4];
int bfs(int k,int y,int num)
{
	int max = 0;
	int z=y/2;
	for(int j=1;j<=3;j++)
	{
		if(book[j]>=z)
		continue;
		num+=a[k][j];
		book[j]+=1;
		k++;
		bfs(k,y,num);
		book[j]-=1;
		if(num>=max)
		max=num;
	}	
	if(k>y)
	{
		return max;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	int d[6]={0};
	scanf("%d",&t);
	for(int m=1;m<=t;m++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		d[m]=bfs(1,n,0);
	}
	for(int i=1;i<=t;i++)
	{
		printf("%d\n",d[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}