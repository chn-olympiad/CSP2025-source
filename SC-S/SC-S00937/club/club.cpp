#include<bits/stdc++.h>
using namespace std;
int t, n, a[100010][4];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdin);
	cin >> t;
	while(t--){
		cin >> n;
		int sum = n/2;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >> a[i][j];
			}
		}
		int ans1 = -1, ans2 = -1, ans3, ans4, ans5 = -1, ans6 = -1, ans7, ans8;
		for(int i = 1; i <= 3; i++){
			if(a[1][i] > ans1){ 
				ans1 = a[1][i]; 
				ans3 = i;
			}else if(a[1][i] > ans5){
				ans5 = a[1][i];
				ans7 = i;
			}
		}
		for(int i = 1; i <= 3; i++){
			if(a[2][i] > ans2){
				ans2 = a[2][i];
				ans4 = i;
			}else if(a[2][i] > ans6){
				ans6 = a[2][i];
				ans8 = i;
			}
	    }
	    cout << ans1 << ' ' << ans2 << ' ' << ans3 << ' ' << ans4 << ' ' << ans5 << ' ' << ans6 << ' ' << ans7 << ' ' << ans8 << '\n';
	    if(ans3 != ans4){
	    	cout << ans1+ans2;
		}else{
			if(ans5+ans2 > ans6+ans1){
				//cout << "ans2=" << ans2 << " " << "ans5=" << ans5 << '\n';
				cout << ans5+ans2;
			}else{
				//cout << "ans1=" << ans1 << ' ' << "ans6=" << ans6 << '\n';
				cout << ans6+ans1;
			}
		}
	}
	return 0;
}