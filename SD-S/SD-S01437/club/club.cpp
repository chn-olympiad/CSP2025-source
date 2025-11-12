#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>

using namespace std;
const int N = 1e5+10;
int n;

struct Node {
	int a,b,c; //¶ÔabcÃÅ
	int mmax_;
} wu[N];



bool cmp(const Node & a,const Node &b) {
	return a.mmax_ > b.mmax_;
}



int main() {
	//freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		long long ans;
		cin >> n;
		int kk = n/2;
		for(int i = 1 ; i <= n ; i++) {
			cin >> wu[i].a >> wu[i].b >> wu[i].c;
			wu[i].mmax_ = max(max(wu[i].a,wu[i].b),wu[i].c);
		}
		sort(wu+1,wu+1+n,cmp);
		for(int i = 1 ; i <= n ; i++) {
			ans += wu[i].mmax_;
		}
	}

	cout << ans;

	return 0;
}
