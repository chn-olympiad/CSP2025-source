#include<bits/stdc++.h>
using namespace std;
long long shu,sum,n,a[100005],MOD=998244353,b[105][105][105];
void dfs(long long mx,long long st,long long num,long long shu);
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,1,0,0);
	cout<<sum;
	return 0;
}
void dfs(long long mx,long long st,long long num,long long shu){
	if(st==n+2)return ;
	if(shu>=3 && num>mx*2 && !b[num][mx][shu]){
		sum++;
		b[num][mx][shu]=1;
	}
	dfs(a[st],st+1,num+a[st],shu+1);
	dfs(mx,st+1,num,shu);
}