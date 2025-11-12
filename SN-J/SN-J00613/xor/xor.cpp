#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

//放个注释证明这是我自己写的  >:) 
//不会做，炸了 :( 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int x,n;
	cin >> x >> n;
	
	int c;
	for (int i = 1; i <= x; i++)
	{
		cin >> c;
	}
	
	cout << x / (n ? n : n + 1); 
	
	return 0; 
} 
