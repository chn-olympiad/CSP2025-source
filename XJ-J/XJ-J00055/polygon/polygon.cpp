#include <bits/stdc++.h>
using namespace std;
const int N=998244353;
int a[5090];
int main(){
	int n;
	long long ans=0;
	freopen("polygon.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
		ans++;
	}
	freopen("polygon.out","w",stdout);
	cout<<ans;
	return 0;
}
