#include<bits/stdc++.h>
using namespace std;
const long long N=1e7+10;
long long n,m,k;
vector<vector<long long> > ch;
struct all{
	long long l;
	long long r;
	long long w;
}q[N];
bool cmp(all a,all b){
	return a.w<b.w;
}
struct DSU{
	vector<long long> f;
	DSU(long long n):f(n){
		for(long long i=0;i<=n;i++){
			f[i]=i;
		}
	}
	long long find(long long x){
		if(x==f[x]) return x;
		else return f[x]=find(f[x]);
	}
	long long m(long long a,long long b){
		long long fa=find(a),fb=find(b);
		if(fa==fb) return 0;
		f[fa]=fb;
		return 1;
	}
	bool same(long long a,long long b){
		return find(a)==find(b);
	}
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
//	node=vector<vector<long long>>(n+1);
	ch=vector<vector<long long> >(k+1);
	for(long long i=1;i<=m;i++){
		cin>>q[i].l>>q[i].r>>q[i].w;
	}
//	bool t=0;
	long long cnt=m;
	for(long long i=1;i<=k;i++){
		long long x;
		cin>>x;
		//	if(x!=0) t=1;
		ch[i].push_back(x);
		for(long long j=1;j<=n;j++){
			long long y;
			cin>>y;
			ch[i].push_back(y);
		}
		for(long long j=1;j<=n;j++){
			for(long long k=j+1;k<=n;k++){
				cnt++;
				q[cnt].l=j,q[cnt].r=k,q[cnt].w=ch[i][j]+ch[i][k];
			}
		}
	}
	sort(q+1,q+1+cnt,cmp);
	DSU d(n+10);
	long long ans=0;
	for(long long i=1;i<=cnt;i++){
		if(d.same(q[i].l,q[i].r)==0){
			d.m(q[i].l,q[i].r);
			ans+=q[i].w;
		}
	}
	cout<<ans<<"\n";
	return 0;
} 
