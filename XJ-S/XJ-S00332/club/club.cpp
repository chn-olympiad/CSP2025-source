#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,num[N],ans;
struct savenode
{
	long long data[4],maxn=0,cha=0,minn=INT_MAX,mid=0;
}a[N];
struct node
{
	long long data,num[10];
}dp[N][10];
bool cmp(savenode a,savenode b)
{
	if(a.cha!=b.cha)
	return a.cha>b.cha;
	else
	return a.maxn>b.maxn;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			a[i].maxn=0;
			a[i].minn=INT_MAX;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i].data[j];
				a[i].maxn=max(a[i].data[j],a[i].maxn);
				a[i].minn=min(a[i].data[j],a[i].minn);
				a[i].mid=a[i].data[1]+a[i].data[2]+a[i].data[3]-a[i].maxn-a[i].minn;
				a[i].cha=a[i].maxn-a[i].mid;
			}
		}
		sort(a+1,a+1+n,cmp);
		dp[1][1].data=a[1].data[1]; dp[1][1].num[1]++;
		dp[1][2].data=a[1].data[2]; dp[1][2].num[2]++;
		dp[1][3].data=a[1].data[3]; dp[1][3].num[3]++;
		
		long long choicenum=0;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=3;j++)// dp[i][j]
			{
				for(int k=1;k<=3;k++) //a[i][k]
				{
//					cout<<i<<","<<j<<","<<k<<" : \n";
//					cout<<"num: "<<dp[i-1][k].num[j]<<endl;
					if(dp[i-1][k].num[j]+1>n/2) //选取 a[i][j] 加上 dp[i-1][k] 求当前dp[i][j]最大 
					continue;
//					cout<<"data: "<<a[i].data[j]+dp[i-1][k].data<<endl;
//					cout<<"old data: "<<dp[i][j].data<<endl;
					if((a[i].data[j]+dp[i-1][k].data)>dp[i][j].data)
					{
						dp[i][j].data=a[i].data[j]+dp[i-1][k].data;
						choicenum=k;
					}
//					cout<<"choice num: "<<choicenum<<endl;
//					dp[i][j].data=max(a[i][j]+dp[i-1][k].data,dp[i][j].data);
					
				}
//				cout<<"\n";
				for(int ind=1;ind<=3;ind++)
				{
					dp[i][j].num[ind]=dp[i-1][choicenum].num[ind];
					
				}
				dp[i][j].num[j]++;
				
//				for(int ind=1;ind<=3;ind++)
//				cout<<dp[i][j].num[ind]<<" ";
//				cout<<endl;
				
//				cout<<"\n\n\n";
			}
		}
		cout<<max(dp[n][1].data,max(dp[n][2].data,dp[n][3].data))<<endl;
	}
	return 0;
}

