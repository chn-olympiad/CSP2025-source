#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	priority_queue<pair<int,int>>x;
}a[100004];
bool cmp(node a,node b){
	return a.x.top().first>b.x.top().first;
}
int b[4]={},ans,n;
void solve(){
	memset(b,0,sizeof(b));
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;a[i].x.push({x,0});
		cin>>x;a[i].x.push({x,1});
		cin>>x;a[i].x.push({x,2});
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		while(!a[i].x.empty()){
			int u=a[i].x.top().first;
			int v=a[i].x.top().second;
			a[i].x.pop();
			if(b[v]>=n/2) continue;
			b[v]++;
			ans=ans+u;
			break;
		}
		while(!a[i].x.empty()){
			a[i].x.pop();
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	
}
