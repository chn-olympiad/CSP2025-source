#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1005],t,k;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,[&](int c,int b){
		return c>b;
	});
//	for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			t=i;
			break;
		}
	}
	cout<<(t-1)/n+1<<" ";
	if(((t-1)/n+1)%2) cout<<(t-1)%n+1;
	else cout<<n-(t-1)%n;
	return 0;
}
