#include<bits/stdc++.h>
using namespace std;
int n,m,a[500000],fen,l,x=1,y=1,flag;
int g(int a,int b){
	return a>b;
}
void dfs(int cnt){
	if(cnt==l){
		return ;
	}
	if(x<1||x>n||y<1||y>n){
		return ;
	}
	if(y%2==1){
		if(x==n){
			y++;
		}else{
			x++;
		}
	}
	else{
		if(x==1){
			y++;
		}else{
			x--;
		}
	}
	dfs(cnt+1);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	fen=a[1];
	sort(a+1,a+n*m+1,g);
	for(int i=1;i<=n*m;i++){
		if(a[i]==fen){
			l=i;
			break;
		}
	}
	dfs(1);
	cout<<y<<" "<<x;
	return 0;
}
