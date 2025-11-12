#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],s,k,ans;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++)
	cin>>a[i];
	k=a[1];
	sort(a+1,a+1+s,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				ans++;
				if(a[ans]==k)
				{
					cout<<i<<' '<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				ans++;
				if(a[ans]==k)
				{
					cout<<i<<' '<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
