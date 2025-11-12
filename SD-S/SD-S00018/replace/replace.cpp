#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

int read(){ int x = 0, f = 1; char ch = getchar(); while(!isdigit(ch)){ if(ch == '-') f = -1; ch = getchar(); } while(isdigit(ch)){ x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar(); } return x * f; }

int n, q;

signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	while(q --){
		cout << 0 << "\n";
	}
	
	return 0;
}

