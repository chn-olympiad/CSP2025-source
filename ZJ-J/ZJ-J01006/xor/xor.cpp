#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
int fa = 1,fb = 1;
ll a[500010];
int vis[500010];
int v[500010];
ll sum = 0;
void dfs(int x,ll ex,ll ans){
//	cout<<ex<<endl;
	if(x == n+1){
		sum = max(ans,sum);
		
//		cout<<"ans : "<<ans<<" sum : "<<sum<<endl;
		ans = 0;
		return ;
	}
	if(a[x] == k){
//		cout<<"x : "<<x<<" ans : "<<ans+1<<endl;
		dfs(x+1,-1,ans+1);
	}else{
		dfs(x+1,-1,ans);
		ll p = ex;
		if(p < 0)	p = 0;
		if((p^a[x]) == k){
//			cout<<"x : "<<x<<" ans : "<<ans+1<<endl;
			dfs(x+1,-1,ans+1);
		}else dfs(x+1,p^a[x],ans);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] != 1)	fa = 0;
		if(a[i] != 0 && a[i] != 1)	fb = 0;
	}
	if(fa && k == 0){
		cout<<n/2<<endl;
		return 0;
	}else if(fb && (k == 0 || k == 1)){
		if(k == 0){
			ll sum = 0;
			for(int i = 1;i <= n;i++){
				if(a[i] == 0)	sum++;
				else if(a[i-1] == 1 && vis[i-1] == 0){
					sum++;
					vis[i] = vis[i-1] = 1;
				}	
			}
			cout<<sum<<endl;
			return 0;
		}
		else{
			ll sum = 0;
			for(int i = 1;i <= n;i++){
				if(a[i] == 1)	sum++;
			}
			cout<<sum<<endl;
			return 0;
		}
	}
	dfs(1,0,0);
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

