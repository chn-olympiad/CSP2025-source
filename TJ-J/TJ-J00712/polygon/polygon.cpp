#include <bits/stdc++.h>
using namespace std;
int gcm(int a, int b){
	return b == 0 ? a : gcm(b, a % b);
} 
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	cout << gcm(a, b) << endl;
	for(int i = 1; i <= a; i++){
		cout << i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
