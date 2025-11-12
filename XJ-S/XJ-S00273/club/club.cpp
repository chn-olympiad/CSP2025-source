#include<bits/stdc++.h>
using namespace std;
struct zhi{
	int x,y,z;
	
};zhi a[100005],b[100005],c[10005];

int bfs(int n,int x,int y,int z,int maxx,int nn,zhi a[]){
	if(n==nn){
		return maxx;
	}
	int m=-1e9;
	if(x<nn/2){
		maxx+=a[n].x ;
		m=max(m,bfs(n+1,x+1,y,z,maxx,nn,a));
		maxx-=a[n].x;
	}
	if(y<nn/2){
		maxx+=a[n].y ;
		m=max(m,bfs(n+1,x,y+1,z,maxx,nn,a));
		maxx-=a[n].y;
	}
	if(z<nn/2){
		maxx+=a[n].z ;
		m=max(m,bfs(n+1,x,y,z+1,maxx,nn,a));
		maxx-=a[n].z;
	}
	return m;
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,b,nn,num=0;
	cin>>nn;
	for(int i=0;i<nn;i++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		

			
		}
		
		int m=bfs(0,0,0,0,0,n,a);
		cout<<m;
		
	}
	
	return 0;
}
