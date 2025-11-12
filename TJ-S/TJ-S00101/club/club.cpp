#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll a,b,c;
};
int n,t;
ll ans;
node A[int(1e5+10)];
void dfs(int k,ll sum,int a,int b,int c){
	if (a>n/2){
		return ;
	}if (b>n/2){
		return ;
	}if (c>n/2){
		return ;
	}
	if (k>n){
		ans=max(ans,sum);
		return ;
	}
	
	dfs(k+1,sum+A[k].a,a+1,b,c);
	dfs(k+1,sum+A[k].b,a,b+1,c);
	dfs(k+1,sum+A[k].c,a,b,c+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for (int i=1;i<=n;i++){
			cin>>A[i].a>>A[i].b>>A[i].c;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
