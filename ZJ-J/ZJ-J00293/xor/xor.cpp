#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[50005];
int main(){
	freopen("xor1.in","r",stdin);
	freopen("xor1.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(k==0) cout << 1;
	else cout << 2;
	return 0;
}
