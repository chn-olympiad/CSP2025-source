#include<bits/stdc++.h>
using namespace std;
int n,m;
int map[20][20];
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+n*m);
	int x=1,y=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){
			cout<<y<<" "<<x;
			break;
		}else{
			if(y%2==0){
				x--;
				if(x<1){
					x=1;
					y++;
				}
			}else{
				x++;
				if(x>n){
					x=n;
					y++;
				}
			}
		}
	}
	return 0;
}
