#include <bits/stdc++.h>
using namespace std;
int a[50001];
int main(){
	//ÌØÊâÐÔÖÊA
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int ans = 0;
	cin >>n>>k;
	int flag = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1){
			flag = 1;
		}
	} 

	if(flag == 0){
		ans += floor(n / 2); 
		
	}
	else if(k == 0){
		for(int i = 2; i <= n; i += 2){
			if(a[i] == a[i - 1]){
				ans++;
			}
		}
	}
	else if(k == 1){
		for(int i = 2; i <= n; i += 2){
			if(a[i] != a[i - 1]){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
