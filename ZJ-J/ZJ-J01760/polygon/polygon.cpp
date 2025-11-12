#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void dfs(int x,int cnt,int maxn,int num){
	if(cnt>2*maxn&&num>=3)ans++;
	if(x>n)return;
	dfs(x+1,cnt,maxn,num);
	dfs(x+1,cnt+a[x],a[x],num+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans<<endl;
	return 0;	
}