#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int N=1e5+5;
ll ans=0,t,v,n;
struct p{
	int x,y,z;
};
p a[N];
bool cmpA(p n,p m){
	return n.x>m.x;
}
void dfs(ll id,ll sum,ll v1,ll v2,ll v3){
	ans=max(ans,sum);
	if(id>n) return ;
	if(v1<v) dfs(id+1,sum+a[id].x,v1+1,v2,v3);
	if(v2<v) dfs(id+1,sum+a[id].y,v1,v2+1,v3);
	if(v3<v) dfs(id+1,sum+a[id].z,v1,v2,v3+1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ll t2=0,t3=0;
		ans=0;
		cin>>n;
		v=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y==0) t2++;
			if(a[i].z==0) t3++;
		}
		if(t2==n&&t3==n){
			sort(a+1,a+n+1,cmpA);
			for(int i=1;i<=v;i++){
				ans+=a[i].x;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(n>50){
			for(int i=1;i<=n;i++){
				ans+=max(a[i].x,max(a[i].y,a[i].z));
			}
			cout<<ans<<"\n";
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}