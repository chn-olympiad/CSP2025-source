#include<bits/stdc++.h>
using namespace std;
long long a[1000],b[1000],c[1000],f[1000],n,m,t,sum,maxn;
bool flag=1;
char temp;
bool check(){
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]||sum>=b[c[i]]) sum++;
	}
	return sum<=n-m;
}
long long A(long long n){
	long long sum=1;
	for(int i=1;i<=n;i++) sum=sum*i%998244353;
	return sum;
}
void dfs(long long x){
	if(x>n){
		if(check()) sum=(sum+1)%998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			c[i]=x,f[i]=1;
			dfs(x+1);
			c[i]=f[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>temp;
		a[i]=(temp<'1'),maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(!b[i]) t++,flag=0;
	}
	if(n-t<m) cout<<0;
	else if(flag&&!maxn) cout<<A(n);
	else{
		dfs(1);
		cout<<sum;
	}
	return 0;
}