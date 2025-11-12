#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;

int n,a[5006];
ll ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polgon.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n==3){
		sort(a+1,a+4);
		a[1]+a[2]+a[3]>a[3]*2;
		cout << 1;
	}
	cout << n*(n-1)/2;
}

