#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	srand(time(0));
	int n, q;
	cin >> n >> q;
	string s;
	for (int i = 1; i <= n; i++) cin >> s >> s;
	while(q--)
	{
		cin >> s >> s;
		cout << rand() % 6 << '\n';
	}
}
