#include"bits/stdc++.h"
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ","w",stdout);
	long long n,ans=1;
	cin>>n;
	for(int i=n;i>=1;i--){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
}
