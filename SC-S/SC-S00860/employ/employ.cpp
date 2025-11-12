#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}