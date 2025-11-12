#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
set<string>set;
void dfs(int num,int mx,int i,int z,int cnt){
	if(cnt>=3 && num>=mx*2 && z==1)ans++;
	if(i>n)return;
	dfs(num+a[i],max(mx,a[i]),i+1,1,cnt+1);
	dfs(num,mx,i+1,0,cnt);
	return;
}
int main(){
//  freopen("polygon.in","r",stdin);
//  freopen("polygon.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  dfs(0,0,1,0,0);
	cout<<ans;
  return 0;
}
