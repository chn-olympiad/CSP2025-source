#include <bits/stdc++.h> 
using namespace std;
int a[5005];
int b[5005];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		b[i]=a[i]+b[i-1];
	}
	for(int i = n;i >= 3;i--){
		int ida = a[i];
		int w = 0;
		for(int j = 1;j <= n;j++){
			if(b[j] > ida){
				w = j;
				break;
			}
		}
		ans+= i - w;
		ans%=998244353;
		for(int z = w;z <= i-1;z++){
			for(int j = 1;j <= z-2;j++){
				if(b[z]-a[j] > ida){
					ans++;
					ans%=998244353;
				}
				if(b[z] - b[j] > ida&&j > 1){
					ans++;
					ans%=998244353;
				}
			}
		}
	}
	cout << ++ans;
}
