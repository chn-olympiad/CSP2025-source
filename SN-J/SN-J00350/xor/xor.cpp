#include <bits/stdc++.h>
using namespace std;

int main(){
	int n , a[500001] , k , cnt = 0 , x=0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(k == 1){
		for(int i = 1; i <= n; i++){
			if(a[i] == 1){
				cnt++;
			}
		}
		cout << cnt;
	}
	else if(k == 0){
		for(int i = 1; i <= n; i++){
			if(a[i] == 0){
				cnt++;
			}
			else if(a[i] == x){
				cnt++;
				x = 0;
			}
			x = a[i];
		}
		cout << cnt;
	}
	return 0;
}
