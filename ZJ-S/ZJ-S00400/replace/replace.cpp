#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, q;
string s[N][2];

bool check(int x, string t1, string t2)
{
	int flag = 0, id, jd;
	string t = t1, tt = t2;
	for(int i = 0; i < t.size(); i ++)
	{
		for(int j = t.size() - 1; j >= i; j --)
		{
			if(t.substr(i, j) == s[x][1])
			{
				flag = 1;
				id = i, jd = j;
				break;
			}
		}
	}
	if(flag == 0) return false;
	int ss = 0;
	for(int i = id; i < jd; i ++)
		t[i] = s[x][2][ss ++];
	if(t == tt) return true;
	return false;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i ++)
		cin >> s[i][1] >> s[i][2];
	string t1, t2;
	while(q --)
	{
		cin >> t1 >> t2;
		int cnt = 0;
		for(int x = 1; x <= n; x ++)
			if(check(x, t1, t2))
				cnt ++;
		cout << cnt << endl;
	}
	return 0;
}
