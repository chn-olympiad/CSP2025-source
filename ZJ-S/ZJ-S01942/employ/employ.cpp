#include<bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
struct pes{
	int a, b, c;
	int id;
}ps[100005];

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> ps[i].a >> ps[i].b >> ps[i].c;
			ps[i].id = i;
		}
	}
	return 0;
}
