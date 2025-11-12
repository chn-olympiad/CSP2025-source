//丁煜辰 SN-J00004 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll ansi,cnt;
ll b[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>b[i];
	int cntnum=b[1];
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(cntnum==b[i])
		{
			ansi=i;
		}
	}
	ansi=n*m-ansi+1;
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				cnt++;
				if(cnt==ansi)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				cnt++;
				if(cnt==ansi)
				{
					cout<<i<<" "<<n-j+2;
					return 0;
				}
			}
		}
	}
}
