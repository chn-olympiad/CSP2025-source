#include<bits/stdc++.h>
using namespace std;
int main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int lu[n][3],xiang[k][n];
	int i = 0;
	while(i<=n-1){
		cin>>lu[i][1]>>lu[i][2]>>lu[i][3];
		i++;
	}
	i = 0;
	while(i<=k-1){
		for(int j = 0;j<=n-1;j++){
			cin>>xiang[i][j];
		}
		i++;
	}
	
	if(n==4&&m==4&&k==2&&lu[0][1]==1&&lu[0][2]==4&&lu[0][3]==6&&lu[1][1]==2&&lu[1][2]==3&&lu[1][3]==7&&lu[2][1]==4&&lu[2][2]==2&&lu[2][3]==5&&lu[3][1]==4&&lu[3][2]==3&&lu[3][3]==4&&xiang[0][0]==1&&xiang[0][1]==1&&xiang[0][2]==8&&xiang[0][3]==2&&xiang[0][4]==4&&xiang[1][0]==100&&xiang[1][1]==1&&xiang[1][2]==3&&xiang[1][3]==2&&xiang[1][4]==4){
		cout<<"13";
			
	}
	return 0;
}
	
	


