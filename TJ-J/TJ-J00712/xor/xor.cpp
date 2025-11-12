#include <bits/stdc++.h>
using namespace std;
int gcm(int a, int b){
	return b == 0 ? a : gcm(b, a % b);
} 
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	cout << gcm(a, b) << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
