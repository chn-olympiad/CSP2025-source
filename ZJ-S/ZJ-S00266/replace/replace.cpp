#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string s[N][2], t1, t2;
int pos[N][2];
int n, q;
int res;
void count(int x)
{
	string s1 = s[x][0], s2 = s[x][1];
	for(int i = 0; i + s1.size() <= t1.size(); i ++)
	{
		if(t1.substr(i, s1.size()) == s1)
		{
			string s3 = t1.substr(0, i), s4 = t1.substr(i + s1.size());
			if(s3 + s2 + s4 == t2) res ++;
		}
	}
}
void work1()
{
	res = 0;
	for(int i = 1; i <= n; i ++)
		count(i);
	cout << res << endl;
}

bool check()
{
	
}
void work2()
{	
	for(int i = 1; i <= n; i ++)
	{
		while(pos[i][0] < s[i][0].size() && s[i][0][pos[i][0]] != 'b') pos[i][0] ++;
		while(pos[i][1] < s[i][1].size() && s[i][1][pos[i][1]] != 'b') pos[i][1] ++;
	}
	while(q --)
	{
		res = 0;
		cin >> t1 >> t2;
		int p1 = 0, p2 = 0;
		while(p1 < t1.size() && t1[p1] != 'b') p1 ++;
		while(p2 < t2.size() && t2[p2] != 'b') p2 ++;
		for(int i = 1; i <= n; i ++)
			if(p1 >= pos[i][0] &&  (p1 - p2 == pos[i][0] - pos[i][1]) && (t1.size() - p1 >= s[i][0].size() - pos[i][0]))res ++;
		cout << res << endl;
	}
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int cnt = 0;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++)
	{
		cin >> s[i][0] >> s[i][1];
		cnt += 2 * s[i][0].size();
		
	} 
	if(cnt <= 10010)
	{
		for(int i = 1; i <= q; i ++)
		{
			cin >> t1 >> t2;
			work1();
		}
		return 0;
	}
	else work2();
	
	return 0;
}

