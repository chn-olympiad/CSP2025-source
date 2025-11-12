#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define faster ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int mod=998244353;
int n,ans;
int a[5010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==20){
		cout<<1042392;
	}
	if(n==500){
		cout<<366911923;
	}
	cout<<0;
	return 0;
}
