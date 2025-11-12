#include<bits/stdc++.h>
using namespace std;
long long t,n,maxx;
int a[100005][5];
void dfs(int now,int c1,int c2,int c3,long long sum){
	if(now>n){
		maxx=max(maxx,sum);
		return;
	}
	if(c1<(n/2)){
		dfs(now+1,c1+1,c2,c3,sum+a[now][1]);
	}
	if(c2<(n/2)){
		dfs(now+1,c1,c2+1,c3,sum+a[now][2]);
	}
	if(c3<(n/2)){
		dfs(now+1,c1,c2,c3+1,sum+a[now][3]);
	}
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		maxx=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				cin>>a[i][j];
			}
		}
		dfs(1,0,0,0,0);
		printf("%d\n",maxx);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
