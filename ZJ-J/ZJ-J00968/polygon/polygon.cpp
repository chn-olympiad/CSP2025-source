#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[21];
ll ans;
void dfs(int x,int l,ll s,int maxa){
	if(x>n)return;
	dfs(x+1,l,s,maxa);
	if(l>1&&s+a[x]>2*max(maxa,a[x]))ans++;
	dfs(x+1,l+1,s+a[x],max(maxa,a[x]));
}
int main(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}//sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans;
}

