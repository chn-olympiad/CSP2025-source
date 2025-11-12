#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N = 1e5+1100;
int a[N][4],m1[N],m2[N],d[N],so[N]; //m1,m2 об╠Й 
int t;
void solve(int &m1,int &m2,int &d,int a,int b,int c)
{
	int dd[] = {0,a,b,c};
	m1 = 1,m2 = 2;
	int m3 = 3;
	if(dd[m1] < dd[m2])swap(m1,m2);
	if(dd[m1] < dd[m3])swap(m1,m3);
	if(dd[m2] < dd[m3])swap(m2,m3);
	d = dd[m1]-dd[m2];
}
bool cmp(int a,int b)
{
	return d[a] > d[b];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int ans = 0;
		int num[5] = {};
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			solve(m1[i],m2[i],d[i],a[i][1],a[i][2],a[i][3]);
			so[i] = i;
		}
		sort(so+1,so+1+n,cmp);
		for(int i = 1;i <= n;i++)
		{
			int j = so[i];
			if(num[m1[j]] < n/2)
			{
				ans += a[j][m1[j]];
				num[m1[j]]++;
			}
			else
			{
				ans += a[j][m2[j]];
				num[m2[j]]++;
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
