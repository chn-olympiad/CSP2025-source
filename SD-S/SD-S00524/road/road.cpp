#include <bits/stdc++.h>
using namespace std;
struct str{
	int s1;
	int s2;
	int id=0;
};
int n,m,k;
int u,v,w;
int q[10050];
vector < str > ve[10050];
int qu[10050],l=0;
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		str asd;
		asd.s1=v;
		asd.s2=u;
		asd.id=0;
		ve[u].push_back(asd);
		asd.s1=u;
		asd.s2=v;
		ve[v].push_back(asd);
	}
	l++;
	qu[l]=u;
	while(l<n){
		int road_min=INT_MAX,city11,city1,city2;
		for(int i=1;i<=l;i++){
			int h=ve[i].size();
			for(int j=0;j<h;j++){
				if(road_min>ve[i][j].s2){
					if(ve[i][j].id==1) continue;
					road_min=ve[i][j].s2;
					city1=i;
					city11=j;
					city2=ve[i][j].s1;
				}
			}
		}
		l++;
		qu[l]=city2;
		ans+=road_min;
		ve[city1][city11].id=1;
		
		cout<<road_min<<endl;
	}
	cout<<ans;
	return 0;
}
