#include<bits/stdc++.h>
using namespace std;
int n, m, a[105];
int pos;
int p;
int q;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
		cin >> a[i];
	int s = a[1];
	sort(a+1, a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(a[i] == s)
		{
			pos = n * m - i + 1;
			break;
		}
	p = pos % n;
	q = pos / n;
	if(p == 0)
		cout << q;
	else
	{
		cout << q + 1;	
		q ++;
	}
	cout <<  " ";
	if(q % 2 == 0)
		if(p == 0)
			cout << 1;
		else cout << n - p + 1;
	else 
		if(p == 0)
			cout << n;
		else cout << p;
	return 0;
}
