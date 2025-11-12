#include<bits/stdc++.h>
using namespace std;
#define N 15
int n,m,tabl[N][N],a[500];
void dfs(int x,int y,int cur,int rk,bool tm){
//	printf("%d %d %d %d %d\n",x,y,cur,rk,tm);
	if(n==1){
		tabl[x][y]=rk;
		if(y>=m) return;
		dfs(x,y+1,cur,rk+1,tm);
		return ;
	}
	if((x==1||x==n)&&!tm){
		if(y>=m){
			tabl[x][y]=rk;
			return ;
		}
		else{
			tabl[x][y]=rk;
			dfs(x,y+1,cur*(-1),rk+1,1);
			return ;
		}
	}
	else{
		tabl[x][y]=rk;
		dfs(x+cur,y,cur,rk+1,0);
		return ;
	}
	return ;
	
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	int xr=a[1],pos_=1;
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=n*m;++i){
		if(a[i]==xr){
			pos_=i;
			break;
		}
	}
	if(n==m&&n==1){
		cout<<1<<' '<<1;
		return 0;
	}
	dfs(1,1,1,1,1);
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=m;++j){
//			cout<<tabl[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//	cout<<xr<<' '<<pos_<<'\n';
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(tabl[i][j]==pos_){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
