#include<bits/stdc++.h>
#define b second
#define a first
using namespace std;
int n,m,k,jans;
vector<pair<int,int> >p[1000005];
struct node {
	int a;
	pair<int,bool> b[10004];
}x[11];
void pr(){
	vector<int>ww;
	ww.push_back(1);
	for(int u=1;u<n;u++){
		int ma=1e9,mb=0;
		for(int i=0;i<ww.size();i++){
			for(int j=0;j<p[ww[i]].size();j++){
				if(p[ww[i]][j].b<ma){
					bool f=0;
					for(int ii=0;ii<ww.size();ii++){
						if(ww[ii]==p[ww[i]][j].a){
							f=1;break;
						}
					}
					if(!f){
						ma=p[ww[i]][j].b;mb=p[ww[i]].a;
					}
				}
			}
		}
		ww.push_back(mb);jans+=ma;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;
		p[u].push_back({v,w});
		p[v].push_back({u,w});
	}
	for(int i=0;i<k;i++){
		cin>>x[i].a;
		for(int j=0;j<n;j++){
			cin>>x[i].b.first;
		}
	}
	cout<<jans<<endl;
	return 0;
}
