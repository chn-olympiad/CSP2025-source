#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
int a[6000];
void dfs(long long sm,long long mx,int id,int k){
	ans%=998244353;
	if(id>n) return ;
	else{
		dfs(sm,mx,id+1,k);
		if(k+1>=3){
			if(a[id]>mx){
				if(sm+a[id]>a[id]*2) ans++;
				dfs(sm+a[id],a[id],id+1,k+1);
			}
			else{
				if(sm+a[id]>mx*2) ans++;
				dfs(sm+a[id],mx,id+1,k+1);
			}		
		}
		else{
			if(a[id]>mx) dfs(sm+a[id],a[id],id+1,k+1);
			else dfs(sm+a[id],mx,id+1,k+1);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,1,0);
	cout<<ans<<endl;
	return 0;
}
