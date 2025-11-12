#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e6 + 5;

char a[N];
int cnt[15];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	scanf("%s", a + 1);
	for (int i = 1; i <= strlen(a + 1); i++)
	{
		if(a[i] >= '0' && a[i] <= '9')
			cnt[a[i] - '0']++;
	}
	for (int i = 9; i >= 0; i--)
	{
		while(cnt[i]--)
			printf("%d", i);
	}
	putchar('\n');
	
	return 0;
}
