#include <bits/stdc++.h>

using namespace std;
bool cmp1(int a[4],int b[4]){
	if (a[2] == b[2]){
		return a < b;
	}else{
		if (a[2] > b[2]){
			return a > b;
		}else{
			return a < b;
		}
	}
}
bool cmp2(int a[4],int b[4]){
	if (a[1] == b[1]){
		return a < b;
	}else{
		if (a[1] > b[1]){
			return a > b;
		}else{
			return a < b;
		}
	}
}
int main() {
	freope("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[10009][4],c1 = 0,c2 = 0,c3 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int maxn = max({a[i][1],a[i][2],a[i][3]});
			if (a[i][1] == maxn){
				a[i][0] = 1;
				c1++;
			}else if(a[i][2] == maxn){
				a[i][0] = 2;
				c2++;
			}else{
				a[i][0] = 3;
				c3++;
			}
		}
	}
	cout << c1 << " " << c2 << " " << c3;
	return 0;
}
