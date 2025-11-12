#include<bits/stdc++.h>
using namespace std;
int n,k,s;
int a[100005],used[100005];
void dfs(int dep,int z){
	if(z==k){
		s++;
		//cout<<dep-1<<"**"<<'\n';
		z=a[dep];
		used[dep-1]=1;
	}
	if(dep>n){//used[dep]==1
		return;
	}
	//cout<<dep<<" "<<z<<'\n'<<'\n';
	if(a[dep]==k){
		s++;
		//cout<<dep<<" "<<z<<"**"<<'\n';	
		z=a[dep];
		used[dep]=1;
	}
	used[dep+1]=1;
	dfs(dep+1,z&a[dep+1]);
	dfs(dep+1,z|a[dep+1]);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,a[1]);
	cout<<s;

	return 0;
}

