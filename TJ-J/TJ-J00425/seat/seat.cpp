#include<iostream>
using namespace std;
int x=1,y=1,n,m,a,se=0,p,sea[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++){
		cin>>sea[i-1];
	}
	for(int i=0;i<(n*m)-1;i++){
		if(sea[i]>a){
			se++;
		}
	}
	for(int i=0;i<se;i++){
		if(y%2==0){
			x--;
		}else{
			x++;
		}
		if(x>n){
			x=n,y++;
		}else if(x<1){
			x=1;y++;
		}
	}
	cout<<y<<" "<<x;
	return 0;
} 
