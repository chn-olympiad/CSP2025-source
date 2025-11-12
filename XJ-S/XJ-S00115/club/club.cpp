#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long T, n, a1[N], a2[N], a3[N], cnt, maxn;

void run1(){
	sort(a1 + 1, a1 + n + 1);
	maxn = 0;
	cnt = n / 2;
	while(cnt--){
		maxn += a1[n--];
	}
}
void run2(){
	maxn = 0;
	maxn = max(maxn, a1[1] + a2[2]);
	maxn = max(maxn, a2[1] + a1[2]);
	
}
void in_run(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a1[i] >> a2[i] >> a3[i];
	}
	if (n <= 2) run2();
	else run1();
	
}


int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >>T;
	while (T--){
		in_run();
		cout << maxn << endl;
	}
	
	
	
	
	
	
	
	
	return 0;
}
