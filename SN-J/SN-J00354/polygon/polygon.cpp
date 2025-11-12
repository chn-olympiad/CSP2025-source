#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=n;k++){
					if(i==j||i==k||j==k){
						continue;
					}
					if(a[i]+a[j]+a[k]>a[k*2]){
						cnt++;
					}
				}
			}
		}
		cout << cnt;
	}
	return 0;
}
