#include<bits/stdc++.h>
using namespace std;
#define LL long long
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int t, n, siz[5];
struct Student
{
	int x, y, z;
	int m1, m2;
//	bool operator < (const Student &w) const
//	{
//		return m1 - m2 < w.m1 - w.m2;
//	}
}a[N];
void read(int &s)
{
	s = 0; int f = 1; char c = getchar();
	for(; c < 48 || c > 57; c = getchar()) (c == '-') && (f == -1);
	for(; c >= 48 && c <= 57; c = getchar()) s = (s << 1) + (s << 3) + (c ^ 48);
	s *= f;
	//cin >> s;
	return;
}
priority_queue<PII, vector<PII>, greater<PII> > q;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	read(t);
	while(t --)
	{
		for(int i = 0; i < 5; i ++) siz[i] = 0;
		read(n);
		for(int i = 1; i <= n; i ++)
		{
			read(a[i].x), read(a[i].y), read(a[i].z);
			int m1 = max(max(a[i].x, a[i].y), a[i].z), m2;
			if(a[i].x == m1)
			{
				siz[1] ++, a[i].m1 = a[i].x;
				if(a[i].y > a[i].z) a[i].m2 = a[i].y;
				else a[i].m2 = a[i].z;
			}
			else if(a[i].y == m1)
			{
				siz[2] ++, a[i].m1 = a[i].y;
				if(a[i].x > a[i].z) a[i].m2 = a[i].x;
				else a[i].m2 = a[i].z;
			}
			else
			{
				siz[3] ++, a[i].m1 = a[i].z;
				if(a[i].x > a[i].y) a[i].m2 = a[i].x;
				else a[i].m2 = a[i].y;
			}
		}
		int nn = n / 2;
		int k = 0, ans = 0;
		if(siz[1] > nn)
			for(int i = 1; i <= n; i ++)
			{
				if(a[i].m1 == a[i].x) q.push({a[i].m1 - a[i].m2, i}), k = siz[1] - nn;
				else ans += a[i].m1;
			}	
		else if(siz[2] > nn)
			for(int i = 1; i <= n; i ++)
			{
				if(a[i].m1 == a[i].y) q.push({a[i].m1 - a[i].m2, i}), k = siz[2] - nn;
				else ans += a[i].m1;
			}
		else if(siz[3] > nn)
			for(int i = 1; i <= n; i ++)
			{
				if(a[i].m1 == a[i].z) q.push({a[i].m1 - a[i].m2, i}), k = siz[3] - nn;
				else ans += a[i].m1;
			}
		else
		{
			for(int i = 1; i <= n; i ++)
				ans += a[i].m1;
			cout << ans << endl;
			continue;
		}	
		while(k --)
		{
			PII u = q.top();
			ans += a[u.second].m2;
			//cout << u.second<< endl;
			q.pop();
		}
		while(q.size())
		{
			PII u = q.top();
			ans += a[u.second].m1;
			q.pop();
		}
		cout << ans << endl;
	}
	return 0;
}
