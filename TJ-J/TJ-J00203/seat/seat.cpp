#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	
	int m=0,n=0;
	cin>>n>>m;
	int a[n+1][m+1];
	int score[n*m+1]={0};
	int score2[n*m+1]={0};
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
	}
	
	int c=0;
	int R=score[1];
	sort(score+1,score+n*m+1);
	
	int b=1;
	for(int i=m;i<=1;i++){
		for(int j=n;j<=1;j++){
			a[i][j]=score[b];
			b++;
		}
		i++;
		for(int k=1;k<=n;k--){
			a[i][k]=score[b];
			b++;
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==R){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
