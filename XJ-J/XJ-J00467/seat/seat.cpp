#include<bits/stdc++.h> 
using namespace std;
int n,m;
int mp[5000][5000];
int num[500000];
int xr;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int y,int step){
	mp[x][y]=step;
	step++;
	if(x==1&&y==m){
	    return;
	}//·µ»Ø

	else if(x==n&&y%2==1||x==1&&y%2==0){
		y++;
	}
    else if(y%2==0&&x!=1){
    	x--;
	}
	else if(y%2==1){
		x++;
	}
	dfs(x,y,step);
}
void dfsv(int x,int y,int step){
	mp[x][y]=step;
	step++;
	if(x==n&&y==m){
		return ;
	}//·µ»Ø 
	else if(x==n&&y%2==1||x==1&&y%2==0){
		y++;
	}
    else if(y%2==0&&x!=1){
    	x--;
	}
	else if(y%2==1){
		x++;
	}
	dfs(x,y,step);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; 
	int p=1;
	for(int i=1;i<=n*m;i++){
		cin>>num[i];
		xr=num[1];
		if(num[i]>xr){
			p++;
		}
	}

	if(m%2==1){
		dfsv(1,1,1);
	}
    else{
   	   dfs(1,1,1);
    }
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=m;j++){
	       if(mp[i][j]==p){
	       	cout<<j<< " "<<i;
	       	return 0;
		   }
	    }
	}
}
