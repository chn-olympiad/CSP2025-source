#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,r;
	cin >> n >> r;
	int a[200000];
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 1;i <= n;i ++){
		for(int j = i;j <= n;j ++){
			int sum = a[i];
			for(int k = i+1;k <= j;k ++){
				sum = sum^k;
			}
			if(sum==r) ans++;
		}
	}
	cout << ans;
	return 0;
}
