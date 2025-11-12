#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[100005];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	long long sum=1;
	for(int i=1;i<=n;i++){
		sum=(sum*i)%998244353;
	}
	cout<<sum;
	return 0;
}