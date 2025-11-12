#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N][N][3],a1[N];
bool b[N];
int n,m,k;
int dfs(int s,int sum,int i){
	if(s==1) return sum;
	int mi=10000000,p;
    for(int j=1;j<=a1[i];j++){
	    if(a[i][j][1]<mi&&b[a[i][j][2]]==0){
	    	mi=a[i][j][1];
	    	p=a[i][j][2];
		}
 	}
 	if(mi==10000000){
 	    for(int i=1;i<=n;i++){
 	    	if(b[i]==0) return dfs(s-1,sum,i);
		}	
	}
    sum+=mi;
 	b[p]=1;
    return dfs(s-1,sum,p);
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
	   	int u1,v1,w1;
	   	cin>>u1>>v1>>w1;
	   	a[u1][++a1[u1]][1]=v1;
	   	a[u1][a1[u1]][2]=w1;
	   	a[v1][++a1[v1]][1]=u1;
	   	a[v1][a1[v1]][2]=w1;
   	}
    int d;
  	while(cin>>d);
    b[1]=1;
   	cout<<dfs(n,0,1);
	return 0;
}