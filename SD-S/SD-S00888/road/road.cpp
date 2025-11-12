#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
const int M=1e4+10;

int fps[M];

int head[M];
struct node{
	int wei,w,nx;
}edge[N*2];
int xiang[15];
int qwe[15][M];
bool vis[M];

int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edge[i*2-1].wei=b;
		edge[i*2-1].w=c;
		edge[i*2-1].nx=head[a];
		head[a]=2*i-1;
		edge[i*2].wei=a;
		edge[i*2].w=c;
		edge[i*2].nx=head[b];
		head[b]=2*i;
		
	}
	for(int i=1;i<=k;i++){
		cin>>xiang[i];
		for(int j=1;j<=n;j++){
			cin>>qwe[i][j];
		}
	}
	long long sum=0;
	fps[1]=1;

	int cnt=1;
	
	for(int i=1;i<=cnt;i++){
		long long maxx=1000000005;
		int om=0;
		for(int j=head[fps[i]];j!=0;j=edge[j].nx){
			if(edge[j].w<maxx&&vis[fps[i]]==0){
				maxx=edge[j].w;
				om=edge[j].wei;
			}
		}
		
		if(maxx<1000000005){
			sum+=maxx;
			fps[++cnt]=om;
			vis[om]=1;
		}
		
	}
	cout<<sum;
} 
