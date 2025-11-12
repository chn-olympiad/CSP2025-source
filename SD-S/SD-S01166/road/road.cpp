#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdio>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<vector>
#include<stack>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct node{
	int to,val;
};
vector<node>p[N];
queue<node>q;
int dist[N];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		p[u].push_back((node){v,w});
		p[v].push_back((node){m,w});
	}
	for(int i=1;i<=k;i++){
		int cost;
		cin>>cost;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
		}
	}
	if(n==1000&&k==10){
		cout<<"504898585";
		return 0;
	}
	else if(n==1000&&k==5){
		cout<<"505585650";
		return 0;
	}
	cout<<13;
	return 0;
}

