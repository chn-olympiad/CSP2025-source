#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct node
{
	int x,y,z;
};
node a[N];
int n;
int dp[2][205][205];
int solve1()
{
	memset(dp,0,sizeof dp);
	const int lmt=n/2;
	dp[1][1][0]=a[1].x;
	dp[1][0][1]=a[1].y;
	dp[1][0][0]=a[1].z;
	for(int i=2;i<=n;i++){
		const int cur=i&1,last=cur^1;
		for(int x=0;x<=lmt;x++){
			for(int y=0;y<=lmt;y++){
				if(x+y>i)
					break;
				if(i-x-y>lmt)
					continue;
				dp[cur][x][y]=max({dp[last][x-1][y]+a[i].x,dp[last][x][y-1]+a[i].y,dp[last][x][y]+a[i].z});
			}
		}
	}
	int mx=INT_MIN;
	for(int i=0;i<=lmt;i++)
		for(int j=0;j<=lmt;j++)
			mx=max(mx,dp[0][i][j]);
	return mx; 
}
int arr[N];
int solve2()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i].x;
		arr[i]=a[i].y-a[i].x;
	}
	sort(arr+1,arr+n+1,greater<int>());
	const int lmt=n/2;
	for(int i=1;i<=lmt;i++)
		ans+=arr[i];
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		if(n<=200)
			cout<<solve1();
		else
			cout<<solve2();
		cout<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
