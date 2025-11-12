#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,ans,b[1001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	vector<ll> a(n+1,0);
	for(ll i = 1;i<=n;i++){
		cin >> a[i];
		b[i] = b[i-1] ^ a[i];
	}
	for(ll i = 1;i<=n;i++){
		for(ll j = 1;j<=n;j++){
			if(b[j] ^ b[i-1] == k &&  b[j] != -1 && b[i-1] != -1){
				ans++;
				b[j] = -1;
				b[i-1] = -1;
			}
		}
	}cout<< ans-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
