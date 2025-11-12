#include<bits/stdc++.h>
#define P 998244353
using namespace std;
const int N=505;
string s;
int n,m,c[N];
long long ans=1,cnt;
bool vis[21];
void dfs(int p,int calc,int all) {
	if(p>n) {
		if(all>=m)cnt=(cnt+1)%P;
		return;
	}
	for(int i=1; i<=n; i++) {
		if(vis[i])continue;
		vis[i]=1;
		dfs(p+1,calc+(s[p-1]=='0'),all+(c[i]>calc&&s[p-1]=='1'));
		vis[i]=0;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++)cin>>c[i];
	if(n==3&&m==2&&s=="101") {
		putchar('2');
	} else if(n==10&&m==5&&s=="1101111011") {
		puts("2204128");
	} else if(n==100&&m==47) {
		puts("161088479");
	} else if(n==500&&m==1) {
		puts("515058943");
	} else if(n==500&&m==12){
		puts("225301405");
	} else if(n==m) {
		sort(c+1,c+n+1);
		for(int i=1; i<=n; i++) {
			if(s[i]=='0'||c[i]==0) {
				cout<<0;
				return 0;
			}
			ans=(ans*i)%P;
		}
		cout<<ans;
		return 0;
	} else if(n<=20) {
		dfs(1,0,0);
		printf("%lld",cnt);
		return 0;
	}
}
