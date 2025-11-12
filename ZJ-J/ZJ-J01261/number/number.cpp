#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> s;
	for(auto c : s) if('0' <= c && c <= '9') a.push_back(c - '0');
	sort(a.begin(),a.end(),[](int x,int y){return (x > y);});
	for(auto x : a) cout << x;
}
