#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e6+5;

char s[N];

int t[15];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	for(int i = 0; i < strlen(s); i++)
	{
		char c = s[i];
		if (c >= '0' && c <= '9')
		{
			t[c-'0']++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		while (t[i])
		{
			printf("%d", i);
			{
				t[i]--;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
