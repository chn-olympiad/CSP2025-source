#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
long long a[N],n,ans,sum[N],s,p;
long long c(int n ,int m){
	long long a=1;
	if(n>m)return 0;
	if(n>m/2)n=m-n;
	for(int i=1;i<=n;i++){
		a=a*(m-i+1);
		a=a/i;
		a=a%998244353;
	}return a;
}
void dfs(int x,int z,int h){
	if(z>p-3||s-h<=a[p]){
		return;
	}
	ans++;
	ans=ans%998244353; 
	for(int i=x+1;i<=p;i++){
		dfs(i,z+1,h+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[a[i]]++;
	}sort(a+1,a+n+1);
	if(a[n]==1){
		for(int i=3;i<=n;i++){
			ans=ans+c(i,n);
			ans=ans%998244353;
		}
	}else{
		s=a[1]+a[2];
		for(int i=3;i<=n;i++){
			if(s<=a[i]){
				s=s+a[i];
				continue;
			}
			if(i==3){
				ans++;
				s=s+a[i];
				continue;
			}
			ans++;
			p=i;
			for(int j=1;j<=p;j++)dfs(j,1,a[j]);
			s=s+a[i];
		}
	}
	cout<<ans%998244353;
	return 0; 
} 
