//马歆玥 西安滨河学校 SN-S00782 
#include <bits/stdc++.h>
using namespace std;

int t,n;
int a[200005];
int b[200005];
int c[200005];

bool cmp(int a1,int a2)
{
	return a1 > a2;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		int ans = 0,maxn;
		int a1=1,a2=1,a3=1;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin >> n;
		int cnt = n/2;
		for(int i=1;i<=n;i++)
			cin >> a[i] >> b[i] >> c[i];
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			maxn = max(a[a1],max(b[a2],c[a3]));
			if(a[a1] == maxn && a1 <= cnt)
			{
				ans += a[a1];
				a1++;
			}
			else if(b[a2] == maxn && a2 <= cnt)
			{
				ans += b[a2];
				a2++;
			}
			else
			{
				ans += c[a3];
				a3++;
			}
			if(a1 + a2 + a3 == n+3)
				break;
		}
		cout << ans << endl;
	}
	return 0;
}
