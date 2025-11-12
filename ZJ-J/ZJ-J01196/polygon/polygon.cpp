#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int mod=998244353;
const int N=5050;
int n,a[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cin>>a[1]>>a[2]>>a[3];
	int x=max(a[1],max(a[2],a[3]));
	int y=a[1]+a[2]+a[3];
	if(y>x*2){
		cout<<1;	
	}else{
		cout<<0;
	}
	return 0;
}
