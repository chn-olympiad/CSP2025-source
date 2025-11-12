#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+100;
int n,a[N],b[N],c[N],ans,cnt[N];
struct node{
	int x,y,z,id;
	bool operator>(node o)const{
		if(x==o.x){
			if(y==o.y) return z>o.z;
			return y>o.y;
		}
		return x>o.x;
	}
};
void dfs(int s,int x,int y,int z,int sum){
	if(x>n/2) return ;
	if(y>n/2) return ;
	if(z>n/2) return ;
	if((ans-sum)>cnt[s]) return ;
	if(s==n+1) {
		ans=max(ans,sum);
		return ;
	}
	dfs(s+1,x+1,y,z,sum+a[s]);
	dfs(s+1,x,y+1,z,sum+b[s]);
	dfs(s+1,x,y,z+1,sum+c[s]);
}
priority_queue<node,vector<node>,greater<node>> q1,q2,q3;
void solve(){
	ans=0;
	cin>>n;
	bool f0=0,f1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]!=0||c[i]!=0) f0=1;
		if(c[i]!=0) f1=1;
	}
	if(!f0){
		sort(a+1,a+1+n,greater<int>());
		for(int i=1;i<n/2;i++) ans+=a[i];
		cout<<ans<<"\n";return ;
	}
	for(int i=n;i>=1;i--){
		cnt[i]=cnt[i+1]+max(a[i],max(b[i],c[i]));
	}
	if(n<=30){
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++){
		int mx=max(a[i],max(b[i],c[i]));
		if(mx==a[i]) q1.push({a[i],b[i],c[i],i});
		else if(mx==b[i]) q2.push({b[i],c[i],a[i],i});
		else q3.push({c[i],a[i],b[i],i});
	}
	if(q2.size()>q1.size()) swap(q2,q1);
	if(q3.size()>q1.size()) swap(q3,q1);
	if(q3.size()>q2.size()) swap(q3,q2);
	while(q1.size()>n/2){
		int o=q1.top().id;q1.pop();
		int o2=q1.top().id;q1.pop();
		int mx1=max(b[o],c[o]);
		int mx2=max(b[o2],c[o2]);
		if(mx1+a[o2]>a[o]+mx2){//rang o2 huiqu
			q1.push({a[o2],b[o2],c[o2],o2});
			if(mx1==b[o]) q2.push({b[o],c[o],a[o]});
			else q3.push({c[o],a[o],b[o],o});
		}
		else{//rang o huiqu
			q1.push({a[o],b[o],c[o],o});
			if(mx2==b[o2]) q2.push({b[o2],c[o2],a[o2]});
			else q3.push({c[o2],a[o2],b[o2],o2});
		}
	}
	while(q2.size()>n/2){
		int o=q2.top().id;q2.pop();
		int o2=q2.top().id;q2.pop();
		if(c[o]+b[o2]>b[o]+c[o2]){//rang o2 huiqu
			q1.push({b[o2],c[o2],a[o2],o2});
			q3.push({c[o],a[o],b[o],o});
		}
		else{//rang o huiqu
			q1.push({b[o],c[o],a[o],o});
			q3.push({c[o2],a[o2],b[o2],o2});
		}
	}
	while(!q1.empty()){
		node o=q1.top();q1.pop();
		ans+=o.x;
	}
	while(!q2.empty()){
		node o=q2.top();q2.pop();
		ans+=o.x;
	}
	while(!q3.empty()){
		node o=q3.top();q3.pop();
		ans+=o.x;
	}
	cout<<ans<<"\n";
}
int32_t main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		solve();
	}
}