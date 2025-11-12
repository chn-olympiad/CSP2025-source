#include <iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (n < 3){
		cout << 0;
	}
	else{
		if (n == 3){
			int maxx = 0,sumn = 0;
			for (int i = 1; i <= 3; i++){
				maxx = max(maxx,a[i]);
				sumn += a[i];
			}
			if (sumn > maxx * 2){
				cout << 1;
			}
		}
	}
	return 0;
}
