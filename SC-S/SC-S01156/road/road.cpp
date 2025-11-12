#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,pair<int,int> > > p;
int cts[20][10101];
long long zx;
vector<pair<int,pair<int,int> > > pp;
int f[10101];
void init(){
	for(int i=1; i<=10010; i++){
		f[i]=i;
	}
}
int fd(int x){
	int fx=f[x];
	if(fx==x){
		return fx;
	}
	return f[x]=fd(fx);
}
int hb(int x,int y){
	x=fd(x);
	y=fd(y);
	if(x==y){
//		cout<<"hb";
		return 0;
	}
	f[y]=x;
//	cout<<"hb";
	return 1;
}
long long op1(int xz){
	init();
	long long num=0;
	vector<pair<int,pair<int,int> > > ppp;
	for(int i=0; i<pp.size(); i++){
		ppp.push_back({pp[i].first,{pp[i].second.first,pp[i].second.second} } );
	}
	for(int i=1; i<=k; i++){
		if(xz&(1<<(i-1))){
			num+=cts[i][0];
			for(int j=1; j<=n; j++){
				ppp.push_back({cts[i][j],{10000+i,j}});
			}
		}
	}
	sort(ppp.begin(),ppp.end());
	for(int i=0; i<ppp.size(); i++){
		int a=ppp[i].first,b=ppp[i].second.first,c=ppp[i].second.second;
		if(hb(b,c)){
			num+=a;
		}
	}
	return num;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		p.push_back({w,{u,v}});
	}
	for(int i=1; i<=k; i++){
		for(int j=0; j<=n; j++){
			cin>>cts[i][j];
		}
	}
	init();
	sort(p.begin(),p.end());
	for(int i=0; i<p.size(); i++){
		int a=p[i].first,b=p[i].second.first,c=p[i].second.second;
		if(hb(b,c)){
			zx+=a;
			pp.push_back({a,{b,c}});
		}
	}
	for(int i=1; i<(1<<k); i++){
		zx=min(zx,op1(i));
	}
	cout<<zx;
	return 0;
}