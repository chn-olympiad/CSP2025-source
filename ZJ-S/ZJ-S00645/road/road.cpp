#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w;
int ci[11][10005];

struct Bian{
	int st,en,cost;
};
vector<Bian> road;
int num[10005],top[10005];
bool z[10005];
bool cmp(Bian a,Bian b){
	return a.cost<b.cost;
}
vector<int> ve[100005];
void dfs(int i){
	for (int j=0;j<ve[i].size();j++){
		if (ve[i][j]==0){
			z[ve[i][j]]=1;
			dfs(ve[i][j]);
		}
	}
}
long long MinRoad(){
	sort(road.begin()+1,road.end(),cmp);
	long long sum=0;
	memset(z,0,sizeof(z));
	for (int i=1;i<=10000;i++)  ve[i].clear();
	sum+=road[1].cost;
	ve[road[1].st].push_back(road[1].en);
	ve[road[1].en].push_back(road[1].st);
	z[road[1].st]=1;
	z[road[1].en]=1;
	for (int i=2;i<=road.size()-1;i++){
		int num1=road[i].st,num2=road[i].en;
		if (z[num1]==0 && z[num2]==0){
			sum+=road[i].cost;
			ve[num1].push_back(num2);
			ve[num2].push_back(num1);
		}
		else if (z[num1]==1 && z[num2]==0){
			sum+=road[i].cost;
			ve[num1].push_back(num2);
			ve[num2].push_back(num1);
			z[num2]=1;
			dfs(num2);
		}
		else if (z[num1]==0 && z[num2]==1){
			sum+=road[i].cost;
			ve[num1].push_back(num2);
			ve[num2].push_back(num1);
			z[num1]=1;
			dfs(num1);
		}
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	road.push_back(Bian{0,0,0});
	for (int i=1;i<=m;i++){
		cin>>u>>v>>w;
		road.push_back({u,v,w});
		num[u]++;
		num[v]++;
	}
	bool z=1;
	for (int i=1;i<=k;i++){
		cin>>ci[i][0];
		if (ci[i][0]!=0) z=0;
		for (int j=1;j<=n;j++){
			cin>>ci[i][j];
		}
	}
	if (z==1 || k==0){
		for (int i=1;i<=k;i++){
			int nums=0;
			for (int j=1;j<=n;j++){
				if (ci[i][j]==0){
					nums=j;
					continue;
				}
			}
			for (int j=1;j<=n;j++){
				if (j==nums)  continue;
				road.push_back(Bian{nums,j,ci[i][j]});
				num[nums]++;
				num[j]++;
			}
		}
		cout<<MinRoad()<<"\n";
	}/*
	for (int i=1;i<=pow(2,k)-1;i++){
		
	}*/
	return 0;
}
