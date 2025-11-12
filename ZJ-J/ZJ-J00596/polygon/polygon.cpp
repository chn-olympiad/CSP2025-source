#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mod=998244353;
int a[N],n,cnt;
void dfs(int x,int mx,int sum){
	if(x>n)return;
	if(x>=3&&sum+a[x]>2*mx)cnt++;
	dfs(x+1,max(mx,a[x]),sum+a[x]);
	dfs(x+1,mx,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];
	dfs(1,0,0);
	cout << cnt;
	return 0;
}
