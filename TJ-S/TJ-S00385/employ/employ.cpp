#include<bits/stdc++.h>
using namespace std;
int a[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	long long j = n;
	for(long long i = 1;i<=n;i++){
		cin >> a[i];
		if(a[i]==0) j--;
	}
	int o = j;
	long long p = n-o;
	for(long long i = 1;i<=n;i++){
		if(a[i]!=0 && p>=a[i]){
			p++;
			j--;
		}
	}
	long long ans = 1;
	for(int i = 1;i<=j;i++){
		ans=ans*n%998244353;
	}
	cout << ans;
	return 0;
}
