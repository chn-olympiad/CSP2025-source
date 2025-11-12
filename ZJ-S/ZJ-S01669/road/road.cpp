#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int r,v;
	bool operator < (const node &a)const {
		return v>a.v;
	}
}o;

int n,m,k,c[15],t[15][10100];
vector<node>p[10100];
int prim(){
	bool flag[10100];
	int s=n+k,ans=0;
	memset(flag,false,sizeof flag);
	priority_queue<node> q;
	o.r=1,o.v=0;
	q.push(o);
	while(!q.empty()&&s){
		o=q.top();
		q.pop();
		if(flag[o.r])continue;
		s--;
		
		ans+=o.v;
		flag[o.r]=true;
//		cout<<ans<<" "<<o.r<<"\n";
		for(int i=0;i<p[o.r].size();i++){
			if(!flag[p[o.r][i].r]){
				q.push(p[o.r][i]);
			}
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int q,w,e;
		cin>>q>>w>>e;
		o.r=w,o.v=e;
		p[q].push_back(o);
		o.r=q;
		p[w].push_back(o);
	}
	bool flag0=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)flag0=false;
		for(int j=1;j<=n;j++)cin>>t[i][j];
	}
	if(k==0)cout<<prim();
	else if(flag0){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				o.r=n+i+10,o.v=t[i][j];
				p[j].push_back(o);
				o.r=j;
				p[n+i+10].push_back(o);
			}
		}
		cout<<prim();
	}
	else cout<<prim()-k;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
*/
