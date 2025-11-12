#include<bits/stdc++.h>
using namespace std;
int t,n;
long long maxi=0;
int a[100005][5]={0},f[5]={0};
void bfs(int x,long long sum)
{
	if(x>n)
	{
		maxi=max(maxi,sum);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(f[i]<n/2 && a[x][i]!=min(a[x][1],min(a[x][2],a[x][3])))
		{
			f[i]++;
			bfs(x+1,sum+a[x][i]);
			f[i]--;
		}
		else continue;
	}
	return ;
}
int main()
{
	freopen("club3.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		maxi=0;
		f[1]=0;f[2]=0;f[3]=0;
		bfs(1,0);
		cout<<maxi;
	}
	return 0;
}
