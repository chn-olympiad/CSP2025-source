#include<bits/stdc++.h>
using namespace std;
int n,maxx=0;
int a[100005][4],flag[100005],b[100005];
int sum[4],ans=0;
void dfs(int x)
{
	if(x>n)
	{
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(flag[x]!=1&&sum[i]<n/2)
		{
			flag[x]=1;
			sum[i]++;
			ans+=a[x][i];
			dfs(x+1);
			flag[x]=0;
			sum[i]--;
			ans-=a[x][i];
		}
	}
}
bool cmp(int x,int y)
{
	return x>y; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j,t,a1,a2,a3,num1=0,num2=0;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n;
		num1=0;
		num2=0;
		for(j=1;j<=n;j++)
		{
			cin>>a1>>a2>>a3;
			num1+=a2+a3;
			a[j][1]=a1;
			b[j]=a1;
			a[j][2]=a2;
			a[j][3]=a3;
		}
		if(num1==0)
		{
			sort(b+1,b+n+1,cmp);
			for(j=1;j<=n/2;j++)
			{
				num2+=b[j];
			}
			cout<<num2<<endl;
		}
		else
		{
			dfs(1);
			cout<<maxx<<endl;
			ans=0;
			sum[1]=0;
			sum[2]=0;
			sum[3]=0;
			for(j=1;j<=n;j++)
			{
				a[j][1]=0;
				a[j][2]=0;
				a[j][3]=0;
				flag[j]=0;
			}
			maxx=0;
		}
	}
	return 0;
}
