//DuanChencheng's code
//number:SN-J00677
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int n,a[100005],ans;
vector<int> ch;
void check(){
	int sum=0,maxx=0;
	for(int x:ch){
		sum+=a[x];
		maxx=max(maxx,a[x]);
	}
	if(sum>2*maxx) ans++;
}
void dfs(int now){
	if(now==n+1){
		check();
		return ;
	} 
	dfs(now+1);
	ch.push_back(now);
	dfs(now+1);
	ch.pop_back();
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
