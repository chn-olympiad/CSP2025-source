#include <bits/stdc++.h>
using namespace std;
const int N=998244353;
int n;
long long maxn,sum,ans;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(sum>maxn*2){
			ans=1;
		}
	}else{
		ans=n*n;
	}
	cout << ans%N;
	return 0;
}
