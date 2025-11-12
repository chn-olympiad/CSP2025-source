#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n , q , l , r , cnt;
string a[100005][2] , b[100005][2] , s1 , s2 , s3 , s4;
string cal(string a , int b , int c)
{
	string s;
	for (int i = b;i <= c;i ++) s += a[i];
	return s;
}
bool find(string s1 , string s2)
{
	if  (s1.size() > s2.size() || (s1.size() == s2.size() && s1 != s2)) return false;
	bool f;
	for (int i = 0;i + int(s2.size()) <= int(s1.size());i ++)
	{
		f = 1;
		for (int j = i;j <= i + int(s2.size());j ++)
		{
			if  (s1[j] != s2[j - i])
			{
				f = 0;
				break;
			}
		}
		if  (f) return true;
	}
	return false;
}
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1;i <= n;i ++)
		cin >> a[i][0] >> a[i][1];
	for (int i = 1;i <= n;i ++)
	{
		if  (a[i][0] == a[i][1]) 
		{
			b[i][0] = b[i][1] = a[i][0];
			continue;
		}
		for (int j = 0;j < int(a[i][0].size());j ++)
		{
			if  (a[i][0][j] != a[i][1][j])
			{
				l = j;
				break;
			}
		}
		for (int j = int(a[i][0].size()) - 1;j >= 0;j --)
		{
			if  (a[i][0][j] != a[i][1][j])
			{
				r = j;
				break;
			}
		}
		b[i][0] = cal(a[i][0] , l , r) , b[i][1] = cal(a[i][1] , l , r);
	}
	while (q --)
	{
		cnt = 0;
		cin >> s1 >> s2;
		for (int i = 0;i < int(s1.size());i ++)
		{
			if  (s1[i] != s2[i])
			{
				l = i;
				break;
			}
		} 
		for (int i = int(s1.size()) - 1;i >= 0;i --)
		{
			if  (s1[i] != s2[i])
			{
				r = i;
				break;
			}
		}
		s3 = cal(s1 , l , r) , s4 = cal(s2 , l , r);
		for (int i = 1;i <= n;i ++)
		{
			if  (b[i][0] == s3 && find(s1 , s3) && b[i][1] == s4) ++ cnt;
		}
		cout << cnt << "\n";
	}
	return 0;
}
