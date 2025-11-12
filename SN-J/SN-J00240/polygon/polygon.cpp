#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans=0;
bool x[5001];
void dfs(int step,int maxn,int cnt,int num){
	if(step>n)return;
	if((num+1>=3)&&(cnt+a[step])>(max(maxn,a[step])*2))ans++;
	dfs(step+1,max(maxn,a[step]),cnt+a[step],num+1);
	dfs(step+1,maxn,cnt,num);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];
	dfs(1,0,0,0);
	cout << ans;
	return 0;
}
