#include <iostream>
#include <algorithm>
using namespace std;
int n,a[5010],b[5010];
int ans=0;
void dfs(int sum,int mx,int l,int m){
	if(l>n) return;
	for(int i=l;i<=n;i++){
		if(sum>a[i]&&m>3){
			ans++;
			if(ans==998244353){
				ans=0;
			}
		}
		dfs(sum+a[i],a[i],i+1,m+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,0,1,0);
	cout<<ans;
	return 0;
}

