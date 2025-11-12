#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int a[100009];
	int ans = 0;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if (k == 0){
		int l = 0;
		for (int i = 1;i <= n;i++){
			if (a[i] == 0){
				l++;
			}else{
				ans += pow(2,l-1);
			}
		}
	}
	else if(k == 1){
		int l = 0;
		for (int i = 1;i <= n;i++){
			if (a[i] == 1){
				l++;
			}else{
				ans += pow(2,l-1);
			}
		}
	}else{
		int g;
		ans = g;
	}
	cout << ans;
	return 0;
}
