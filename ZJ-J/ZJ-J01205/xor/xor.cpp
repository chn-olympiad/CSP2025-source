#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+9;
ll n, k, a[N], ans=0;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
	scanf("%lld %lld", &n,&k);
	for(ll i=1;i<=n;i++){
		scanf("%lld", &a[i]);
		if(a[i]==k){
			ans++;
		}
	}
	ll nxor = a[1];
	ll st =1;
	while(a[st]==k&&st<n){
		st++;
	}
	nxor=a[st];
	ll j2 = st;	
	for(ll i=st+1;i<=n;i++){
		if(a[i]==k){
			i++;
			while(a[i]==k&&i<n){
				i++;
			}
			nxor = a[i];
			j2 = i;
			continue;
		}
		nxor = nxor xor a[i];
		if(nxor==k){
			ans++;
			i++;
			while(a[i]==k&&i<n){
				i++;
			} 
			nxor=a[i]; 
			j2 = i;
			continue;
		}
		ll nxor2 = nxor;
		ll j3 = j2;
		while(j3 < i){
			nxor2 = nxor2 xor a[j3];
			j3++;
			if(nxor2 == k){
				ans++;
				i++;
				while(a[i]==k&&i<n){
					i++;
				} 
				j2 = i;
				nxor = a[i];
				break;
			}
		}
	} 
	printf("%lld", ans);
	return 0;
}