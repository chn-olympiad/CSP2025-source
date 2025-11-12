#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MX = 2e5 + 10;
int n,q;
struct node
{
	string a;
	string b;
} mp[MX + 10];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i;
	cin >> n >> q;
	for(i = 1;i <= n;i++)
	{
		cin >> mp[i].a >> mp[i].b;
	}
	while(q--)
	{
		string s,t;
		cin >> s >> t;
		
	}
	cout << 0 << '\n';
	return 0;
}
