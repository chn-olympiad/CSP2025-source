#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5; 

struct node{
	int w[4];
	int mx,nxt;
	bool operator>(const node a)const{
		return (w[mx]-w[nxt])>(a.w[a.mx]-a.w[a.nxt]);
	}
}stu[N];

int n;
priority_queue< node,vector<node>,greater<node> >q[4];

void solve(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		int a,mx=0,nxt=0;
		stu[i].w[0]=-2e9;
		for(int j=1;j<=3;j++){
			scanf("%lld",&a);
			if(a>stu[i].w[mx])nxt=mx,mx=j;
			else if(a>stu[i].w[nxt])nxt=j;
			stu[i].w[j]=a;
		}
		stu[i].mx=mx,stu[i].nxt=nxt;
	}
	for(int i=1;i<=n;i++){
		q[stu[i].mx].push(stu[i]);
	}
		
	int flag=0;
	for(int i=1;i<=3;i++)
		if(q[i].size()>n/2)flag=i;	
	
	if(flag){
		while(q[flag].size()>n/2){
			node a=q[flag].top();
			q[flag].pop();
			q[a.nxt].push(a);
		}
	}

	int ans=0;
	for(int i=1;i<=3;i++){
		while(!q[i].empty()){
			ans+=q[i].top().w[i];
			q[i].pop();
		}
	}
	cout<<ans<<'\n';
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
