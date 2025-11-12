#include<bits/stdc++.h>
using namespace std;
bool cmd(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,sum = 1;
    int a[15][15]={};
    int z[105]={};
    cin>>n>>m;
    for(int i = 1;i<=n*m;i++){
    	cin>>z[i];
	}
	x = z[1];
	sort(z+1,z+1+n*m,cmd);
	for(int j = 1;j<=m;j++){
		if(j%2==1){
			for(int i = 1;i<=n;i++){
				if(z[sum] == x){
					cout<<j<<" "<<i;
				}
				a[i][j] = z[sum];
				sum++;
			}
		}else{
			for(int i = n;i>=1;i--){
				if(z[sum] == x){
					cout<<i<<" "<<j;
				}
				a[i][j] = z[sum];
				sum++;
			}
		}
	}
    return 0;
}
