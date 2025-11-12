#include<bits/stdc++.h>
using namespace std;

int numbers[1000010], numbers_count = 0;

int main()
{
	freopen("number.in", "r+", stdin);
	freopen("number.out", "w+", stdout);
	char s[1000010];
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	for (int i = 1; i <= len; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			numbers[++numbers_count] = (s[i] - '0');
		}
	}
	sort(numbers + 1, numbers + numbers_count + 1);
	for (int i = numbers_count; i >= 1; i--)
	{
		printf("%d", numbers[i]);
	}
	
	//printf("Memory:%db", (sizeof(numbers) + sizeof(numbers_count) + sizeof(s) + sizeof(len) ) / 1024);
	return 0;
}
