#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,x[501];
	cin>>n>>m;
	string a;
	cin>>a;
	long long sum=1;
	for(int i=n;i>=1;i--){
		sum=(sum*i)%998244353;
	}cout<<sum;
	return 0;
}
