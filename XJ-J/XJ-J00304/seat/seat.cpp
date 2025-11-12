#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,m;
int arr[105];
bool cmp(int x,int y){
	return x>y;
}
bool kc[110][110];
int sx[3]={1,0,-1};
int sy[3]={0,1,0};
int rx,ry;
void dfs(int x,int y,int stepp){
	if(stepp==0){
		rx=x;
		ry=y;
		return ;
	}
	
	
	if(x>=1&&x<n&&y>=1&&y<=m&&y%2!=0){
		int zx=x+sx[0];
		int zy=y+sy[0];
		dfs(zx,zy,stepp-1);
	}
	
	else if((x>=1&&x==n&&y>=1&&y<=m&&y%2!=0)||(x==1&&y>=1&&y<=m&&y%2==0)){
		int zx=x+sx[1];
		int zy=y+sy[1];
		dfs(zx,zy,stepp-1);
	}
	
	else if(x>1&&x<=n&&y>=1&&y<=m&&y%2==0){
		int zx=x+sx[2];
		int zy=y+sy[2];
		dfs(zx,zy,stepp-1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
		cin>>n>>m;
	for(int a=1;a<=n*m;a++)
		cin>>arr[a];
	int xr=arr[1];
	int xrg=0;
	sort(arr+1,arr+n*m+1,cmp);
	for(int a=1;a<=n*m;a++)
		if(arr[a]==xr)
			xrg=a;
	dfs(1,1,xrg-1);
	cout<<ry<<" "<<rx;
	return 0;
} 
