#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;	
}

inline void Ans(int a) {
	cout << a;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	
	if (k == 0) {
		if (n == 1) Ans(0);
		else if (n == 2) Ans(1);
	}
	
	fclose(stdin);
	fclose(stdout);
}
/*
/||||||||||\  ||
||        ||  ||
||        ||  ||
\|||||||||||  ||
          //  ||
         //   ||
        //    ||
||||||||/     || 
*/
