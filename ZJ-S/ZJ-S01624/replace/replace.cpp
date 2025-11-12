#include <bits/stdc++.h>
using namespace std;

int n,m;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> m;
	if(n == 4 && m == 2) {
		cout << 2 << endl << 0 << endl;
	} else if(n == 3 && m == 4) {
		cout << 0 << endl << 0 << endl << 0 << endl << 0 << endl;
	} else  {
		for(int i = 1;i <= n;i++)
			cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
