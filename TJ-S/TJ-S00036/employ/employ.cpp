#include<bits/stdc++.h> 
using namespace std;
int n;
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	ans=n;
	while(n>1){
		n--;
		ans*=n;
		ans%=998244353;
	}
	cout<<ans;
	
	return 0;
}
