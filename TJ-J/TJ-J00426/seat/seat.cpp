#include<bits/stdc++.h>
using namespace std;
int n, m, a[105], R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	R = a[1];
	int Rp = 0;
	for(int i = 1;i <= n * m;i++){
		if(a[i] > R){
			Rp++;
		}
	}
	int s = Rp / n, d = Rp % n;
	if(s % 2 == 0){
		cout << s + 1 << ' ' << d + 1;
	}
	else{
		cout << s + 1 << ' ' << m - d;
	}
	return 0;
}
