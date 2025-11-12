#include<bits/stdc++.h>
using namespace std;
int n,k,s[500005],ans,dp[1005][1005],cnt,q;
struct f{
	int a,b;
}a[1000005];
bool cmp(f x,f y){
	return x.b<y.b;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i<=n;i++)cin>>s[i];
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			dp[i][j]=dp[i][j-1]^s[j];
			if (dp[i][j]==k){
				a[++cnt] = {i,j};
			}
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i = 1;i<=cnt;i++){
		if (a[i].a>q){
			ans++;
			q = a[i].b;
		}
	}
	cout<<ans;
	return 0;
}
