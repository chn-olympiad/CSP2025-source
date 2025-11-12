#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10,M=2e6+10;
int a[12][N],w[N][N],u[N],v[N];

struct Node{
	int u,v,w; 
}e[M];

bool cmp(Node a,Node b){
	return a.w<b.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> c(k);
	for(int i=0;i<m;i++){
		int u1,v1,w1;
		cin>>u1>>v1>>w1;
	    e[i].u=u1;
		e[i].v=v1;
		e[i].w=w1;
	}
	sort(e+1,e+1+m,cmp);
	int ans=0;
	if(k==0){
		for(int i=0;i<4;i++){
			ans+=e[i].w;
		}
	}
	else{
		for(int i=0;i<k;i++){
		    cin>>c[i];
		    for(int j=0;j<n;j++) 
		        cin>>a[i][j];
	    }
	}
	cout<<ans; 
	return 0;
}