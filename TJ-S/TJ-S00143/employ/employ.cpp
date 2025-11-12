#include <bits/stdc++.h>
using namespace std;
int cnt;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n>>m;
	int c;
	cin >> c;
	while(int i = 0;i < n;i++)
	{
		int a;
		cin >> a;
	}
	cnt = 1;
	for(int i =2;i <=n;i++)
	{
		cnt*=i;
	}
	cout << cnt;
	return 0;
}
