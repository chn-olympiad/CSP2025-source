#include<bits/stdc++.h>
using namespace std;
int n,a[5010],b[5010],cnt=0;
long long ans=0;
void dfs(int l,int i){
	if(l==0||i==n+1) return;
	b[++cnt]=a[i];
	dfs(l-1,i+1);
	cnt--;
	dfs(l,i+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int l=3;l<=n;l++){
		cnt=0;
		memset(b,0,sizeof b);
		dfs(l,1);
		int sum=0;
		int ma=-1e9;
		for(int i=1;i<=l;i++){
			ma=max(ma,b[i]);
			sum+=b[i];
		}
		if(sum>ma*2) ans++;
	}
	cout<<ans;
	return 0;
}