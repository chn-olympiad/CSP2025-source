#include <bits/stdc++.h>
using namespace std;

int n,m;
const int N = 1e4;
struct Num {
	int x;
}a[N];

bool cmp(Num tx,Num ty) {
	return tx.x > ty.x;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;	
	int ans = n * m;
	for(int i = 1;i <= ans;i++) {
		cin >> a[i].x;
	}
	int w = a[1].x;
	int sum = 0;
	sort(a + 1,a + 1 + ans,cmp);
	for(int i = 1;i <= ans;i++) {
		if(a[i].x > w) {
			sum ++;
		}
	}
	int l = sum / n;
	if(l == 0) {
		cout << l + 1 << " " << n - sum + 1;
	} else if(sum % n == 0){
		if((sum / n) % 2 == 0) {
			cout << l + 1 << " " << 1;
		} else {
			cout << l + 1 << " " << n;
		}		
	} else if(sum > n){
		cout << l + 1 << " " << n - (sum - l * n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
