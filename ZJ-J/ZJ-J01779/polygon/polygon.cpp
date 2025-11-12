#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int MOD=998244353;
int n;
int a[5010];
struct node{
	int num;
	int start;
}vis[5010][5010];
int dfs(int mx,int s,int st,int f){
	if(s==n){
		return 0;
	}
	if(vis[mx][f].num and s==vis[mx][f].start and st>=3) return vis[mx][f].num;
	int sum=0;
	for(int i=s+1;i<=n;i++){
		sum+=dfs(a[i],i,st+1,f+a[i]);
		if(f>a[i] and st>=2) sum++;
		sum%=MOD;
	}
	vis[mx][f].num=sum;
	vis[mx][f].start=s;
	return sum;
}
int ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n-2;i++) ans+=dfs(a[i],i,1,a[i]);
	cout<<ans;
	return 0;
}
