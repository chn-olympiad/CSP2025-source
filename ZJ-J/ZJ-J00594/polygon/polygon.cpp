#include<bits/stdc++.h>
using namespace std;
int n;
int a[25],ans;
void dfs(int k,int num,int maxn,int sum){
	if(3<=num&&(sum>2*(maxn))) ans++;
	if(num==n||k==n) return ;
	for(int i=k+1;i<=n;i++)
		dfs(i,num+1,max(a[i],maxn),sum+a[i]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		dfs(i,1,a[i],a[i]);
	cout<<ans;
	return 0;
}