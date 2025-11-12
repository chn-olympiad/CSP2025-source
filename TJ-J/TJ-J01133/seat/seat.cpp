#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int ma[1001][1001];
int downorup[2]={1,-1};
int dou=0;
int flag;
bool xxx(int a,int b){
	if(a>b){
		return 1;
	}
	return 0;
}
int dfs(int x,int y,int k){
	if(a[k]==flag){
		cout<<y<<' '<<x;
		return 0;
	}
	int x1=x+downorup[dou];
	if(x1<1 or x1>n){
		if(dou==1){
			dou=0;
		}
		else{
			dou=1;
		}
		return dfs(x,y+1,k+1);
	}
	else{
		return dfs(x1,y,k+1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	flag=a[1];
	sort(a+1,a+m*n+1,xxx);
    dfs(1,1,1);
	return 0;
}
