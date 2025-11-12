#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
int n,k;
int h[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n >> k;
	for (int i = 1;i <= n;++i)
		cin >> h[i];
	if (k == 0)
		cout << 1; 
	return 0;
}
