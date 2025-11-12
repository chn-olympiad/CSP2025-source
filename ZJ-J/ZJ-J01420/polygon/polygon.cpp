#include<bits/stdc++.h>
using namespace std;
int n, a[5005];
int m;
int cnt;
int main()
{
	freopen("polygon.in","r", stdin);
	freopen("polygon1.out", "w", stdout);
	cin >> n;
	bool f1 = 1;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]!=1) f1 = 0;
	}
	if(n <= 3)
		if(a[1]+a[2]+a[3]>2 * max(a[1], max(a[2], a[3])))
			cnt ++;
	cout << cnt;
	return 0;		
}
