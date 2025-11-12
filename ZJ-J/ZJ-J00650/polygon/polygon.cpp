#include<bits/stdc++.h>
using namespace std;
int n,isok=1;
int a[500005];
long long ans=0;
bool cmp(int c,int d){
	return c>d;
}
int mx=0;
void dfs(int q,int sum){
	if(q>n){
		if(sum>mx){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	for(int i=q;i<=n+1;i++){
		dfs(i+1,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) isok=0;
	}
	if(isok){
		for(int i=3;i<=n;i++){
			long long jans=1;
			for(int j=(i+1);j<=n;j++){
				jans*=j;
				jans%=998244353;
			}
			ans+=jans;
			ans%=998244353;
		}
		cout<<ans;
	}
	else{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n-2;i++){
			mx=a[i];
			dfs(i+1,0);
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

