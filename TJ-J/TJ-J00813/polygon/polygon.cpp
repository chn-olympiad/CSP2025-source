#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

const int N = 5005;
const int M = 1005;
const int P = 998244353;

int n;
int a[N];

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	int ans = 10086;
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
}
