#include<bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n >> k;
	if (n < 3)
		cout << 0;
	if (n == 3)
		cout << 1;
	return 0;
}
