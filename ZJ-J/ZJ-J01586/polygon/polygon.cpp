#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	long long ans = 0;
	for(int i = 1;i<=n-2;i++){
		for(int j = i+1;j<=n-1;j++){
			for(int k = j+1;k<=n;k++){
				int sum = a[i]+a[j]+a[k];
				if(2*max(a[i],max(a[j],a[k]))<sum){
					ans=(ans+1)%998244353;
				}
			}
		}
	}
	for(int i = 1;i<=n-3;i++){
		for(int j = i+1;j<=n-2;j++){
			for(int k = j+1;k<=n-1;k++){
				for(int p = k+1;p<=n;p++){
					int sum = a[i]+a[j]+a[k]+a[p];
					if(2*max(max(a[i],a[p]),max(a[j],a[k]))<sum){
						ans=(ans+1)%998244353;
					}
				}
			}
		}
	}
	for(int i = 1;i<=n-4;i++){
		for(int j = i+1;j<=n-3;j++){
			for(int k = j+1;k<=n-2;k++){
				for(int p = k+1;p<=n-1;p++){
					for(int q = p+1;q<=n;q++){
						int sum = a[i]+a[j]+a[k]+a[p]+a[q];
						if(2*max(max(a[i],a[p]),max(a[q],max(a[j],a[k])))<sum){
							ans=(ans+1)%998244353;
						}
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}