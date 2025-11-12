#include<bits/stdc++.h>
#define ll long long 
using namespace std;
struct bian{
	ll net,to,val;
	friend bool operator < (bian a,bian b){
		return  a.val>b.val;
	}
}tu;
struct d{
	ll fa;
	ll s;
}di[10004];
ll n,m,k,cnt=0,u,v,w,c,ans=0;
priority_queue<bian> f; 
void ffa(int t){
	if(di[t].fa==t){
		return;
	}else{
		ffa(di[t].fa);
		di[t].fa=di[di[t].fa].fa;
		di[t].s=di[di[t].fa].s;
	}
}
void find(int o){
	if(o==0){
		while(cnt<n&&!f.empty()){
			bian t=f.top();
			f.pop();
			ffa(t.net);ffa(t.to);
			if(di[t.net].fa!=di[t.to].fa){
				ans+=t.val;
				di[t.to].fa=di[t.net].fa;
				di[di[t.net].fa].s+=di[t.to].s;
				cnt=max(cnt,di[di[t.net].fa].s);
				di[t.to].s=di[di[t.net].fa].s;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k!=0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		di[i].fa=i;
		di[i].s=1;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		tu.net=u;
		tu.to=v;
		tu.val=w;
		f.push(tu);
	}
	find(0);
	cout<<ans;
	return 0;
}
