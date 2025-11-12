#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define repr(i,a,b) for(int i = a;i <= b;i++)
#define maxn 1000005 
#define PII pair<int,int>
int c[maxn];
int a[15][100005];
vector<PII> e[maxn];
namespace task1{
	
}
namespace task2{
	
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	repr(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	repr(j,1,k){
		cin>>c[j];
		if(c[j]!=0) flag = false;
		repr(i,1,n){
			cin>>a[j][i];
		}
	}
	if(flag) task1();
	if(k==0) taks2();
	return 0;
} 
