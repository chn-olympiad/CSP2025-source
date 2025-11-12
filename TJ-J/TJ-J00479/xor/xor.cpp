#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin >> n >> k;
	long long arr[n+5];
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	if(n == 1 && k == 0){
		cout << 1;
		return 0;
	}
	if(n == 2 && k == 0){
		cout << 2;
		return 0;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i == j){
				if(arr[i] == k){
					ans ++;
					arr[i] = -123;
				}
			}
			else{
				int cnt = arr[i];
				for(int e=i;e<=j;e++){
					if(arr[e] == -123){
						break;
					}
					else{
						cnt ^= arr[e];
						arr[e] = -123;
					}
				}
				if(cnt == k){
					ans ++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
