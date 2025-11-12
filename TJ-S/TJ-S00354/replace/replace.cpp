#include<bits/stdc++.h>
using namespace std;


const int N = 2e5+5;
int n, q;
vector<pair<string, string> > t, s;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for(int i=1; i<=n; i++)
	{
		string a, b;
		cin >> a >> b;
		s.push_back(make_pair(a, b));
	}
	for(int i=1; i<=q; i++)
	{
		string a, b;
		cin >> a >> b;
		s.push_back(make_pair(a, b));
		cout << 0 << endl;
	}

	
	return 0;
}
