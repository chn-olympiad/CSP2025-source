#include<bits/stdc++.h>
using namespace std;

char a;
int b[200], c = -1;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 0; i <= 1000005; i++){
		cin >> a;
		b[int(a) - 48]++;
	}
	for (int i = 9; i >= 0; i--){
		for (int j = 1; j <= b[i]; j++){
			cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
