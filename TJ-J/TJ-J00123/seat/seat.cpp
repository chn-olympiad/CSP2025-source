#include<bits/stdc++.h>
using namespace std;
int seat[12][12];
int n,m;
int stu[103];
int xiaor;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>stu[i];
	}
	int xiaor=stu[1];
	sort(stu+1,stu+(n*m)+1,cmp);
	int x=1;
	int y=1;
	for(int i=1;i<=n*m;i++){
		seat[x][y]=stu[i];
		
		if(y%2!=0){
			if(x<n){
				x++;
			}else{
				y++;
			}
		}else{
			if(x>1){
				x--;
			}else{
				y++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==xiaor){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
