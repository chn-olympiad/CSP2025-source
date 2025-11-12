//武岳桐 SN-J00669 西安建筑科技大学附属中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freapen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, s[10005], d;
	cin >> n >> m;
	for(int i = 0;i < n * m;i++){
		cin >> s[i];
		if(i == 0){
			d = s[i];
		}
	}
	int q = -1;
	for(int i = 0;i < n * m;i++){
		for(int j = 0;j < n * m;j++){
			if(s[j + 1] > s[j]) swap(s[j], s[j+ 1]);
 		}
	}
	for(int i = 0;i < n * m;i++){
		if(s[i] == d){
			q = i;
			break;
		}
	}
	int f = q, g = q, w = n * m, e = 1;
	if(f / n % 2 == 0){
		cout << f / n + 1 << " " << f % n + 1;
	}
	else{
		cout << f / n + 1 << " " << n - (f % n);
	}
	return 0;
}
