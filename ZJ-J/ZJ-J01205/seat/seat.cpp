#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+9;
ll n, m, a[N], small_a;
bool cmp(ll sb1, ll sb2){
	return sb1 > sb2;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
	scanf("%lld %lld", &n,&m);
	for(ll i=1;i<=n*m;i++){
		scanf("%lld", &a[i]);
	}
	small_a = a[1];
	sort(a+1, a+1+n*m, cmp);
	ll pa = 0;
	for(ll i=1;i<=n*m;i++){
		if (a[i]==small_a){
			pa = i;
		}
	}
	printf("%lld ", (pa-1)/n+1);
	if(((pa-1)/n)%2==0){
		ll paa = (pa-1) % n+1;
		printf("%lld", paa);
	}else{
		ll paa = n - (pa-1) % n;
		printf("%lld", paa);
	}
	return 0;
}