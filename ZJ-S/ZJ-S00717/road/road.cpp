#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6+10;
int n,m,k,u[N],v[N],w[N],c[30],a[30][10000+10],A;
bool f[N];
struct node{
	int pre,to,v;
	bool operator<(node y)const{
		return v<y.v;
	}
}t;

priority_queue<node> pq,q;
vector<int> g[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		t.pre=min(u[i],v[i]);
		t.to=max(u[i],v[i]);
		t.v=-w[i];
		pq.push(t);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			t.pre=j,t.to=n+i,t.v=-(a[i][j]+c[i]);
			pq.push(t);
			if(c[i]!=0||a[i][j]!=0){
				A=1;
			}
		}
	}
	if(A==0&&k!=0){
		cout<<0;
		return 0;
	}
//	if(k==0){
//		int ac=0,ans=0;
//		while(ac+1!=n){
//			t=pq.top();
//			
//			ans+=-t.v;
//			ac++;
//			cout<<t.pre<<" "<<t.to<<" "<<t.v<<endl;
//			f[t.to]=1,f[t.pre]=1;
//			pq.pop();
//		}
//		cout<<ans;
//		return 0;
//	}
	int ac=0,ans=0;
	while(ac<n){
		t=pq.top();
		if(f[t.pre]==1&&f[t.to]==1){
			pq.pop();
			continue;
		}
		if(t.to>n){
			if(f[t.to]==1) ans+=-t.v-c[t.to-n];
			else ans+=-t.v;
		}else{
			ans+=-t.v;
		}
		ac++;
		f[t.to]=1,f[t.pre]=1;
		pq.pop();
	}
	cout<<ans;
	
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 5 0
1 2 3
1 4 7
3 4 1
2 3 6
1 3 8
*/
