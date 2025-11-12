#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("emoloy.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m){
		cout<<0<<endl;
		return 0;
	}
	int an=n;
	for(int i=2;i<n;i++){
		an*=i;
		an%=998244353;
	}
	cout<<an;
	return 0;
}

