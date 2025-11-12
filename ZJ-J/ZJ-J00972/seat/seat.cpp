#include<bits/stdc++.h>
#define ll long long
#define forr(a, b, k) for (int i = (a); i <= (b); i += (k))
using namespace std;
const int N = 1e5 + 10;
int T;
int n, m;
int a[N];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)cin >> a[i];
	int k;
	T = a[1];
	sort(a + 1, a + 1 + n * m, greater<int> ());
	for (int i = 1; i <= n * m; i++) if(a[i] == T)
	{
		k = i;
		break;
	}
	if(k % n == 0)
	{
		if(k / n % 2 == 1)
		{
			cout << k / n << " " << n;
		}else{
			cout << k / n << " " << 1;
		}
	}else{
		int p = k / n + 1;
		cout << p << " ";
		if(p % 2 == 1)
		{
			cout << k % n;
		}else{
			cout << n - (k % n) + 1;
		}
	}
	
}

