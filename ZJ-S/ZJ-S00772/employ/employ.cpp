#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
int n,m,a[N],c[N];
bool work(){
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(a[i]==0) cnt++;
		else if(cnt>=c[i]) cnt++;
	}
	if(cnt>(n-m)) return false;
	return true;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		char c;cin>>c;
		a[i]=c-'0';
	}
	for(int i=1;i<=n;++i) cin>>c[i];
	cout<<work();
	return 0;
}
