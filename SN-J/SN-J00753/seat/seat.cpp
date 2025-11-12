#include<bits/stdc++.h>
using namespace std;
int t[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cj,xR,x=1,y=1;
	cin>>n>>m;
	cin>>xR;
	t[xR]=1;
	for(int i=2;i<=n*m;i++){
		cin>>cj;
		t[cj]=1;
	}
	for(int i=100;i>=1;i--){
		if(i==xR){
			cout<<x<<" "<<y;
			return 0;
		}
		if(t[i]==1){
			if(x%2==1){
				y++;
			}
			else{
				y--;
			}
			if(y>n||y==0){
				x++;
				if(x%2==1){
					y=1;
				}
				else{
					y=m;
				}		
			}
		}
	}
}
