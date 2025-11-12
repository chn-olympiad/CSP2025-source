#include<bits/stdc++.h>
using namespace std;
long long dp[205][205][205];
struct node{
	int s1,s2,s3;
}a[100005];
long long cnt1,cnt2,cnt3;
bool cmp(node n1,node n2)
{
	return n1.s1>n2.s1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int round=1;round<=t;round++)
	{
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			cnt1+=a[i].s1;
			cnt2+=a[i].s2;
			cnt3+=a[i].s3;
		}
		long long ans=0;
		if(cnt2==0 && cnt3==0)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].s1;
			}
			cout<<ans;
			cout<<endl;
			continue;
		}
		else if(n<=200)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j1=n/2;j1>=0;j1--)
				{
					if(j1>i) continue;
					for(int j2=n/2;j2>=0;j2--)
					{
						if(j1+j2>i) continue;
						for(int j3=n/2;j3>=0;j3--)
						{
							if(j1+j2+j3>i) continue;
							if(j1!=0) dp[j1][j2][j3]=max(dp[j1][j2][j3],dp[j1-1][j2][j3]+a[i].s1);
							if(j2!=0) dp[j1][j2][j3]=max(dp[j1][j2][j3],dp[j1][j2-1][j3]+a[i].s2);
							if(j3!=0) dp[j1][j2][j3]=max(dp[j1][j2][j3],dp[j1][j2][j3-1]+a[i].s3);
							ans=max(ans,dp[j1][j2][j3]);
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
}