#include<bits/stdc++.h>
using namespace std;
int vis[20][20];
int n,m,x=1,y=1,sum;
int a[205];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+1+n*m,cmp);
	vis[1][1]=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			cout<<x<<" "<<y;
			break;
		}else if(y+1<=n&&vis[x][y+1]==0){
			y++;
			vis[x][y]=1;
		}else if(y-1>=1&&vis[x][y-1]==0){
			y--;
			vis[x][y]=1;
		}else if(x+1<=m&&vis[x+1][y]==0){
			x++;
			vis[x][y]=1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
