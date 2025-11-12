#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,vis[501],c[501],tot,d[100001],ans;
char a[1000001];
void dfs(int res){
	if(res==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
//			printf("%d %d %d\n",d[i],c[d[i]],cnt);
			if(a[i]=='0'||c[d[i]]<=cnt){
				cnt++;
			}
		}
//		puts("");
		if(n-cnt>=m){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			d[++tot]=i;
			dfs(res+1);
			vis[i]=0;
			tot--;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("\n%s",a+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(n<=10){
		dfs(1);
	}
	printf("%d\n",ans);
	return 0;
}
