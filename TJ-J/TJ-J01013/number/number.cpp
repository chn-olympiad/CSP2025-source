#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXLEN = 1e6 + 10;
char s[MAXLEN];
int a[MAXLEN], t = 0;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", &s[1]);
	int len = strlen(&s[1]);
	for(int i = 1; i <= len; ++ i) if('0' <= s[i] && s[i] <= '9') a[++ t] = s[i] - '0';
	std::sort(&a[1], &a[t + 1], cmp);
	if(!a[1]) printf("0");
	else for(int i = 1; i <= t; ++ i) printf("%d", a[i]);
	printf("\n");
	return 0;
} 
