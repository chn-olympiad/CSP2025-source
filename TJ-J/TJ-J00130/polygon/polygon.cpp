#include<bits/stdc++.h>
using namespace std;
int n,a[50005],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if (n == 3){
		if (a[1]+a[2]+a[3] > max(a[1],max(a[2],a[3]))*2){
			cout << 1;
		}
		else cout << 0;
	}
}
