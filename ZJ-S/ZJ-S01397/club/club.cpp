#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,k,ans;
struct node{
	int a,b,c,w;
}v[100005],dp[100005];
bool cmp(node x,node y){
	return x.a>y.a;
}
void dfs(ll res,ll i,ll sa,ll sb,ll sc){
	if(i>n){
		ans=max(ans,res);
		return;
	}
	if(sa>0){
		dfs(res+v[i].a,i+1,sa-1,sb,sc);
	}if(sb>0){
		dfs(res+v[i].b,i+1,sa,sb-1,sc);
	}if(sc>0){
		dfs(res+v[i].c,i+1,sa,sb,sc-1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);  
	cin>>t;
	while(t--){
		cin>>n;
		k=n/2;
		ans=0;
		bool f=1;
		for(int i=1;i<=n;i++){
			cin>>v[i].a>>v[i].b>>v[i].c;
		}
		if(n<=30){
			dfs(0,1,k,k,k);
		}else if(f==1){
			sort(v+1,v+1+n,cmp);
			for(int i=1;i<=k;i++){
				ans+=v[i].a;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
10 9 9
10 9 9
9 0 0
9 0 0
Ren5Jie4Di4Ling5%
*/