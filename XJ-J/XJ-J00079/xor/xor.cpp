#include<bits/stdc++.h>
using namespace std;
int n;
long long int a[50010],b[50010],cnt,k,ans;
bool mp[50010];
dfs(int l,int r,int ans){
	if(r>n||mp[r]==1||mp[l]==1){
	return 1;
	}
	if(ans==k){
		cnt++;
		ans=0;
		for(int i=l;i<=r;i++){
			mp[i]=1;
		}
		for(int i;i<=n;i++){
			b[i]=0;
		}
		return 1;
	}
	dfs(l,r+1,ans+=a[r+1]);
	dfs(l,r+1,ans-=a[r+1]);
	b[r]=1;
	if(b[l]==1)dfs(l+1,r,ans+a[l]);
	if(b[l]==0)dfs(l+1,r,ans-a[l]);
}
int main(){
	freopen("xor.in","r","stdin");
	freopen("xor.out","w","stdout");
	cin>>n;
	for(int i;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1,ans);
	cout<<cnt;
	return 0; 
}




