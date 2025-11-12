#include<bits/stdc++.h>
using namespace std;
int n,m,f[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>f[(i-1)*m+j];
		}
	}
	int wei=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[(i-1)*m+j]>f[1]){
				wei++;
			}
		}
	}
	int count=1,x=1,y=1;
	while(count<wei){
		if((x==n&&y%2==1)||(x==1&&y%2==0)){
			y++;
		}
		else{
			if(y%2==0){
				x-=1;
							
			}
			else{
				x++;
			}
		}
		count++;
		
	}
	cout<<y<<" "<<x;
	
	return 0;
}
