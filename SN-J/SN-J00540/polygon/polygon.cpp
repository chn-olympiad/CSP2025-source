#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005],cnt,ans;
bool f[5005];
void dfs(int now){
	if(now>n){
		if(cnt>=3){
			int sum=0,maxx=0;
			for(int i=1;i<=n;i++){
				if(f[i]==true){
					sum+=a[i];
					maxx=max(maxx,a[i]);
				}
			}
			if(maxx*2<sum){
				ans++;
			}
		}
		return;
	}
	else{
		f[now]=true;
		cnt++;
		dfs(now+1);
		f[now]=false;
		cnt--;
		dfs(now+1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}

