#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],maxx=0,sum=0;
bool vis[5005];
int A(int a,int b){
	int res=1;
	for(int i=1;i<=a;i++){
		res*=max(long(b-i),long(0));
	}
	return res;
}
int C(int a,int b){
	return A(a,b)/A(a,a);
}

signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	if(n<=3) {
		if(n<3){
			cout<<0;
			return 0;
		}
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			sum+=a[i];
		}
		for(int i=1; i<=n; i++) {
			if(sum<=a[i]*2) {
				cout<<0;
				return 0;
			}
		}
		cout<<1;
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	if(flag){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=C(i,n);
		}
		cout<<ans;
		return 0;
	}
	cout<<1;
	return 0;
}

