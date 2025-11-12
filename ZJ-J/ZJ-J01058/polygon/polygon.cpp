#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
int n,ans;
int a[N];
bool vis[N];
void dfs(int sum1,int sum2,int sum3,int sum4){
	if(sum1>=3&&sum2>sum3*2)++ans;
	if(sum1>n)return;
	for(int i=sum4;i<=n;++i){
		if(vis[i]==0){
			vis[i]=1;
			dfs(sum1+1,sum2+a[i],max(sum3,a[i]),i);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	dfs(0,0,0,1);
	cout<<ans;
	return 0;
}