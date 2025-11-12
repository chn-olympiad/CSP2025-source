#include<bits/stdc++.h>
using namespace std;
int n,num,amax,a[10010],b[10010];
void dfs(int ans,int fd,int ghf,int Max){
	if(ans==0){
		if(Max*2<ghf) num++;
		return;
	}
	for(int i=fd+1;i<=n-ans+1;i++) dfs(ans-1,i,ghf+a[i],max(Max,a[i]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		amax=max(amax,a[i]);
	} 
	for(int k=2;k<n;k++)
		for(int i=1;i<=n-k;i++) dfs(k,i,a[i],a[i]);
	num=num%998244353;
	cout<<num;
	return 0;
}
