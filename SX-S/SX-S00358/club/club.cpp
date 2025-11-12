#include<bits/stdc++.h>
#define int long long
#define for1(l,r,name) for(int name = l;name <= r;name++)
#define for2(r,l,name) for(int name = r;name >= l;name--)
using namespace std;
const int N = 1e5 + 666;
int t,n,h[102][4],dp[102][52][52][52],cnt,ca,cb,cc,sum,cun[N],ans;
bool f[N];
struct node{
	int a,b,c;
}s[N];
struct node1{
	int id,jd,a;
	bool operator < (const node1 & hh) const{
		return a > hh.a;
	}
}sss[3 * N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cnt = ca = cb = cc = 0;
		bool flag = 0;
		memset(f,0,sizeof f);
		cin >> n;
		if(n <= 150)
		{
			memset(dp,0,sizeof dp);
			for1(1,n,i)
			{
				cin >> h[i][1] >> h[i][2] >> h[i][3];
				for1(0,n/2,j)
				for1(0,n/2,k)
				for1(0,n/2,l)
				{
					dp[i][j+1][k][l]=max(dp[i][j+1][k][l],dp[i-1][j][k][l]+h[i][1]);
					dp[i][j][k+1][l]=max(dp[i][j][k+1][l],dp[i-1][j][k][l]+h[i][2]);
					dp[i][j][k][l+1]=max(dp[i][j][k][l+1],dp[i-1][j][k][l]+h[i][3]);
				}
			}
			ans = 0;
			for1(1,n/2,j)
			for1(1,n/2,k)
			for1(1,n/2,l)
			ans = max(ans,dp[n][j][k][l]);
			cout << ans << '\n';
			continue;
		}
		for1(1,n,i)
		{
			cin >> s[i].a >> s[i].b >> s[i].c;
			sss[++cnt].id = 1,sss[cnt].jd = i,sss[cnt].a = s[i].a;
			sss[++cnt].id = 2,sss[cnt].jd = i,sss[cnt].a = s[i].b;
			sss[++cnt].id = 3,sss[cnt].jd = i,sss[cnt].a = s[i].c;
		} 
		sort(sss + 1,sss + 1 + cnt);
		for1(1,n,i)
		{
			if(sss[i].id == 1) ca++;
			if(sss[i].id == 2) cc++;
			if(sss[i].id == 3) cb++;
			if(f[sss[i].jd]) flag = 1;
			f[sss[i].jd] = 1;
			sum += sss[i].a;
		} 
		if(ca <= n / 2 && cb <= n / 2 && cc <= n / 2 && !flag) 
		{
			cout << sum << '\n';
			continue;
		}
		
		ans = 0;
		
		sum = 0;
		for1(1,n,i) 
		{
			sum += max(s[i].b,s[i].c);
			cun[i] = s[i].a - max(s[i].b,s[i].c);
		}
		sort(cun + 1,cun + 1 + n);
		for1(n / 2 + 1,n,i) sum += cun[i];
		ans = max(ans,sum);
	
		sum = 0;
		for1(1,n,i) 
		{
			sum += max(s[i].a,s[i].c);
			cun[i] = s[i].b - max(s[i].a,s[i].c);
		}
		sort(cun + 1,cun + 1 + n);
		for1(n / 2 + 1,n,i) sum += cun[i];
		ans = max(ans,sum);
	
		sum = 0;
		for1(1,n,i) 
		{
			sum += max(s[i].a,s[i].b);
			cun[i] = s[i].c - max(s[i].a,s[i].b);
		}
		sort(cun + 1,cun + 1 + n);
		for1(n / 2 + 1,n,i) sum += cun[i];
		ans = max(ans,sum);
		
		cout << ans << '\n';		
	}
	return 0;
}
