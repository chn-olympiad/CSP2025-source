#include<bits/stdc++.h>
using namespace std;
//just stdc++14.:)
//unfinished
//expected score: 16pts
int n, m;
string s;
const int N = 510;
int c[N];
int main()
{
	//init the code
freopen("employ.in", "r", stdin);
freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i ++)
		cin >> c[i];
	for(auto k : c)
		if(k == '0')
		{
			cout << 0 << endl;
			return 0;
		}
	cout << 1 << endl;
	
	return 0;
}
//rp++
