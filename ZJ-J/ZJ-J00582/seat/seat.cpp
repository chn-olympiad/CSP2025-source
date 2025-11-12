#include<bits/stdc++.h>

using namespace std;
int n,m,che;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	che=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,i=1;
	while(x<=n||y<=m){
		if(a[i]==che){
			cout<<y<<' '<<x;
			break;
		}
		i++;
		if(y%2==1){
			if(x==n){
				y++;
			}
			else{
				x++;
			}
		}
		else{
			if(x==1){
				y++;
			}
			else {
				x--;
			}
		}
	}
	return 0;
}

