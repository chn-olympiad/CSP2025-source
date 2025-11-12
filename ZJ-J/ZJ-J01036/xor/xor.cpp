#include<bits/stdc++.h>
using namespace std;
long long n,K,a[500005],ans;
const long long MAX = 2500000000;

void solve(){
	cin >> n >> K;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] == K){
			ans++;
			a[i] = MAX;
		}
	}
	for(int i = 1;i < n;i++){
		for(int j = 1;j <= n - i;j++){
			bool f = 1;
			int k = j + i;
			int sum = a[j];
			for(int sb = j + 1;sb <= k;sb++){
				sum = sum ^ a[sb];
				if(a[sb] == MAX){
					f = 0;
					break;
				}
			}
			if(sum == K && f){
				ans++;
				for(int sb = j + 1;sb <= k;sb++){
					if(a[sb]) a[sb] = MAX;
				}
				j = k + 1;
			}
		}
	}
	cout << ans;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
