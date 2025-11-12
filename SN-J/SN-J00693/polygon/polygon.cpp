#include <bits/stdc++.h>
using namespace std;
long long n, k, num, a[100], b[100];
int main(){
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		b[a[i]]++;
	}
	for(int i=1; i<=n; i++){
		if(b[i]!=0){
			a[k]=i;
			k++;
		}
	}
	cout << k;
	if(k<3){
		cout << 0;
		return 0;
	}else{
		for(int i=1; i<=n; i++){
			for(int j=2; j<=n; j++){
				for(int l=3; l<=n; l++){
					num=a[i]+a[j]+a[l];
					if(num>2*a[l]){
						ans++;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
