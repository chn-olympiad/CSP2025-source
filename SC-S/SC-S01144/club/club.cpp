#include<bits/stdc++.h>
using namespace std;
int t;
int n,a[100005][7],sum1,sum2,sum3,ans;
void cmp(int x,int m)
{
	if(x>n)
	{
		ans=max(ans,m);
		return ;
	}
	if(sum1+1<=n/2)
	{
		sum1++;
		cmp(x+1,m+a[x][1]);
		sum1--;
	}
	if(sum2+1<=n/2)
	{
		sum2++;
		cmp(x+1,m+a[x][2]);
		sum2--;
	}
	if(sum3+1<=n/2)
	{
		sum3++;
		cmp(x+1,m+a[x][3]);
		sum3--;
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		}
		cmp(1,0);
		cout<<ans<<"\n";
		ans=0;sum1=0,sum2=0,sum3=0;
	}
	return 0;
}