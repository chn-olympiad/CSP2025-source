#include<bits/stdc++.h>

using namespace std;

char s[1000001];
int t[11];

int cnt;

void input();
void calcu();
void output();

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	input();
	output();
	return 0;
}

void input()
{
	int i;
	
	scanf("%s", s);
	for(i = 0; i <= strlen(s); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			t[s[i] - '0']++;
		}
	}
}

void output()
{
	int i;
	
	for(i = 9; i >= 0; i--)
	{
		while(t[i] > 0)
		{
			cout << i;
			t[i]--;
		}
	}
}
