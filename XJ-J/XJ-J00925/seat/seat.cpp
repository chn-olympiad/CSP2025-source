#include<bits/stdc++.h>
using namespace std;
int a[1005];
int c[105][105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		c[x][y]=a[i];
		if(c[x][y]==num){
			cout<<y<<' '<<x;
		}
		if(y%2==1 && x!=n){
			x++;
		}
		else if(y%2==1 && x==n){
			y++;
		}
		else if(y%2==0 && x!=1){
			x--;
		}
		else if(y%2==0 && x==1){
			y++;
		}
		
	}
	return 0;
}

