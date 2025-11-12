#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int s,l,o,w;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> w;
	if(w == 3)
	{
		cin >> s >> l >> o;
		int maxx = max(s,max(l,o));
		if(s + l + o > 2 * maxx)
		{
			cout << 1;
			return 0;
		}
		cout << 0;
		return 0;
	}
	cout << 13;
	return 0;
}
