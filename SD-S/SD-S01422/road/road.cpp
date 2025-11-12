#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
int n,m,k,aa,ab,ac,fa[N],c[15],a[15][N],sz[N];
ll la[N],l;
int Fi(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=Fi(fa[x]);
}
//vector<pair<int,pair<int,int> > >;
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >p,v[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>aa>>ab>>ac;
		p.push({ac,{aa,ab}});
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;sz[i]=1;
	}
	while(p.size()){
		pair<int,pair<int,int> >q=p.top();
		p.pop();
		int x=q.second.first,y=q.second.second;
		if(Fi(x)!=Fi(y)){
			if(sz[Fi(x)]>sz[Fi(y)]){
				swap(x,y);
			}
			sz[Fi(y)]+=sz[Fi(x)];
			fa[Fi(x)]=Fi(y);
			v[0].push(q);
			la[0]+=q.first;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	l=la[0];
	for(int s=1;s<(1<<k);s++){
		int pq=0;
		for(int i=k-1;i>=0;i--){
			if((s&(1<<i))){
				if(!pq){
//				cout<<"ok"<<i<<endl;
					pq=i;
				}
				la[s]=la[s]+c[i+1];
			}
		}
		p=v[s^(1<<pq)];
//		for(int i=0;i<v[s^(1<<pq)].size();i++){
//			p.push([i]);
//		}
		for(int i=1;i<=n;i++){
//			cout<<pq<<"p"<<i<<endl;
			p.push({a[pq+1][i],{pq+1+n,i}});
		}
//		cout<<"a"<<s<<endl;
		for(int i=1;i<=n+k;i++){
			fa[i]=i;sz[i]=1;
		}
		while(p.size()){
			pair<int,pair<int,int> >q=p.top();
			p.pop();
			int x=q.second.first,y=q.second.second;
			if(Fi(x)!=Fi(y)){
				if(sz[Fi(x)]>sz[Fi(y)]){
					swap(x,y);
				}
				sz[Fi(y)]+=sz[Fi(x)];
				fa[Fi(x)]=Fi(y);
				v[s].push(q);
//				cout<<la[s]<<" "<<q.first<<" "<<q.second.first<<" "<<q.second.second<<endl;
				la[s]+=q.first;
			}
		}
//		cout<<s<<" "<<la[s]<<endl;
		l=min(l,la[s]);
	}
	cout<<l;
	return 0;
}
