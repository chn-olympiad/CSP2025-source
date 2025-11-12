#include<bits/stdc++.h>
using namespace std;
int u[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>u[i];
	}
	int u_=u[0];
	sort(u,u+n*m);
	int x=1,y=1;
	bool f=1;
	for(int i=m*n-1;i>=0;i--){
		if(u[i]==u_){
			break;
		}
		else{
			if(y==n and f){
				x++;
				f=0;
			}
			else if(y==1 and f==0){
				x++;
				f=1;
			}
			else if(x%2==1) y++;
			else if(x%2==0) y--;
			
		}
	}
	cout<<x<<' '<<y;
	return 0;
}
