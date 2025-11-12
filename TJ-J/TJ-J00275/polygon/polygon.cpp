#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[5005];
long long dfs(int k){
	if(k==3)return 1;
	int sum=0;
	for(int i=1;i<k-1;i++){
		sum+=i;
	}
	return dfs(k-1)*2+sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	int sum=0,maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==3){
		if(sum>maxn*2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(maxn==1){
		cout<<dfs(n)%998244353;
		return 0;
	}
	
	return 0;
} 
