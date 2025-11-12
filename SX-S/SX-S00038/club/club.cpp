#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1e5;

#define endl "\n"

struct Goodness{
	int gn_fir;
	int gn_sec;
	int gn_thi;
	bool flag = false;
//	int most_gn;
//	int ord_gn[3] = {0};
}gn[SIZE + 1];

bool cmpA (Goodness x, Goodness y){
	return x.gn_fir > y.gn_fir;
}

void SolveA(int n){
	sort(gn, gn + n, cmpA);
	int ans = 0;
	for(int i = 0; i < n / 2; i++){
		ans += gn[i].gn_fir;
	}
	cout << ans << endl;
}

void Solve(){
	int n;
	cin >> n;
	bool A = true;
	for(int i = 0; i < n; i++){
		cin >> gn[i].gn_fir >> gn[i].gn_sec >> gn[i].gn_thi;
		if(!(gn[i].gn_sec == 0 && gn[i].gn_thi == 0)){
			A = false;
		}
//		gn[i].ord_gn[0] = gn[i].gn_fir;
//		gn[i].ord_gn[1] = gn[i].gn_sec;
//		gn[i].ord_gn[2] = gn[i].gn_thi;
	}

	if(A){
		SolveA(n);
	}
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		Solve();
	}
	return 0;
}