#include<bits/stdc++.h>
#define pii pair<long long,long long>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const long long N=140086;

long long p[N];
struct node{
	long long val,l,r;
};vector<node> t;
bool cmp(node a,node b){
	return a.val<b.val;
}
long long find(long long x){
	if(p[x]==x)return x;
	return p[x]=find(p[x]);
}
void up(long long x,long long y){
	x=find(x);y=find(y);
	p[x]=y;
}
int main(){
	IOS;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v,w;cin>>u>>v>>w;
		t.push_back({w,u,v});
	}
	for(long long i=n+1;i<k+n+1;i++){
		long long x;cin>>x;
		for(long long j=1;j<=n;j++){
			long long l;cin>>l;
			t.push_back({0,i,j});
		}
	}
	sort(t.begin(),t.end(),cmp);
	for(long long i=0;i<=n+k+1;i++){
		p[i]=i;
	}
	long long h=0;
	long long ans=0;
	for(auto tmp:t){
		if(find(tmp.l)!=find(tmp.r)){
			up(tmp.l,tmp.r);
			ans+=tmp.val;
			h++;
			if(h==n-1)break;
		}
	}
	cout<<ans;
	return 0;
}

