#include<bits/stdc++.h>
using namespace std;
int n,m;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	if (m == 1)
		cout << 998244353 % n;
}
