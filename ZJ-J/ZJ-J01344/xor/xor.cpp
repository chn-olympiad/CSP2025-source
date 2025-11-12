#include<bits/stdc++.h>
using namespace std;
struct complete{
	long long x,y;
};
long long a[500001],c[500001],n,m,t,maxn;
vector<complete> b;
bool check(long long k){
	for(int i=1;i<k;i++){
		for(int j=i+1;j<=k;j++){
			long long p=c[i],q=c[j];
			if(b[p].x==b[q].x||b[p].y==b[q].y) return 0;
			if(b[p].x<b[q].x&&b[p].y>=b[q].x||b[p].x>b[q].x&&b[p].x<=b[q].y) return 0;
		}
	}
	return 1;
}
void dfs(long long x,long long k){
	if(!check(k)) return;
	if(x==b.size()){
		maxn=max(maxn,k);
		return;
	}
	c[k+1]=x;
	dfs(x+1,k+1);
	c[k+1]=0;
	dfs(x+1,k);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		t=0;
		for(int j=i;j<=n;j++){
			t^=a[j];
			if(t==m) b.push_back(complete{i,j});
		}
	}
	dfs(0,0);
	cout<<maxn;
	return 0;
}
