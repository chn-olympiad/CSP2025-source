#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[110];
int main() {
	cin>>n>>k;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(int i=1;i<=n;i++) {
		ans+=i;
	}
	cout<<ans;
	return 0;
}
