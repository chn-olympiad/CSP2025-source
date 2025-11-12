#include<iostream>
#include<cstdio>
using namespace std;
int a[101];
int n,m,k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	k = n * m;
	for(int i = 1;i <= k;i++)
	{
		cin >> a[i];
	}
	int cnt = 1;
	for(int i = 2;i <= k;i++)
	{
		if(a[i] > a[1]) cnt++;
	}
	int s1 = cnt / n,s2 = cnt % n;
	if(s2 != 0) s1++;
	else s2 = n;
	cout << s1 << ' ';
	if(s1 % 2 == 0) cout << n - s2 + 1;
	else cout << s2;
}
