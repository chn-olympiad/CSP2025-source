#include <bits/stdc++.h>
using namespace std;
int t;
int n;
struct node
{
	int v,c;//a: v为满意程度，c为部门编号，c∈{1, 2, 3}
	//num: v为满意程度和，c为人数
};
node a[100005][4];

bool cmp1(node a,node b)
{
	return a.v > b.v;
}

bool cmp2(int a,int b)
{
	return a > b;
}
void solve()
{
	node num[4];
	for (int i = 0;i <= 3;i++)
	{
		num[i].c = 0;
		num[i].v = 0;
	}
	cin >> n;
	bool ff = true;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i][1].v >> a[i][2].v >> a[i][3].v; 
		a[i][1].c = 1;
		a[i][2].c = 2;
		a[i][3].c = 3;
		if (a[i][2].v != 0 || a[i][3].v != 0) ff = false;
		sort(a[i] + 1,a[i] + 4,cmp1);
		//for (int j = 1;j <= 3;j++)	
		//	cout << a[i][j].v << " " << a[i][j].c << endl;	
		//cout << endl;
		num[a[i][1].c].v += a[i][1].v;
		num[a[i][1].c].c++;
	}
	if (ff)
	{
		int cp[100005];
		for (int i = 1;i <= n;i++)
			cp[i] = a[i][1].v;
		sort(cp + 1,cp + 1 + n,cmp2);
		int ans = 0;
		for (int i = 1;i <= n / 2;i++)
		{
			ans += cp[i];
		}
		cout << ans << endl;
		return;
	}
	bool f = true;
	int sum = 0;
	for (int i = 1;i <= 3;i++)
	{
		if (num[i].c > (n / 2))
			f = false;
		sum += num[i].v;
	}
	if (f)
	{
		cout << sum << endl;
		return;
	}
	else 
	{
		//int moving[100005];//moving[i]表示移动第i个人所能得到的最大值
		for (int i = 1;i <= n;i++)
		{
			int m[4][4];//m[i][j]表示把这个人从i个部门移到j个部门所得到的值
			memset(m,0,sizeof(m));
			for (int j = 1;j <= 3;j++)
			{
				for (int k = 1;k <= 3;k++)
				{
					m[a[i][j].c][a[i][k].c] = a[i][k].v - a[i][j].v;
				}
			}
			int numn = 0;
			int zd = 0;
			//sort(num + 1,num + 4,cmp2);
			for (int j = 1;j <= 3;j++)
			{
				if (num[j].c > (n / 2))
				{
					if (num[1].c + 1 <= (n / 2))
					{
						if (numn < sum + m[j][1] && m[j][1] < 0)
						{
							numn = sum + m[j][1];
							zd = 1;
						}
						if (numn < sum)
						{
							sum = numn;
							num[j].c--;
							num[zd].c++;
						}
					}
					
					if (num[2].c + 1 <= (n / 2))
					{
						if (numn < sum + m[j][2] && m[j][2] < 0)
						{
							numn = sum + m[j][2];
							zd = 2;
						}
						if (numn < sum)
						{
							sum = numn;
							num[j].c--;
							num[zd].c++;
						}
					}
					
					if (num[3].c + 1 <= (n / 2))
					{
						if (numn < sum + m[j][3] && m[j][3] < 0)
						{
							numn = sum + m[j][3];
							zd = 3;
						}
						if (numn < sum)
						{
							sum = numn;
							num[j].c--;
							num[zd].c++;
						}
					}
					
				}
			}
		}
		cout << sum << endl;
	}
}
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		solve();
	}
}