#include <iostream>
#include <algorithm>
using namespace std;

int seat[11][11];
int score[121];
int sc;
int n,m;

void fnd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==sc){
				cout<<j<<" "<<i;
				return;
			}
		}
	}
	return;
}

bool key(int x,int y){
	return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>score[i];
	}
	
	sc=score[1];
	sort(score+1,score+n*m+1,key);
	
	bool d=1; // 0: up 1: down
	int x=1;
	for(int i=1;;){
		for(int j=1;;){
		seat[i][j]=score[x++];
			if(d==1){ // down
				i++;
				if(i==n){
					seat[i][j]=score[x++];
					if(j==m){
						fnd();
						fclose(stdin);
						fclose(stdout);
						return 0;
					}
					j++;
					d=0;
				}
			}else{ // up
				i--;
				if(i==1){
					seat[i][j]=score[x++];
					if(j==m){
						fnd();
						fclose(stdin);
						fclose(stdout);
						return 0;
					}
					j++;
					d=1;
				}
			}
		}
	}
	
    fclose(stdin);
    fclose(stdout);
	return 0;
}