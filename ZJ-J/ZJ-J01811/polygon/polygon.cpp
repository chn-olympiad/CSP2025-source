#include<bits/stdc++.h>
using namespace std;
int a[5005],cnt,x,y,n,m,b;
int suml;
int MOD=998244353;
void dfs(int deep,int maxx,int sum,int no){
	if(suml<=maxx*2)
		return;
	if(deep>3&&sum>maxx*2){
		cnt++;
		cnt%=MOD;
	}
	for(int i=no+1;i<=min(n,n-3+deep);i++){
		dfs(deep+1,max(maxx,a[i]),sum+a[i],i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		suml+=a[i];
	}
	dfs(1,0,0,0);
	cout<<cnt;
	return 0;
}
