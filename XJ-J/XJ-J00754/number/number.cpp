#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sp ' '

typedef long long ll;
typedef double db;

typedef vector <int> vi; 

int num[10];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> s;
	for (auto i : s)
	    if (i >= '0' && i <= '9')
	        ++num[i - '0'];

	for (int i = 9; i >= 0; i--)
	    for (int j = 0; j < num[i]; j++)
            cout << i;
	cout << endl;
	
	return 0;
} 
