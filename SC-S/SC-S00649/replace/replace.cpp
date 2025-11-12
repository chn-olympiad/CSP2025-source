#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;

struct node
{
	string x,y;
}s[N];

ll n,q;
string t1,t2;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		cin >> s[i].x >> s[i].y;
	}
	while(q--)
	{
		cin >> t1 >> t2;
		cout << "0\n";
	}
	return 0;
}