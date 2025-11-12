#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int> a(n * m);
	cin >> a[0];
	int x = a[0];
	for (int i = 1; i < n * m; i++){
		cin >> a[i];
	}
	sort(a.rbegin(),a.rend());
	int h = 1,l = 1;
	for (int i = 0; i < n * m; i++){
		if (a[i] == x){
			cout << l << ' ' << h;
			break;
		}
		if (l % 2 == 0){
			if (h == 1){
				l++;
			}
			else{
				h--;	
			}
		}
		else{
			if (h == n){
				l++;
			}
			else{
				h++;
			}
		}
		
	}

	return 0;
}
