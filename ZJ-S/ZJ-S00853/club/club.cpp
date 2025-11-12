#include<bits/stdc++.h>
using namespace std;
// 200
int f[210][210][210];//i,a,b,i-a-b
int a[100010][4], b[100010];
struct Node{int x,y;} a2[100010], b2[100010], c2[100010];
struct node{int a,b,ap,bp,c;} t[100010];
/**void calc()
{
	memset(f,0,sizeof f);
	int n;
	cin >> n;
	int sp2 = 1, sp3 = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if(a[i][2] != 0) sp2 = 0;
		if(a[i][3] != 0) sp3 = 0;
	}
	if(n <= 200)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int x = 0; x <= i; x++)
			{
				for(int y = 0; x + y <= i; y++)
				{
					if(x != 0) f[i][x][y] = max(f[i][x][y], f[i-1][x-1][y] + a[i][1]);
					if(y != 0) f[i][x][y] = max(f[i][x][y], f[i-1][x][y-1] + a[i][2]);
					if(i-x-y != 0) f[i][x][y] = max(f[i][x][y], f[i-1][x][y] + a[i][3]);
				}
			}
		}
		int ans = 0;
		/ **for(int i = 1; i <= n; i++)
		{
			for(int x = 0; x <= i; x++)
			{
				for(int y = 0; x + y <= i; y++)
					cout << f[i][x][y] << ' ';
				cout << endl;
			}
			cout << endl;
		}* /
		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j + i <= n; j++)
			{
				if(i <= n/2 && j <= n/2 && n-i-j <= n/2)
				{
					ans = max(ans, f[n][i][j]);
					//cout << i << j << n-i-j << f[n][i][j] << endl;
				}
			}
		}
		cout << ans << endl;
		return;
	}
	if(sp2)
	{
		for(int i = 1; i <= n; i++) b[i] = a[i][1];
		sort(b+1,b+n+1,[](int x, int y){return x > y;});
		int ans = 0;
		for(int i = 1; i <= n / 2; i++)
		{
			ans += b[i];
		}
		cout << ans << endl;
		return;
	}
	if(sp3)
	{
		memset(a2,0,sizeof a2);
		memset(b2,0,sizeof b2);
		memset(c2,0,sizeof c2);
		int cura = 0, curb = 0, curc = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i][1] > a[i][2]) a2[++cura] = {a[i][1], a[i][2]};
			if(a[i][1] < a[i][2]) b2[++curb] = {a[i][1], a[i][2]};
			if(a[i][1] == a[i][2]) c2[++curc] = {a[i][1], a[i][2]};
		}
		sort(a2+1,a2+cura+1,[](Node x, Node y){return x.x - x.y > y.x - y.y;});
		sort(b2+1,b2+curb+1,[](Node x, Node y){return x.x - x.y > y.x - y.y;});
		int ans = 0;
		for(int ua = 1, ub = 1; ua <= cura && ub <= curb;)
		{
			//if(a2[ua].x - a2[ua].y )
		}
	}
}*/
void calc()
{
	memset(t,0,sizeof t);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		if(x >= y && y >= z) t[i] = {x,y,1,2,x-y};
		else if(x >= z && z >= y) t[i] = {x,z,1,3,x-z};
		else if(y >= x && x >= z) t[i] = {y,x,2,1,y-x};
		else if(y >= z && z >= x) t[i] = {y,z,2,3,y-z};
		else if(z >= x && x >= y) t[i] = {z,x,3,1,z-x};
		else if(z >= y && y >= x) t[i] = {z,y,3,2,z-y};
	}
	sort(t+1,t+n+1,[](node x,node y){
		return x.c > y.c;
	});
	int cnt[4]={};
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(cnt[t[i].ap] < n/2)
		{
			ans += t[i].a;
			cnt[t[i].ap]++;
		}
		else
		{
			ans += t[i].b;
			cnt[t[i].bp]++;
		}
	}
	cout << ans << endl;
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--) calc();
	return 0;
}
