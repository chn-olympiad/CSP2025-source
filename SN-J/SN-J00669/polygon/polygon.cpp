//武岳桐 SN-J00669 西安建筑科技大学附属中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, s = 0, d = -1;
	long long f = 0;
	cin >> n;
	int a[5005];
	if(n < 3){
		cout << "0";
		return 0;
	}
	for(int i = 0;i < n;i++){
		cin >> a[i];
		s += a[i];
		if(d < a[i]) d = a[i];
	}
	if(n == 3){
		if(s > 2 * d){
			cout << "1";
			return 0;
		}
		else{
			cout << "0";
			return 0;
		}
	}
	for(int i = n;i > 0;i--){
		f += i;
	}
	cout << f;
	return 0;
}
