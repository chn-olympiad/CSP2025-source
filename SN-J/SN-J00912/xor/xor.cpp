#include <iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,x;
	cin >> n;
	bool flag = true;
	for (int i = 1; i <= n; i++){
		cin >> x;
		if (x != 1){
			flag = false;
		}
	}
	if (flag){
		if (n % 2 == 0){
			cout << n / 2;
		}
		else{
			cout << n / 2 - 1;
		}
	}
	return 0;
}
