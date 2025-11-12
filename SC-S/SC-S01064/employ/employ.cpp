#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define ptc putchar
using namespace std;
const int N=512;
const int mod=998244353;
int n,m;
char c[N];
int a[N];
bool used[N];
int ans;
void dfs(int now,int cnt){
	if(cnt>n-m) return;
	if(now==n+1){
		++ans;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			used[i]=1;
			if(c[now]=='1') dfs(now+1,cnt+(cnt>=a[i]));
			else dfs(now+1,cnt+1);
			used[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",c+1);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	dfs(1,0);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}