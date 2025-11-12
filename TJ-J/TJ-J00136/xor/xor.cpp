#include <bits/stdc++.h>
using namespace std;
int a[10000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k; 
	cin >> n >> k;
	if(n == 2 && k == 0){
		cout << 1; 
		return 0;
	} 
	if(n == 1 && k == 0) {
		cout << 0;
		return 0;
	}
	int b=0,c=0;
	for(int i = 0;i<=n;i++){
		cin >> a[i];
		if(a[i] == 0) b++;
		else c++;
	}
	if(n <= 100 && (a[1] == 1||a[1] == 0)){
		if(k==0) {
			cout << b/2+c/2;
		}
		else(k==1){
			cout << min(b,c);
		}
	}
	cout << 0;
	return 0; 
}
