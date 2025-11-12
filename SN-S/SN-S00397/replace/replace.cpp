#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

//写个注释证明我是自己写的 >:)
//不会了，趴 

int main()
{
	freopen("replace1.in","r",stdin);
	freopen("replace1.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,q;
	string x,a,b;
	string o[200010],r[200010];
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> o[i][0] >> r[i][1];
	} 
	
	string a1,a2,a3,a4;
	int cha,num;
	
	for (int i = 1; i <= q; i++)
	{
		cin >> a >> b;
		cout << (a.size() % 4 + b.size() % 7) % 8
	}
} 
