#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+300;
int a[N][4],T,n,maxx,num1,num2,num3,sum;
void dfs(int now,int sum,int k,int num1,int num2,int num3)
{
	if(now==k)
	{
		maxx=max(maxx,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(i==1 && num1>=k/2)
			continue;
		if(i==2 && num2>=k/2) 
			continue;
		if(i==3 && num3>=k/2)
			continue;
		dfs(now+1,sum+a[now+1][i],k,num1+(i==1),num2+(i==2),num3+(i==3));
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		sum=num1=num2=num3=maxx=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);	
			}
			if(a[i][1]>a[i][2] && a[i][1]>a[i][3])
			{
				num1++;
				sum+=a[i][1]; 
			}
			if(a[i][2]>a[i][1] && a[i][2]>a[i][3])
			{
				num2++;
				sum+=a[i][2]; 
			}
			if(a[i][3]>a[i][2] && a[i][3]>a[i][1])
			{
				num3++;
				sum+=a[i][3]; 
			}
		} 
		if(num1<=n/2 && num2<=n/2 && num3<=n/2)
		{
			printf("%d\n",sum);
			continue;
		}
		dfs(0,0,n,0,0,0);
		printf("%d\n",maxx);
	}
	return 0;
} 
