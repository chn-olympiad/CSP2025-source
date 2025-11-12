#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 2e6 + 10;
int n, q, t[N][30], idx, cnt[N];
struct String
{
	string s1, s2;
	int siz;
}a[N];
void read(int &s)
{
	s = 0; int f = 1; char c = getchar();
	for(; c < 48 || c > 57; c = getchar()) (c == '-') && (f = -1);
	for(; c >= 48 && c <= 57; c = getchar()) s = (s << 1) + (s << 3) + (c ^ 48);
	s *= f;
	return;
}
void fun(string &a1, string &a2)
{		
	string b1, b2;
	int len = 0, S = 0, E = 0;
	for(int i = 0; i < a1.size(); i ++)
		if(a1[i] != a2[i])
		{
			S = i;
			break;
		}
	for(int i = a1.size() - 1; i >= 0; i --)
		if(a1[i] != a2[i])
		{
			E = i;
			break;
		}
	for(int i = S; i <= E; i ++)
		b1[len] = a1[i], b2[len ++] = a2[i];
	a1 = b1, a2 = b2;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	read(n), read(q);
	cout << n << q << endl;
	for(int i = 1; i <= n; i ++) 
		cin >> a[i].s1 >> a[i].s2, a[i].siz = a[i].s1.size();
	while(q --)
	{
		string a1, a2;
		cin >> a1 >> a2;
		if(a1.size() != a2.size())
		{
			puts("0");
			continue;
		}
		string b1, b2;
		int len = 0, S = 0, E = 0;
		for(int i = 0; i < a1.size(); i ++)
			if(a1[i] != a2[i])
			{
				S = i;
				break;
			}
		for(int i = a1.size() - 1; i >= 0; i --)
			if(a1[i] != a2[i])
			{
				E = i;
				break;
			}
		for(int i = S; i <= E; i ++)
			b1[len] = a1[i], b2[len ++] = a2[i];
		
	}
	return 0;
}
