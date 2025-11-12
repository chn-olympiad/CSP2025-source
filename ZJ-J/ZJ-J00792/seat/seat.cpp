#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int vis[15][15];
long long wz;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int y,int sum,int wz,int o){
	if(sum==wz){
		cout<<x<<" "<<y;
		return ;
	}
	if(o==0){
		if(y==n){
			dfs(x+1,y,sum+1,wz,1);
		}else{
			dfs(x,y+1,sum+1,wz,0);
		}
	}else{
		if(y==1){
			dfs(x+1,y,sum+1,wz,0);
		}else{
			dfs(x,y-1,sum+1,wz,1);
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int x;
	cin>>x;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	a[1]=x;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(x==a[i]){
			wz=i;
			break;
		}
	}
//	cout<<wz;
	dfs(1,1,1,wz,0);
	return 0;
}

