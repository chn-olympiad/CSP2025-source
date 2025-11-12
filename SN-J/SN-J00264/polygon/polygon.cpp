#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[25],ans;
void dfs(int x,int gs,int ls,int mx,int f){
	if(x>n)return ;
	if(gs>=3&&ls>2*mx&&f==0)ans++;
	dfs(x+1,gs+1,ls+a[x+1],max(mx,a[x+1]),0);
	dfs(x+1,gs,ls,mx,1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,0,0,0);
	cout<<ans;
	return 0;
}

