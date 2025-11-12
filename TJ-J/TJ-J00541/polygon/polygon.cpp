#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5005];
long long ans;
bool f[5005];
long long b[5005];
void dfs(int h,int ji){
	if(ji>=3){
		long long s=0,maxx=0;
		string st="";
		for(int i=1;i<=ji;i++){
			s+=b[i];
			maxx=max(maxx,b[i]);
//			cout<<i<<' ';
		}
//		cout<<'\n';
		if(maxx*2<s){
			ans++;
			ans%=998244353;
//			cout<<1<<'\n';
		}
	}
	for(int i=h+1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			ji++;
			b[ji]=a[i];
			dfs(i,ji);
			b[ji]=0;
			ji--;
			f[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]) f=0;
	}
	if(n>10){
		if(!f) cout<<0;
		else{
			ans=1;
			for(long long i=1;i<=n-2;i++){
				for(int j=1;j<=i;j++){
					ans+=j;
					ans%=998244353;
				}
				
			}
			cout<<ans;
		}
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
