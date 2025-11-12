#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 10;
int n, k;
int s[N];


signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%lld %lld", &n, &k);
	int x, sum = 0;
	bool sp = true;
	for(int i = 1; i <= n; i ++)
	{
		scanf("%lld", &x);
		sum += x;
		s[i] = s[i - 1] ^ x;
		if(x > 1) sp = false;
	}
	if(sp)
	{
		if(k == 1) printf("%lld\n", sum);
		else printf("%lld\n", sum / 2);
		return 0;
	}
	
	int cnt = 0;
	for(int l = 1; l <= n; l ++)
	{
		for(int r = l; r <= n; r ++)
			if((s[r] ^ s[l - 1]) == k)
			{
				l = r;
				cnt ++;
				break;
			}
	}
	printf("%lld\n", cnt);
	
	
	
	return 0;
}
