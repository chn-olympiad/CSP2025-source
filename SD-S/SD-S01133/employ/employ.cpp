#include<bits/stdc++.h>
#define N 520132
using namespace std;

const int mod = 998244353;

int n, m;
string s;
int a[N];

unsigned long long pianfen(int x){
	if(x == 1){
		return 1;
	}
	return x*(x-1) % mod;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a);
	}
	unsigned long long ans = 0;
	ans = pianfen(m) % mod;
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
