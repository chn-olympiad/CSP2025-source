#include<bits/stdc++.h>
using namespace std;
int m,n,k;
long long total;
bool country=0;
struct road{
	int city1,city2,cost;
}r[1200000];
int town[15];
bool city[10100];
bool cmp(road a,road b){
	return a.cost<b.cost;
}
struct vallage{
	int c,w;
}v[13][10200];
bool cmp2(vallage a,vallage b){
	return a.w<b.w;
}


void work_1(){
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(city[r[i].city1]==0||city[r[i].city2]==0){
			city[r[i].city1]=1;
			city[r[i].city2]=1;
			total+=r[i].cost;
		}
	}
	cout<<total;
}
void work_2(){
	for(int i=1;i<=k;i++){
		sort(v[i]+1,v[i]+n+1,cmp2);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			r[m+n*(i-1)+j].city1=v[k][1].c;
			r[m+n*(i-1)+j].city2=v[k][j].c;
			r[m+n*(i-1)+j].cost=v[k][j].w;
		}
	}
	m+=k*n;
	work_1();
}



int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>r[i].city1>>r[i].city2>>r[i].cost;		
	}
	for(int i=1;i<=k;i++){
		cin>>town[i];
		for(int j=1;j<=n;j++){
			cin>>v[i][j].w;
			v[i][j].c=j;
		}
		if(town[i]!=0)country=1;
	}
	if(k==0)work_1();
	else if(country==0)work_2();
	return 0;
}
