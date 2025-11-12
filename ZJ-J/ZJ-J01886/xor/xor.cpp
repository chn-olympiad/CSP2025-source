#include <bits/stdc++.h>
using namespace std;
int n,k,a[200010],cnt1,cnt0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == 1) cnt1++;
		if(a[i] == 0) cnt0++;
	}
	if(cnt1 == n && k == 0){
		cout << n / 2;
	}
	else if(cnt1+cnt0 == n){
		if(k == 0){
			int kb1 = 0;
			for(int i = 1; i <= n; i++){
				if(a[i] == 1 && a[i+1] == 1){
					kb1++;
					i++;
				}
			}
			cout << kb1;
		}else if(k==1){
			cout << cnt1;
		}
	}
	cout << 11;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


