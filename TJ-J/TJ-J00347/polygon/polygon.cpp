#include <iostream> 
using namespace std;
int main(){
	int n,ans; 
	cin >> n; 
	if(n < 3){
		cout << 0;
		return 0;
	} 
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	if(n > 3){
	    ans = 1;
	}else{
		ans = 0;
	}
	for(int i = 0; i < n; i++){
		for(int j = 1+i; j < n; j++){
			for(int k = j + 1; k < n; k++){
				if(a[i] + a[j] > a[k]){
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
} 
