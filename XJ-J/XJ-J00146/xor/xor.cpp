#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n , k , a[N] , ans , cnt0 , cnt1;
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		cnt0 += (a[i] == 0 ? 1 : 0);
		cnt1 += a[i];
	}
	if(k == 0){
		if(cnt0 > 0){
			ans += cnt0;
			for(int i = 2;i <= n;i++){
				if(a[i - 1] == 1 && a[i] == 1){
					ans++;
					a[i] = 0;
				}
			}
			cout<<ans;
		}else{
			cout<<n / 2;
		}
	}else{
		cout<<cnt1;
	}
}
