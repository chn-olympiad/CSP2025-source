//会了一个单次O(n)的办法，能得50 
#include<bits/stdc++.h>

using namespace std;

#define N 200005
#define M 5000005
#define ull unsigned long long

int n, q, p = 13331;
string s1, s2;
ull H1[M], H2[M], P[M];
struct str{ull h1, h2, h, hh; int l, r, len;}a[N];//记录两个哈希值，第一个和最后一个不重复的，和长度 

void hsh1(string s)
{
	for(int i = 1; i <= s.length(); i++)
		H1[i] = H1[i - 1] * p + s[i - 1];
}
void hsh2(string s)
{
	for(int i = 1; i <= s.length(); i++)
		H2[i] = H2[i - 1] * p + s[i - 1];
}
ull query1(int l, int r){return H1[r] - H1[l - 1] * P[r - l + 1];}
ull query2(int l, int r){return H2[r] - H2[l - 1] * P[r - l + 1];}

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	P[0] = 1;
	for(int i = 1; i <= 5000005; i++)P[i] = P[i - 1] * p;
	for(int i = 1; i <= n; i++)
	{
		cin >> s1 >> s2;
		hsh1(s1), hsh2(s2);
		int l = 1, r = s1.length();
		while(l <= s1.length() && s1[l - 1] == s2[l - 1])l++;
		while(r > 0 && s1[r - 1] == s2[r - 1])r--;
		a[i].h1 = H1[s1.length()], a[i].h2 = H2[s2.length()];
		a[i].len = s1.length();
		a[i].l = l, a[i].r = r;
		if(l > r)//没用的东西 
		{
			a[i].h = a[i].hh = a[i].h1;
			continue;
		}
		a[i].h = query1(l, r), a[i].hh = query2(l, r);
	}
	
	while(q--)
	{
		cin >> s1 >> s2;
		hsh1(s1), hsh2(s2);
		int l = 1, r = s1.length();
		while(l <= s1.length() && s1[l - 1] == s2[l - 1])l++;
		while(r > 0 && s1[r - 1] == s2[r - 1])r--;
		ull hh1 = query1(l, r), hh2 = query2(l, r);
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i].r - a[i].l + 1 != r - l + 1)continue;
			if(a[i].h != hh1 || a[i].hh != hh2)continue;
			int pos = 1 + l - a[i].l;
			if(a[i].h1 == query1(pos, pos + a[i].len - 1))ans++;
		}
		cout << ans << "\n";
	}
	
	return 0;
} 
