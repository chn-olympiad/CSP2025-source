#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt;
int a[1001];
int r;
bool vis[15][15]={0};
bool cmp(int x,int y){
	return x>y;
}
int an;
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			cnt=i;
			break;
		}
	}
	int x=1,y=1;
	vis[1][1]=1;
	while(cnt!=1){
		if((x-1)<=1 && (x+1)<=n && vis[x+1][y]==0){
			cnt--,x++;
			vis[x][y]=1;
			an=2;
		}else if((x+1)>=n && (x-1)>=1 && vis[x-1][y]==0){
			cnt--,x--;
			vis[x][y]=1;
			an=1;
		}else if((x-1)<1 || (x+1)>n){
			y++,cnt--;
			vis[x][y]=1;
		}else{
			if(an==1){
				cnt--,x--;
				vis[x][y]=1;	
			}else{
				cnt--,x++;
				vis[x][y]=1;
			}
		}
	}
	cout<<y<<" "<<x;

	return 0;
}

