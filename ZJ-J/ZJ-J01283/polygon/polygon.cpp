#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt;
void dfs(int x,int sum,int f,bool z,int cut) {
	if(sum>f*2&&!z&&cut>=3) {
		cnt++;
		cnt%=998244353;
		//cout<<sum<<' '<<f<<endl;
	}
	for(int i=x+1; i<=n; i++) {
		dfs(i,sum,f,1,cut);

		dfs(i,sum+a[i],a[i],0,cut+1);

	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n==3) {
		if(a[1]+a[2]+a[3]>2*a[3]) {
			cout<<1;

		} else cout<<0;
		return 0;
	}
	if(a[n]==1) {
		for(int i=3; i<=n; i++) {
			cnt+=(n-(i-1));
			cnt%=998244353;
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		dfs(i,a[i],a[i],0,1);
	}
	cout<<cnt;
	return 0;
}