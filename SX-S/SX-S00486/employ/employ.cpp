#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n;
	for(int i=n-1;i>=1;i--)
	{
		n=n*i%998244353;
	}
	return 0;
}
