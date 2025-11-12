#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define db double
#define mp make_pair
#define eb emplace_back
#define pii pair<int,int>
const int N=2e5+10,mod=1e9+7;
int n,a[N][4];
namespace S1{
	int f[205][205][205];
	void init(){
		for(int i=1;i<=n;++i)
			for(int j=0;j<=n/2;++j)
				for(int k=0;k<=n/2;++k)
					f[i][j][k]=0;
	}
	void solve(){
		init();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=3;++j)
				cin>>a[i][j];
		for(int i=1;i<=n;++i){
			for(int j=0;j<=n/2;++j){
				for(int k=0;k<=n/2;++k){
					if(j+k>i) continue;
					if(i-j-k>n/2) continue;
					if(i-j-k>0) f[i][j][k]=f[i-1][j][k]+a[i][1];
					if(j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][2]);
					if(k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][3]);
				}
			}
		}
		int ans=0;
		for(int j=0;j<=n/2;++j){
			for(int k=0;k<=n/2;++k){
				if(n-j-k>n/2) continue;
	//			cout<<n-j-k<<" "<<j<<" "<<k<<" "<<f[n][j][k]<<endl;
				ans=max(ans,f[n][j][k]);
			}
		}
		cout<<ans<<endl;
	}
}
struct node{
	int id,x;
	node(){}
	node(int _id,int _x){
		id=_id;
		x=_x;
	}
	bool operator < (const node &rho) const{
		return x>rho.x;
	}
};
struct club{
	int pos,x,y,z;
	club(){}
	club(int p,int a,int b,int c){
		pos=p;
		x=a;
		y=b;
		z=c;
	}
};
void solve(){
	cin>>n;
	if(n<=200){
		S1::solve();
		return ;
	}
	queue<club> q;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=3;++j)
			cin>>a[i][j];
		q.push(club(i,a[i][1],a[i][2],a[i][3]));
	}
	priority_queue<node> q1,q2;
	while(!q.empty()){
		club p=q.front();
		q.pop();
		if(p.x>p.y){
			if(q1.size()<n/2){
				q1.push(node(p.pos,p.x));
			}
			else{
				node t=q1.top();
				if(p.x+a[t.id][2]>p.y+a[t.id][1]){
					q1.pop();
					q1.push(node(p.pos,p.x));
					q2.push(node(t.id,a[t.id][2]));
				}
				else q2.push(node(p.pos,p.y));
			}
		}
		else{
			if(q2.size()<n/2){
				q2.push(node(p.pos,p.y));
			}
			else{
				node t=q2.top();
				if(p.y+a[t.id][1]>p.x+a[t.id][2]){
					q2.pop();
					q2.push(node(p.pos,p.y));
					q1.push(node(t.id,a[t.id][1]));
				}
				else q1.push(node(p.pos,p.x));
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n/2;++i){
		node t=q1.top();
		ans+=t.x;
		q1.pop();
		t=q2.top();
		ans+=t.x;
		q2.pop();
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
