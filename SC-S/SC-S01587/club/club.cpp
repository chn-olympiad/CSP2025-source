#include<bits/stdc++.h>
using namespace std;
int n,t,a[(int)(1e5+10)],b[(int)(1e5+10)],ans,c[(int)(1e5+10)];
void dfs(int as,int  bs,int cs,int cl,int sum){
	if(cl==n+1){
		ans=max(ans,sum);
		return;
	}
	if(as<n/2)dfs(as+1,bs,cs,cl+1,sum+a[cl]);
	if(bs<n/2)dfs(as,bs+1,cs,cl+1,sum+b[cl]);
	if(cs<n/2)dfs(as,bs,cs+1,cl+1,sum+c[cl]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(0,0,0,1,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
} 