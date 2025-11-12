#include<bits/stdc++.h>
using namespace std;
const long long m=998244353;
long long as=0;	
long long a[6000];
int n;
int b[600];
void dfs(int k,int s,int h,int z){
	if(s>n)return;
	if(s>=3){
		if(h>2*b[s]){
			if(z==1)
			as++;
		}
		as%=m;
	}
	if(k==n+1)
	return;
	dfs(k+1,s,h,0);
	b[s+1]=a[k];
	dfs(k+1,s+1,h+a[k],1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]<=1){
		for(int i=3;i<=n;i++){
			long long ss=1;
			for(int j=n;j>=n-i+1;j--){
				ss*=j;
				ss%=m;
			}
			as+=ss;
			as%=m;
		}
		cout<<as;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<as;
	return 0;
}           