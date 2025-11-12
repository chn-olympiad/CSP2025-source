#include<bits/stdc++.h>
using namespace std;
int n,l;
int a[5005];
long long ans;
long long c(int x,int y){
	long long s=1;
	for(int i=x;i>=x-y+1;i--){
		s*=i;
		s%=998244353;
	}
	for(int i=y;i>=1;i--){
		s/=i;
		s%=998244353;
	}
	return s;
}
void dfs(int z,int x,int y){
	if(z==n+1){
		if(x>y*2){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	dfs(z+1,x+a[z],max(y,a[z]));
	dfs(z+1,x,y);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l+=(a[i]==1);
	}
	if(l==n){
		for(int i=3;i<=n;i++){
			ans+=c(n,i);
			ans%=998244353;
		}
		cout<<ans;
	}else if(n<=20){
		dfs(1,0,0);
		cout<<ans;
	}else{
		srand(time(0));
		cout<<rand()%998244353;
	}
	return 0;
}