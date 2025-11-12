#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int s=a[1],d=n*m;
	sort(a,a+n*m);
	int x=1,y=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[d]==s){
				cout<<y<<' '<<x;
				return 0;
			}else if(x==n&&y%2==1){
				y++;
			}else if(x==1&&y%2==0){
				y++;
			}else if(y%2==1){
				x++;
			}else{
				x--;
			}		
			d--;		
		}
	}
	
	return 0;
} 
