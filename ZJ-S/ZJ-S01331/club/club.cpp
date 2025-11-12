#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll T,n;
struct node{
	ll id,x,y,z;
}a[N],b[N];
bool vis[N];
multiset<pair<ll,ll> > s,s1,s2;
bool cmp1(node a,node b){
	return a.y>b.y;
}
bool cmp2(node a,node b){
	return a.z>b.z;
}
int main(){
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;s.clear();s1.clear();s2.clear();
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].id=i;vis[i]=0;
			b[i]=a[i];
		}
		ll res=0;
		for(int i=1;i<=n;i++) res+=a[i].x,a[i].y-=a[i].x;
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n/2;i++){
			ll t=a[i].id;
			s1.insert({b[t].x-b[t].y,t});
			vis[t]=1;
			a[i].x+=a[i].y;
			res+=a[i].y;
//			cout<<t<<" ";
		}
//		for(int i=1;i<=n;i++) cout<<vis[i]<<" ";cout<<"\n";
		//先一半1部门    一半2部门
		//再插入3部门判断是否可以换1或2并检查替换为1后1能否再去替换2
		for(int i=n/2+1;i<=n;i++){
			ll t=a[i].id;
			s2.insert({b[t].y-b[t].x,t});
		}
		for(int i=1;i<=n;i++) a[i].z-=a[i].x;
		for(int i=1;i<=n;i++) s.insert({a[i].z,a[i].id});
		ll ans=res,tmp=0;
		while(tmp<n/2 && s.size()){
			
//			for(int i=1;i<=n;i++) cout<<vis[i]<<" ";cout<<"\n";
			auto it=--s.end();
			if(it->first<0) break;
			s.erase(it);
			tmp++;ll t=it->second;
			res+=it->first;
			if(vis[t]==0){//t是部门1 
//				for(auto i:s2) cout<<i.first<<" "<<i.second<<"\n";cout<<"\n";
//				for(auto i:s) cout<<i.first<<" "<<i.second<<"\n";cout<<"\n";
//				cout<<b[t].y-b[t].x<<" "<<t<<"\n\n\n";
				s2.erase(s2.find({b[t].y-b[t].x,t}));
//				for(auto i:s2) cout<<i.first<<" "<<i.second<<"\n";cout<<"\n";
				auto zw=--s1.end();
				t=zw->second;
				if(zw->first>0){
					res+=zw->first;
					vis[t]=0;
					s.erase(s.find({b[t].z-b[t].y,t}));
					s.insert({b[t].z-b[t].x,t});
					s2.insert({b[t].y-b[t].x,t});
					s1.erase(zw);
				}
				
			}else{//t是部门2 
//				cout<<t<<" ";
//				cout<<1;
//				for(auto i:s1) cout<<i.first<<" "<<i.second<<"\n";cout<<"\n";
//				for(auto i:s) cout<<i.first<<" "<<i.second<<"\n";cout<<"\n";
//				cout<<b[t].y-b[t].x<<" "<<t<<"\n";
				s1.erase(s1.find({b[t].x-b[t].y,t}));
//				cout<<2;
				auto zw=--s2.end();
				t=zw->second;
				if(zw->first>0){
					res+=zw->first;
					vis[t]=1;
					s.erase(s.find({b[t].z-b[t].x,t}));
					s.insert({b[t].z-b[t].y,t});
					s1.insert({b[t].x-b[t].y,t});
					s2.erase(zw);
				}
//				cout<<vis[9];
			}
			ans=max(ans,res);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
