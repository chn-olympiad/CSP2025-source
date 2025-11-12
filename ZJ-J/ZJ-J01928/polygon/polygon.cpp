#include<bits/stdc++.h>
using namespace std;
int n,a[510],vis[510],qwe,f=0;
long long c;
int jc(int a){
	int s=a;
	while(a-->1){
		s*=a;
	}
	return s?s:1;
}
void dfs(int s,int mx,int k,int t,int N){
	if(k>=N){
		if(s>2*mx){
			c=(c+1)%998244353;
		}
		return;
	}
	for(int i=t+1;i<n;i++){
		if(vis[i]==0){
			s+=a[i];
			mx=max(mx,a[i]);
			vis[i]=1;
			k++;
			dfs(s,mx,k,i,N);
			k--;
			s-=a[i];
			vis[i]=0;
		}
	}
}
void ok(){
	for(int i=3;i<=n;i++){
		int s=jc(n)/jc(i)/jc(n-i);
		c=(c+s)%998244353;
	}
	cout<<c;
	exit(0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	if(f==0) ok();
	for(int i=3;i<=n;i++){
		dfs(0,0,0,-1,i);
	}
	cout<<c;
	return 0;
}
