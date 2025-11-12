#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N  = 5e5 + 10;
LL k;
int n;
int a[N];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %lld", &n, &k);
	for(int i = 1; i <= n; i ++)scanf("%d", &a[i]);
	int cnt = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = i; j <= n; j ++)
		{
			bool flag = 1;
			LL num = 0;
			if(i == j)
			{
				num = a[i];
			}
			else
			{
				for(int t = i; t <= j; t ++)num = num ^ a[t];
			}
			if(num == k)
			{
				i = j + 1;
				cnt ++;
			}
		}
	printf("%d", cnt);
	return 0;
}
