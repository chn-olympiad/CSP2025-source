#include <bits/stdc++.h>
using namespace std;

int a[105];

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int num = n * m;
	for(int i = 1;i <= num;i++)
		cin >> a[i];
	int k = a[1];
	sort(a+1,a+num+1,cmp);
	for(int i = 1;i <= num;i++)
		if(a[i] == k)
		{
			k = i;
			break;
		}
	int l = (k - 1) / n + 1;
	cout << l << " ";
	k = (k - 1) % n + 1;
	if(l % 2 == 0)
		cout << n - k + 1;
	else
		cout << k;
	return 0;
}
