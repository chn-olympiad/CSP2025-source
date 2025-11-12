#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >>n >>k;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(k==0){
		cout << 1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]+a[j]==k&&i!=j){
				cout << a[1];
				return 0;
			}
		}
	}
	return 0;
}
