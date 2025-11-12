#include<bits/stdc++.h>
using namespace std; 
int n, t, ma1 = 0, ma2 = 0, te, cnt = 0;
struct str{
	int b[5] = {}, otc = 0, otma = 0, ottma = 0;
}a[114514];
bool cmp(str s, str g);
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 0; i < t; i++){
		int mama1 = 0,mama2 = 0;
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> a[j].b[0] >> a[j].b[1] >> a[j].b[2];
			a[j].otc = a[j].b[0] - a[j].b[1];
		}
		sort(a, a + n, cmp);
		for(int j = 0; j < n; j++){
			if(a[j].otc >= 0 && j < n / 2){
				a[j].otma = a[j].b[0];
			}else{
				a[j].otma = a[j].b[1];
			}
		}
		for(int j = 0; j < n; j++){
			a[j].otc = a[j].otma - a[j].b[2];
		}
		sort(a, a + n, cmp);
		for(int k = n / 2 - 1; k <= n; k++){
			for(int j = 0; j < n; j++){		
				if(a[j].otc >= 0 && j < k && j < n / 2 + cnt){
					a[j].ottma = a[j].otma;
				}else{
					a[j].ottma = a[j].b[2];
				}
			}
			for(int j = 0; j < n; j++){
			//	cout << a[j].ottma;
				ma1 += a[j].ottma;
			}
			mama1 = max(mama1, ma1);
			ma1 = 0;
		}
		for(int j = 0; j < n; j++){
			te = a[j].b[1];
			a[j].b[1] = a[j].b[2];
			a[j].b[2] = te;
			a[j].otc = a[j].b[0] - a[j].b[1];
		}
		for(int j = 0; j < n; j++){
			cin >> a[j].b[0] >> a[j].b[1] >> a[j].b[2];
			a[j].otc = a[j].b[0] - a[j].b[1];
		}
		sort(a, a + n, cmp);
		for(int j = 0; j < n; j++){
			if(a[j].otc >= 0 && j < n / 2){
				a[j].otma = a[j].b[0];
			}else{
				a[j].otma = a[j].b[1];
			}
		}
		for(int j = 0; j < n; j++){
			a[j].otc = a[j].otma - a[j].b[2];
		}
		sort(a, a + n, cmp);
		for(int k = n / 2 - 1; k <= n; k++){
			for(int j = 0; j < n; j++){		
				if(a[j].otc >= 0 && j < k && j < n / 2 + cnt){
					a[j].ottma = a[j].otma;
				}else{
					a[j].ottma = a[j].b[2];
				}
			}
			for(int j = 0; j < n; j++){
			//	cout << a[j].ottma;
				ma2 += a[j].ottma;
			}
			mama2 = max(mama1, ma1);
			ma1 = 0;
		}
		cout << max(mama1, mama2) << "\n";
	} 
	return 0;
}
bool cmp(str s, str g){
	return s.otc > g.otc;
}
