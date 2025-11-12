#include<bits/stdc++.h>
using namespace std;
int s[121];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> s[i];
	int f = s[1];
	sort(s + 1, s + 1 + n * m, cmp);
	int ind = 0;
	for(int i = 1; i <= n * m; i++)
	{
		if(s[i] == f){
			ind = i;
			break;
		}
	}
	int r = (ind / n) + 1;
	if(ind % n == 0) r--;
	int c = ind % n;
	if(r % 2 == 1)
	{
		if(ind % n == 0) cout << r << " " << n;
		else cout << r << ' ' << c;
	}
	else {
		if(ind % n == 0) cout << r << ' ' << n - c;
		else cout << r << ' ' << n - c + 1;
	}
	return 0;
}


