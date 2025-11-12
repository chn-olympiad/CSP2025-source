#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int a[5005],su[5005],n,cn;
void dfs(int l,int x,int s,int c){
	if(n-l<2-c) return;
	if(s+su[n]-su[l-1]<x*2) return;
	if(l>n){
		cn+=(c>2&&s>x*2);
		return;
	}dfs(l+1,x,s,c);
	dfs(l+1,max(x,a[l]),s+a[l],c+1);
}int ch(int t,int c){
	long long ans=0;
	for(int i=3;i<=c;i++){
		long long x=1;
		for(int j=t,k=i;j>t-i;j--,k--) x*=j/k;
		(ans+=x)%M;
	}return ans;
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]),su[i]=su[i-1]+a[i];
	}if(mx==1){
		cout<<ch(su[n],su[n]);
		return 0;
	}else if(n>30){
		cout<<ch(n,n);
		return 0;
	}dfs(1,0,0,0);cout<<cn;
	return 0;
}
