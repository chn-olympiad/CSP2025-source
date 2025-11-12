#include<bits/stdc++.h>
using namespace std;
int m,n,R,cnt,a[15][15],r[105];
void dfs(int cnt,int x,int y){
	if(cnt==0)return;
	a[x][y]=r[cnt];
	if(r[cnt]==R){
		cout<<y<<" "<<x<<endl;
		return;
	}
	cnt--;
	if(x==n)if(a[x-1][y]!=0)return dfs(cnt,x,y+1);
	if(x==1)if(a[x+1][y]!=0)return dfs(cnt,x,y+1);
	if(x!=n&&a[x+1][y]==0)return dfs(cnt,x+1,y);
	return dfs(cnt,x-1,y);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>R;
	r[1]=R;
	for(int i=2;i<=n*m;++i){
		cin>>r[i];
	}
	sort(r+1,r+n*m+1);
	dfs(n*m,1,1);
	return 0;	
}