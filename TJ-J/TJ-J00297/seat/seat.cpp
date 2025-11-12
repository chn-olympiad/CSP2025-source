#include<bits/stdc++.h>
using namespace std;
#define int long long
struct st{
	int x;//hang
	int y;//lie
	int crto;
}st[105];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n,m,f[105],xr,total=0;
	cin >> n >> m;
	for(int i=1;i<=m;i++)//i lie j hang
	{
		if(i%2==0){
			for(int j=n;j>=1;j--)
			{
				total++;
				st[total].x=i;
				st[total].y=j;
				st[total].crto=total;
				cin >> f[total];
			}
		}else{
			for(int j=1;j<=n;j++)
			{
				total++;
				st[total].x=i;
				st[total].y=j;
				st[total].crto=total;
				cin >> f[total];
			}
		}
	}
	xr=f[1];
	int ss=n*m,ans=0;
	sort(f+1,f+ss+1);
	for(int i=ss;i>=1;i--)
	{
		ans++;
		if(f[i]==xr)
		{
			cout << st[ans].x << " " << st[ans].y;
			return 0;
		}
	}
	return 0;
}
