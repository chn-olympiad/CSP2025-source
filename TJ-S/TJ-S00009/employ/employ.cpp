#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
long long mod=998244353;
long long sum=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		sum*=i;
		sum%=mod;
	}
	cout<<sum<<endl;
	return 0;
}


