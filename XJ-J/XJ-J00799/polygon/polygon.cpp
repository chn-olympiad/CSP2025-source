#include<bits/stdc++.h>
using namespace std;
const int N=5555;
const int Mod=998244353;
int n,a[N],f[N],c[N];
//void dfs(int fd,int mx) {
//	if(fd>mx) {
//		for(int i=1;i<=mx;i++) cout<<c[i]<<" ";
//		cout<<"\n";return ;
//	} 
//	for(int i=1;i<=n;i++) {
//		if(f[i]==0) {
//			c[fd]=a[i];f[i]=114514;dfs(fd+1,mx);c[fd]=0;f[i]=0;
//		}
//	}
//}
int main() {
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3) {
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]) {cout<<1;return 0;}
		else {cout<<0;return 0;}
	}
//	for(int i=3;i<=n;i++) {
//		memset(c,0,sizeof c);memset(f,0,sizeof f);
//		dfs(1,i);
//	}
	return 0;
}
