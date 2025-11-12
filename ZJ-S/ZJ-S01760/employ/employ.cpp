#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=505,mod=998244353;
int n,m,cnt,sum,a[MAXN],vis[MAXN],b[MAXN];
ll ans;
char c[MAXN];
void dfs(int p){
	if (p>n){
		cnt=sum=0;
		for(int i=1;i<=n;i++){
			if (cnt>=b[i]||c[i]=='0') cnt++;
			else sum++;
		}
		if (sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if (vis[i]==1) continue;
		vis[i]=1;
		b[p]=a[i];
		dfs(p+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf(" %c",&c[i]);
		if (c[i]=='1') cnt++;
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	if (cnt<m){cout<<0<<endl;return 0;}
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
