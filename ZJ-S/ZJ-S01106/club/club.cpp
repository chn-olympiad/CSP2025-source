#include<bits/stdc++.h>
using namespace std;
//int testcase = 0;
int a[100005][5];
vector<int> w[4];
void solve(){
	int n;
	cin >> n;
	w[1].clear();
	w[2].clear();
	w[3].clear();
	for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin >> a[i][j];
	int cnta = 0, cntb=0, cntc=0;
	for(int i=1;i<=n;i++) {
//		cout << a[i][1] << " " << a[i][2] << " " << a[i][3] << endl;
		if(a[i][1]>=a[i][2] and a[i][1]>=a[i][3]) cnta++, w[1].push_back(i);
   else if(a[i][2]>=a[i][1] and a[i][2]>=a[i][3]) cntb++, w[2].push_back(i);
   else if(a[i][3]>=a[i][2] and a[i][3]>=a[i][1]) cntc++, w[3].push_back(i);
	}
//	cout << cnta << " " << cntb << " " << cntc << endl;
	if(cnta > n/2){
		int d = cnta - n/2;
		sort(w[1].begin(), w[1].end(), [](int i, int j){
			return a[i][1] - max(a[i][2], a[i][3]) < a[j][1] - max(a[j][2], a[j][3]);
		});
		for(int i=0;i<d;i++){
			int r = w[1][i];
			w[a[r][2] > a[r][3]?2:3].push_back(r);
		}
		int ans = 0;
		for(int i: w[2]) ans += a[i][2];
		for(int i: w[3]) ans += a[i][3];
		for(int i=d;i<w[1].size();i++){
			ans += a[w[1][i]][1];
		}
		cout << ans << endl;
		
	}else if(cntb > n/2){
		int d = cntb - n/2;	
		sort(w[2].begin(), w[2].end(), [](int i, int j){
			return a[i][2] - max(a[i][1], a[i][3]) < a[j][2] - max(a[j][1], a[j][3]);
		});
		for(int i=0;i<d;i++){
			int r = w[2][i];
			w[a[r][1] > a[r][3]?1:3].push_back(r);
		}
		int ans = 0;
		for(int i: w[1]) ans += a[i][1];
		for(int i: w[3]) ans += a[i][3];
		for(int i=d;i<w[2].size();i++){
			ans += a[w[2][i]][2];
		}
		cout << ans << endl;
	}else if(cntc > n/2){
		int d = cntc - n/2;
		sort(w[3].begin(), w[3].end(), [](int i, int j){
			return a[i][3] - max(a[i][2], a[i][1]) < a[j][3] - max(a[j][2], a[j][1]);
		});
		for(int i=0;i<d;i++){
			int r = w[3][i];
			w[a[r][2] > a[r][1]?2:1].push_back(r);
		}
		int ans = 0;
		for(int i: w[1]) ans += a[i][1];
		for(int i: w[2]) ans += a[i][2];
		for(int i=d;i<w[3].size();i++){
			ans += a[w[3][i]][3];
		}
		cout << ans << endl;
	}else{
		int ans = 0;
		for(int i: w[1]) ans += a[i][1];
		for(int i: w[2]) ans += a[i][2];
		for(int i: w[3]) ans += a[i][3];
		cout << ans << endl;
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}