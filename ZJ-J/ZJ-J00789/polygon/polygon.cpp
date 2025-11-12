#include <bits/stdc++.h>
using namespace std;
int n,a[5050],ans=0;
void dfs(int i,int s,int m) {
	if(i>=3&&s+a[i]>2*max(m,a[i])) {
		ans++;
		ans%=998244353;
	}
	s+=a[i];
	m=max(m,a[i]);
	for(int j=i+1;j<=n;j++) {
		dfs(j,s,m);
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	return 0;
}
/*
5
2 2 3 8 10

5
1 2 3 4 5
*/