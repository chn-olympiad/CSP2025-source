#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],f = 0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int ans = 0;
	for(int i = 1;i <= n; i ++){
		cin >> a[i];if(a[i] != 1) f = 1;
	}
	if(k == 0){
		ans = n;cout << ans;return 0;
	}
	for(int i = 1;i <= n;i ++){
		if(a[i] == 0 && a[i - 1] == 1 && b[i - 1] == 0){
			ans ++;b[i - 1] = b[i] =1;
		}else if(a[i] == 0 && a[i + 1] == 1 && b[i +1] == 0){
			ans ++;b[i + 1] = b[i] =1;
		}
		if(a[i] == 1 && b[i] == 0 && a[i - 2] == 1 && b[i - 2] == 0&& a[i - 1] == 1 && b[i -1] == 0 && i >= 3&&i <= n){
			ans ++;b[i] = b[i -2]=b[i-1] = 1;
		}
		else if(a[i] == 1 && b[i] == 0 && a[i + 1] == 1 && b[i + 1] == 0&& a[i - 1] == 1 && b[i -1] == 0&& i >= 2 && i < n){
			ans ++;b[i] = b[i + 1]=b[i-1] = 1;
		}else if(a[i] == 1 && b[i] == 0 && a[i + 2] == 1 && b[i + 2] == 0&& a[i + 1] == 1 && b[i + 1] == 0 && i < n - 1){
			ans ++;b[i] = b[i +2]=b[i+1] = 1;
		}
	}
	cout << ans;
	return 0;
}
