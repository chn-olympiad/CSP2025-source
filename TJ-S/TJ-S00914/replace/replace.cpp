#include<bits/stdc++.h>
using namespace std;
const int maxn = 200006;
string s[maxn][2];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	while(q--){
        for(int i = 0; i <= n; i++){
            cin >> s[i][1] >> s[i][2];
        }
	}
	return 0;
}
