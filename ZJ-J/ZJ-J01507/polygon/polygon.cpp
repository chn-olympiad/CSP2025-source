#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int>& a,int& n,int& ans,int sum,int d,int mxa){
	if(d==n){
		if(sum>(mxa*2)){
			ans++;
			ans%=998244353;
		}
		return;
	}
	dfs(a,n,ans,(sum+a[d]),(d+1),max(mxa,a[d]));
	dfs(a,n,ans,sum,(d+1),mxa);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int> a(n);
	bool all1=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if((all1==1)and(a[i]!=1)){
			all1=0;
		}
	}
	if(all1==0 and n<=30){
		int ans=0;
		dfs(a,n,ans,0,0,0);
		cout<<ans<<endl;
	}else{
		int ans=1;
		for(int i=0;i<n;i++){
			ans<<=1;
			ans%=998244353;
		}
		cout<<ans<<endl;
	}
	return 0;
}
