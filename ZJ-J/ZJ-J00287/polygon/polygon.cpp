#include<bits/stdc++.h>
using namespace std;
long long n,a[5500],ans=0;
void dfs(int w,long long s,int end,int we){
	if(s>a[end]){
		ans++;
	}
	if(we>=end){
		return;
	}
	
	for(int i=w;i<end;i++){
		dfs(i+1,s+a[i],end,we+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(1,0,i,0);
	}
	cout<<ans%998244353;
	return 0;
}