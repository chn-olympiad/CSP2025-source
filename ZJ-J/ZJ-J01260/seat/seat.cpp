#include<bits/stdc++.h>
using namespace std;
int n,m,c;int rp=INT_MAX;
struct node{
	int h;
	int st;
}a[110];
bool f[11][11];
bool cmp(node a,node b){
	return a.st>b.st;
}
void dfs(int k,int x,int y){
	f[x][y]=1;
	if(a[k].h==1){cout<<x<<" "<<y;return ;}
	else{
		if(!f[x][y+1]&&y+1<=n) dfs(k+1,x,y+1);
		else if(!f[x][y-1]&&y-1>=1) dfs(k+1,x,y-1);
		else if(!f[x+1][y]&&x+1<=m) dfs(k+1,x+1,y);
	} 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	c=n*m;
	for(int i=1;i<=c;i++){
		cin>>a[i].st;
		a[i].h=i;
	}
	sort(a+1,a+c+1,cmp);
	dfs(1,1,1);
	return 0;
}
