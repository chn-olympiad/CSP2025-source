#include<bits/stdc++.h>
#define int long long

using namespace std;

string s;
int a[1000001];
int cnt;

void input();
void init();
void calcu();

signed main()
{
	freopen("number.in", 'r', stdin);
	freopen("number.out", 'w', stdout);
	input();
	init();
	calcu();
	return 0;
}

void calcu()
{
	int i;
	
	for(i = cnt - 1; i >= 0; i--)
	{
		cout << a[i];
	}
}

void input()
{
	cin >> s;
}

void init()
{
	int i;
	
	cnt = 0;
	for(i = 0; i <= s.size(); i++)
	{
		if(s[i] <= '9' && s[i] >= '0')
		{
			a[cnt] = s[i] - '0';
			cnt++;
		}
	}
	sort(a, a + cnt);
}
