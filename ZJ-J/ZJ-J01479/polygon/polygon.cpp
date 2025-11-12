#include<bits/stdc++.h>
using namespace std;
long long s=0;
int n,a[5005]={};
int dfs(int sum,int k,int m,int t,int y){
	if (k>=3 and sum>m*2 and y==1) s+=1;
	if (t>n) return 0;
	dfs(sum+a[t],k+1,max(m,a[t]),t+1,1);
	dfs(sum,k,m,t+1,0);
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0,0,1,1);
	cout<<s%998244353;
	fclose(stdin);fclose(stdout);
	return 0;
}









