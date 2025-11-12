#include <iostream> 
#include <cstring>
using namespace std;
int main(){
	string s;
	cin >> s;
	int n = s.size(), m = 0;
	long long a[n] = {}, b[n] = {};
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){
			m++;
		}
		if(s[i] >= '0' && s[i] <= '9'){
			a[i] = s[i] - '0';
		}
	}
	for(int i = 0; i < n; i++){
	    int max =-99999999999;
		for(int j = 0; j < n; j++){
			if(a[j] > max){
				max = a[j];
			}
		}
		b[i] = max;
		for(int j = 0; j < n; j++){
			if(a[j] ==max){
				a[j] = 0;
				break;
			} 
		}
	}
	long long ans = 0;
	for(int i = 0; i < n; i++){
		if(b[i] != 0){
			ans = ans*10 + b[i];
		}
	}
	for(int i = 0; i < m; i++){
		ans = ans * 10;
	}
	cout << ans;
	/*
	string s;
	cin > s;
    if(s.size() - 1 == 1) cout << s;
    */
	return 0;
}
