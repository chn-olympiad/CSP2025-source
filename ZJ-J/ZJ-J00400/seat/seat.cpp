#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1100;
ll n,m,a[N],g[N][N],cnt;
inline bool cmp(ll& x,ll& y){
	return x>y;
}
inline void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	ll fi=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1)
			for(int j=1;j<=n;j++) g[j][i]=a[++cnt];
		else
			for(int j=n;j>=1;j--) g[j][i]=a[++cnt];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(g[i][j]==fi){
				cout<<j<<' '<<i;
				break;
			}
	return ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
	return 0;
}
