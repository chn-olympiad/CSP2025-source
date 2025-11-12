#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	int R = a[1];
	sort(a+1,a+1+n*m,cmp);
	int cntn = 1,cntm = 0;
	bool flag = 0;
	for(int i = 1; i <= n * m; i++)
	{
		if(flag == 0) cntm++;
		else if(flag == 1) cntm--;
		if(flag == 0 && cntm > m)
		{
			flag = 1;
			cntn++;
			cntm--;
		}
		if(flag == 1 && cntm < 1)
		{
			flag = 0;
			cntn++;
			cntm++;
		}
		if(a[i] == R)
		{
			if(cntm > m) cout << cntn << " " << cntm;
			else if(cntm < m) cout << cntn << " " << cntm;
			else cout << cntn << " " << cntm;
			return 0;
		}
	}
	return 0;
}
