#include<bits/stdc++.h>
using namespace std;

int seats[15][15];
int score[110];
int n,m;

void setseats(int n, int m){
	bool flag=0;
	int snum=1;
	for(int i=1;i<=n;i++){
		if(flag==0){
			for(int j=1;j<=m;j++){
				seats[j][i]=snum;
				snum++;
				flag=1;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				seats[j][i]=snum;
				snum++;
				flag=0;
			}
		}
	}
	return;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> score[i];
	}
	setseats(n,m);
	
	int seatnumber=1;
	for(int i=2;i<=n*m;i++){
		if(score[1]<score[i]) seatnumber++;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seats[i][j]==seatnumber){
				printf("%d %d",j,i);
			}
		}
	}
	return 0;
}
