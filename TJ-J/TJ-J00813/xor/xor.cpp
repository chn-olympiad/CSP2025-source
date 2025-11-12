#include <cstdio>
using namespace std;

const int N = 5e5+5;
int n, k;
int a[N];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("%d", n/2);
	fclose(stdin);
	fclose(stdout);
}
