#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5010],ans,mx[5010],l;
void dfs(int t,int now){
	for(int i=now+1;i<=n;i++){
		l+=a[i];
		mx[t]=max(mx[t-1],a[i]);
		if(l>mx[t]*2&&t>=3){
			ans++;
			ans%=mod;
		}
		if(t!=n)dfs(t+1,i);
		
		l-=a[i];
	}
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
