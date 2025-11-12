#include <bits/stdc++.h>
using namespace std;
int q;
struct nps
{
	int a[3], maxa, mida;
}m[100001];
bool cmp(nps x, nps y)
{
	return (x.maxa-x.mida >= y.maxa-y.mida);
}
void work()
{
	int n, t[3] = {};
	bool bl = 1, bll = 1, blll = 1;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		int l = 0;
		cin >> m[i].a[0] >> m[i].a[1] >> m[i].a[2];
		if(m[i].a[2] != 0) bll = 0;
		else if(m[i].a[1] != 0) blll = 0;
		m[i].maxa = m[i].a[0], t[0] ++, l = 0;
		if(m[i].a[1] > m[i].maxa) m[i].maxa = m[i].a[1], m[i].mida = m[i].a[0], t[0]--, t[1]++, l = 1;
		else m[i].mida = m[i].a[1];
		if(m[i].a[2] > m[i].maxa) m[i].maxa = m[i].a[2], m[i].mida = m[i].a[l], t[l]--, t[2]++;
		else if(m[i].a[2] > m[i].a[(l+1)%2]) m[i].mida = m[i].a[2];
	}
	int k = -1;
	for(int j = 0; j < 3; j ++)
		if(t[j] > n/2)
			bl = 0, k = j;
	long long ans = 0;
	for(int i = 1; i <= n; i++)
		ans += m[i].maxa;
	if(bl)//hefa
	{
		cout << ans << endl;
		return;
	}
	sort(m+1, m+n+1, cmp);
	if(bll & blll)//A
	{
		long long ans1 = 0;
		for(int i = 1; i <= t[k]; i ++)
			if(i <= n/2) ans1 += m[i].maxa;
		cout << ans1 << endl;
		return;
	}
	if(bll)//B
	{
		int j = 1;
		long long ans1 = 0;
		for(int i = 1; i <= n; i ++)
			if(m[i].maxa == m[i].a[k])
			{	
				if(j <= n/2) ans1 += m[i].maxa;
				else if(j <= t[k])ans1 += m[i].a[(k+1)%2];
				j++;
			}
			else ans1 += m[i].maxa;
		cout << ans1 << endl;
		return;
	}
	int j = 1;
	long long ans2 = 0;
	for(int i = 1; i <= n; i ++)
		if(m[i].maxa == m[i].a[k])
		{
			if(j <= n/2) ans2 += m[i].maxa;
			else if(j <= t[k]) ans2 += m[i].mida;
			j++;
		}
		else ans2 += m[i].maxa;
	cout << ans2 << endl;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> q;
	while(q--)
		work();
	return 0;
}
