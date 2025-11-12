#include <bits/stdc++.h>
using namespace std;

int a[100005][3],t,n,ans,tmp,cnt[4];
bool c[]={0,0,0,0},p[100005]={0};

void dfs(int x) {
	if(x==n+1) {
		ans=ans>tmp? ans:tmp;
		return;
	}
	for(int i=1;i<=n;i++) {
		if(p[i]==0) {
			for(int j=1;j<=3;j++) {
				if(c[j]==0) {
					p[i]=1;
					cnt[j]++;
					tmp+=a[i][j];
					if(cnt[j]==n/2) c[j]=1;
					dfs(x+1);
					tmp-=a[i][j];
					cnt[j]--;
					c[j]=0;p[i]=0;
				}
			}
		}
	}
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t) {
		t--;
		ans=0;tmp=0;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=3;j++) {
				scanf("%d",&a[i][j]);
			}
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	
	return 0;
}
