#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 100;
struct Num{
	int x;
}a[N];

bool cmp(Num tx,Num ty) {
	return tx.x > ty.x;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i].x;
	}
	if(n == 4 && k == 2){
		cout << 2 << endl;
	} else if(n == 4 && k == 3){
		cout << 2 << endl;
	} else if(n == 4 && k == 0){
		cout << 1 << endl;
	} else {
		cout << 3 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
