// Homeward you come, distant wind. -- Cipher

// Expect: 100pts

#include <bits/stdc++.h>

#define ll long long

using namespace std; 

#define pii pair<int, int>
#define x first
#define y second

string str; 
int a[10]; 

signed main()
{
	freopen("number.in", "r", stdin); 
	freopen("number.out", "w", stdout); 
	
	cin.tie(nullptr) -> sync_with_stdio(false); 

	cin >> str; 
	for(char it : str) if(isdigit(it)) a[it - '0'] ++;

	for (int i = 9; i >= 0; i --)
		for (int j = 1; j <= a[i]; j ++) cout << i;

	cout << '\n'; 

	return 0; 
}