#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500001],b[500001],maxx = 0,cnt = 0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i =1;i<=n;i++){
		cin >> a[i];
		a[i] ^= a[i-1];
		a[i] ^= k;
		b[a[i]]++;
		cnt = max(cnt,a[i]);
	}
	for(int i =1;i<=cnt;i++){
		maxx = max(maxx,b[i]);
	}
	cout << maxx;
	return 0;
}
