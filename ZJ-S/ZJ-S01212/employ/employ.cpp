#include<bits/stdc++.h>
using namespace std;
const int N = 550, P = 998244353;
int n, m, tk[N];
long long sum = 1;
string hd;
int main(){
	
	freopen("employ3.in", "r", stdin);
	freopen("employ3.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	cin >> hd;
	int ci, cnt = 0;
	for(int t = 0; t < n; t ++){
		scanf("%d", &ci);
		if(ci == 0){
			cnt ++;
			n --;
		}
	}
	if(n <= m){
		printf("0");
		return 0;
	}
	for(int t = 1; t <= n; t ++){
		sum *= t;
		sum %= P;
	}
	for(int t = 1; t <= cnt; t ++){
		sum *= t;
		sum %= P;
	}
	printf("%lld", sum);
	
}