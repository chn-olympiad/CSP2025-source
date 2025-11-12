#include <bits/stdc++.h>
using namespace std;
long long n,m,a[103],as[14][14],a1,cnt=1;
bool mycmp(long long a,long long b)
{
	if(a<b)
		return false;
	return true;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	a1 = a[1];
	sort(a+1,a+n*m+1,mycmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i%2==1)
			{
				as[i][j] = a[cnt];
				cnt++;			
			}
			else
			{
				as[i][m-j+1] = a[cnt];
				cnt++;				
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(as[i][j] == a1)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}