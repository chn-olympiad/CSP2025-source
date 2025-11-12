#include<bits/stdc++.h>
using namespace std;
int n, k, a[500010], ans, lst = 1, s[500010];
int myxor(int x, int y, int z)
{
	while(x <= y)
	{
		if((s[y] ^ s[x - 1]) == z)	return 1;
		else						x++;
	}
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		s[i] = a[i] ^ s[i - 1];
	for(int i = 1; i <= n; i++)
		if(myxor(lst, i, k))
			ans++, lst = i + 1;
	cout << ans;
	return 0;
}
