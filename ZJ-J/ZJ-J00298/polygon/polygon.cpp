#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int sum[5005] = {0};
long long ans = 0;
void dfs(int iid,int id,int r,int nsum,int upnum){
	if(nsum <= upnum || id >= r)return;
	if(iid >= 2)ans++;
	dfs(iid+1,id+1,r,nsum-a[id],upnum);
	dfs(iid,id+1,r,nsum,upnum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i-1]+a[i];
	}
	for(int i = n;i >= 3;i--){
		dfs(0,1,i,sum[i-1],a[i]);
	}
	cout<<ans;
	return 0;
}
