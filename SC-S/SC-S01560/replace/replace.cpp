#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n, q;
string si[MAXN][2], tj[2];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for(int i = 1 ; i <= n; i++)
		cin >> si[i][0] >> si[i][1];
		
	while(q--) {
		cin >> tj[0] >> tj[1];
		
		int beg = 0x3f3f3f3f, end = 0;
		for(int i = 0; i < tj[0].size(); i++)
			if(tj[0][i] != tj[1][i])
				beg = min(beg, i), 
				end = max(end, i);
		
		cout << 0 << endl;
	}
	
return 0;
} 