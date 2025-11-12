#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r,f;
void dfs(int x,int y,int p){
	if(f)return;
//	cout<<x<<" "<<y<<" "<<p<<endl;
	if(a[p]==r){
		cout<<y<<" "<<x;
		f=1;
		return;
	}
	if(x==n){
		if(y%2==1)dfs(x,y+1,p-1);
		else dfs(x-1,y,p-1);
	}
	else if(x==1){
		if(y%2==0)dfs(x,y+1,p-1);
		else dfs(x+1,y,p-1);
	}
	else if(y%2)dfs(x+1,y,p-1);
	else dfs(x-1,y,p-1);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1);
	dfs(1,1,n*m);
	return 0;
}