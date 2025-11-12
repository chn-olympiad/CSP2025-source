#include <iostream>
#include <cstdio>
using namespace std;

int n,ans = 1;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		ans *= i;
	}
	cout << ans;
	return 0;
}
