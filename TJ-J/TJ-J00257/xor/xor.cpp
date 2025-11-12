#include <bits/stdc++.h>
using namespace std;
const int MAX = 5 * 1e5 + 4;
int num[MAX];



int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n , k , ans = 0;
	cin >> n >> k;
	bool yes = true;
	for(int i = 0;i < n;i ++){
		cin >> num[i];
		if(num[i] != 1){
			yes = false;
		}
	}
	if(yes && n == 2 && k == 0){
		cout << 1 << "\n";
		return 0;
	}
	if(yes && k == 0){
		cout << n / 2 << "\n";
		return 0;
	}
	if(k == 0){
	
		for(int i = 0;i < n;i ++){
	//		cout << "num[" << i << "] = " << num[i] << "\n";
			if(!num[i]){
				ans ++;
			}
			if(num[i] == 1){
				if(num[i + 1] == 1){
					ans ++;
					i ++;
				}
			}
		}
	}
	if(k == 1){
		for(int i = 0;i < n;i ++){
	//		cout << "num[" << i << "] = " << num[i] << "\n";
			if(num[i] == 1){
				ans ++;
			}
		}
	}
	cout << ans << "\n";
//	011000
	
	
	
	
	
	return 0;
}
