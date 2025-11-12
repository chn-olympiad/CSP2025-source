#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node{
	ll u,v,w;
};
ll t,n,cnt,m,f,F,ss;
node a[N],b[N];
//struct _{
//	ll l,l1,l2,l3;
//};

void dfs(ll _,ll x,ll y,ll z,ll ans){
	if(_==n+1){
		cnt=max(cnt,ans);
		//cout<<cnt<<" "<<x<<" "<<y<<" "<<z<<endl;
		return ;
	}if(x+1<=m){
		dfs(_+1,x+1,y,z,ans+a[_].u);
	}if(y+1<=m){
		dfs(_+1,x,y+1,z,ans+a[_].v);
	}if(z+1<=m){
		dfs(_+1,x,y,z+1,ans+a[_].w);
	}return ;
}
bool cmp(node q,node o){
	if(q.v!=o.v) return q.u>o.u;
	else return q.v>o.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	while(t--){
		cnt=0;
		f=0;F=0;
		//_ dp[N][4];
		//memset(dp,0,sizeof(dp));
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].u>>a[i].v>>a[i].w;
			if(a[i].v||a[i].w) f=1;
			if(a[i].w) F=1;
		}
		if(n<=30){
			dfs(1,0,0,0,0);
			cout<<cnt<<endl;
			continue;
		}if(!f){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++) cnt+=a[i].u;
			cout<<cnt<<endl;
			continue;
		}if(!F){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++) cnt+=a[i].u;
			cout<<cnt<<endl;
		}
		ll mx1=0,mx2=0,mx3=0,pp;
		for(int i=1;i<=n;i++){
			if(a[i].u) mx1++,pp=a[i].u;
		}for(int i=1;i<=n;i++){
			if(a[i].v) mx2++;
		}for(int i=1;i<=n;i++){
			if(a[i].w) mx3++;
		}cout<<(min(n/2,mx1)+min(n/2,mx2)+min(n/2,mx3))*pp<<endl;
		
		//ll m=n/2;
		//for(int i=1;i<=n;i++){
		//	ll A=0,B=0,C=0;
		//	if(dp[i-1][1].l1+1<=m) A=a[i].x;
		//	if(dp[i-1][2].l2+1<=m) B=a[i].y;
		//	if(dp[i-1][3].l3+1<=m) C=a[i].z;
			//ll ss=max{dp[i-1][1].l,dp[i-2][1].l,dp[i-1][3].l};
			//if(!A&&ss){
				
			//}
		//}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
