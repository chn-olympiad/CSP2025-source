#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[150];
int vis[15][15];

bool cmp(int a,int b){
	return a>b;
}

int find(int R){
	
	int l=1,r=n*m;
	while(l<=r){
		
		int mid=(l+r)/2;
		if(a[mid]==R) return mid;
		else if(a[mid]>R) l=mid+1;
		else r=mid-1;
		
	}
	
}

int fx[]={0,1,-1,0};
int fy[]={0,0,0,1};
//仅需三个方向 
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	
	int R=a[1];
	sort(a+1,a+1+n*m,cmp);
	
	int f=find(R);
	
	int x=1,y=1;
	vis[1][1]=1;
	for(int i=2;i<=f;i++){
		
		for(int j=1;j<=3;j++){
			
			int tx=x+fx[j],ty=y+fy[j];
			if(1<=tx && tx<=n && 1<=ty && ty<=m && !vis[tx][ty]){
				
				vis[tx][ty]=i;
				x=tx,y=ty;
				break;
				
			} 
			
		}
		
	}
	
	cout<<y<<" "<<x;
	
	return 0;
	
}
