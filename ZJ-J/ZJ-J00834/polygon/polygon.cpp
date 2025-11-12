#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans;
	return 0;
}
