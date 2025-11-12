#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[105],cnt,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;i<=cnt;i++) cin>>b[i];
	ans=b[1];
	sort(b+1,b+1+cnt);
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=b[cnt--];
				if(a[i][j]==ans)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				a[i][j]=b[cnt--];
				if(a[i][j]==ans)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}

