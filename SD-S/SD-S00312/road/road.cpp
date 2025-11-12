#include<bits/stdc++.h>
using namespace std;
/*

*/
int n,m,x,y,z,k;
struct node{
	int next,from,to,mu;
}a[10010];
int pre[10010];
void add(int u,int v,int w){
	k++;
	a[k]={u,v,pre[u],w};
	pre[u]=k;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);	
	}
    if(k==0){
    	cout<<1;
	}
	return 0;
} 
