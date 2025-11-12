#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans;
	ans++;
	ans%=1234;
	cout<<ans+a[0]-a[1]-a[2]+a[3]+a[34];
	fclose(stdin);
	fclose(stdout);
}
