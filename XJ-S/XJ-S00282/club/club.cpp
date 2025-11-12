#include<bits/stdc++.h>
using namespace std;

int t,n,max1=-1,vis[3],num,flag;
struct st{
	int one;
	int two;
	int three;
}str[100000];

void dfs(int step,int sum,int weizhi)
{
	int sum1=sum;
	if(weizhi==1&&vis[0]<=num-1&&flag==0)
	{
		sum1+=str[step].one;
		flag=1;
		vis[0]++;
	}
	if(weizhi==2&&vis[1]<=num-1&&flag==0)
	{
		sum1+=str[step].two;
		flag=1;
		vis[1]++; 
	}
	if(weizhi==3&&vis[2]<=num-1&&flag==0)
	{
		sum1+=str[step].three; 
		flag=1;
		vis[2]++;
	}
	flag=0;
	if(step==n-1)
	{
		if(max1<sum1)
		{
			max1=sum1;
		}
		return;
	}
	
	dfs(step+1,sum1,1);
	dfs(step+1,sum1,2);
	dfs(step+1,sum1,3);
	vis[weizhi]-=1;
}

int cmp(int a,int b)
{
	return a>b;
}
int cmp1(st a,st b)
{
	return a.one>b.one;
}
int cmp2(st a,st b)
{
	return a.two>b.two;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>t;
	int flag2=0,flag3=0,flag4;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		num=n/2;
		for(int j=0;j<n;j++)
		{
			cin>>str[j].one>>str[j].two>>str[j].three;
			if(str[j].two!=0)
			{
				flag2=1;
			}
			if(str[j].three!=0)
			{
				flag3=1;
			}
			if(str[j].one!=0)
			{
				flag4=1;
			}
		}
		if(flag2==0&&flag3==0)
		{
			int ans=0,lingshi[100000]={};
			for(int j=0;j<n;j++)
			{
				lingshi[j]=str[j].one;
			}
			sort(lingshi,lingshi+n,cmp);
			for(int j=0;j<=n/2-1;j++)
			{
				ans+=lingshi[j];
			} 
			cout<<ans<<" ";
		}
		else if(flag3==0&&flag2==1&&flag4==1)
		{
			int ans1=0,ans2=0;
			sort(str,str+n,cmp1);
			for(int j=0;j<n/2;j++)
			{
				ans1+=str[j].one;
			}
			for(int j=n/2;j<n;j++)
			{
				ans1+=str[j].two;
			}
			sort(str,str+n,cmp2);
			
			for(int j=0;j<n/2;j++)
			{
				ans2+=str[j].two;
			}
			for(int j=n/2;j<n;j++)
			{
				ans2+=str[j].one;
			}
			if(ans2<=ans1) cout<<ans1<<" ";
			else cout<<ans2<<" ";
		}
		else
		{
			dfs(0,0,1);
			vis[0]=0;
			vis[1]=0;
			vis[2]=0;
			dfs(0,0,2);
			vis[0]=0;
			vis[1]=0;
			vis[2]=0;
			dfs(0,0,3);
			cout<<max1<<" ";
		}
	}
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
