#include <bits/stdc++.h>
using namespace std;
int a;
void loop(int q)
{
	cout << q;
	loop(q);
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> a;
	loop(a);
	return 0;
}
