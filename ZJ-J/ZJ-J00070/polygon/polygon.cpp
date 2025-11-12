#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long int cnt = 0;
int sum = 0;
int max_a = 0;
int a[5005] = {};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;++i){
		cin >> a[i];
	}
	for(int i = 3;i <= n;++i){
		for(int j = 0;j <= n - i;++j){
			sum = 0;
			max_a = 0;
			for(int k = j;k < j + i;++k){
				if (a[k] > max_a) max_a = a[k];
				sum += a[k];
			}
			if (sum > 2 * max_a) cnt++;
		}
	}
	cout << cnt % 998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
