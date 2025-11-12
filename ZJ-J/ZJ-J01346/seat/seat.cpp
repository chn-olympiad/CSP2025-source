#include <bits/stdc++.h>
using namespace std;
const int N=30;
int s[N][N];
int n,m;
int a[N*N];
int cnt=0,ansx,ansy,flag=0,pos;
bool cmp(int x,int y){return x>y;}
void dfs(int x,int y){
	if(flag)return ;
	s[x][y]=a[++cnt];
	if(a[cnt]==pos){
		ansx=x;
		ansy=y;
		flag=1;
		return ;
	}
	if((y%2==1&&x+1>n)||(y%2==0&&x-1<1)){
		dfs(x,y+1);
	}
	if(y%2==1)dfs(x+1,y);
	else dfs(x-1,y);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	pos=a[1];
	cout<<pos<<endl;
	sort(a+1,a+n*m+1,cmp);
	dfs(1,1);
	cout<<ansy<<" "<<ansx<<endl;
	return 0;
}
