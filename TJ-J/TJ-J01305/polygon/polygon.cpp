#include <bits/stdc++.h>
using namespace std;
int n,li[10001],kl=0;
int dfs(int set,int cnt) {
	if (cnt>li[set]*2) {
		kl++;
	}
	for (int i=set+1;i<=n;i++) {
		dfs(i,cnt+li[i]);
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>li[i];
	}
	sort(li+1,li+n+1);
	dfs(0,0);
	cout<<kl%998244353<<endl;
	return 0;
}
