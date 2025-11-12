#include<bits/stdc++.h>
using namespace std;
int n,m,x,t,cnt=1,ans;
int main() {
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%d",&x);
			if(i==1 && j==1) t=x;
			if(x>t) cnt++;
		}
	}
	while(cnt-n>0) {
		cnt-=n;
		ans++;
	}
	if(ans%2) {
		printf("%d %d",ans+1,n-cnt+1);
	} else {
		printf("%d %d",ans+1,cnt);
	}
	return 0;
}
