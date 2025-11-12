#include<bits/stdc++.h>
using namespace std;
//RP++
typedef long long ll;
ll t,n,v[114514],ans=0,a[4][114514],d[114514][4][2];
struct sth{
	ll i,s,x,y,z;
};
map<sth,ll> mp;
bool operator<(sth p,sth q){
	return 1;
}
ll dfs(ll i,ll sum,ll x,ll y,ll z){
	sth q;
	q.i=i;
	q.s=sum;
	q.x=x;
	q.y=y;
	q.z=z;
	if(mp[q]!=0) return mp[q];
	if(i==n){
		ll p[3]={(x!=n/2?sum+a[1][i]:0),(y!=n/2?sum+a[2][i]:0),(z!=n/2?sum+a[3][i]:0)};
		mp[q]=max(p[0],max(p[1],p[2]));
		return max(p[0],max(p[1],p[2]));
	}
	ll p[3]={(x!=n/2?dfs(i+1,sum+a[1][i],x+1,y,z):0),(y!=n/2?dfs(i+1,sum+a[2][i],x,y+1,z):0),(z!=n/2?dfs(i+1,sum+a[3][i],x,y,z+1):0)};
	mp[q]=max(p[0],max(p[1],p[2]));
	return max(p[0],max(p[1],p[2]));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		cout<<dfs(1,0,0,0,0)<<endl;
	}
	return 0;
} 