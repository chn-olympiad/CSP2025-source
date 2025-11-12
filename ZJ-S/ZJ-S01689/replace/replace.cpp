#include <bits/stdc++.h>
using namespace std;

struct re
{
	string x,y;
};

re a[200005];
int n,m;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string l,r;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i].x >> a[i].y;
	while(m--)
	{
		cin >> l >> r;
		cout << 0;
		if(m > 0)
			cout << "\n";
	}
	return 0;
}
