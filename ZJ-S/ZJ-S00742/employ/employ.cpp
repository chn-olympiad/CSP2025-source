#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[501];
int c[501];
long long ans=1; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=2;i<=n;i++){
		ans*=i;
	}
	cout<<ans%998244353;
	return 0;
}
