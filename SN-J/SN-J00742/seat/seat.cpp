//SN-J00742 王安祺 西安市高新第一学校 
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[15][15];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n>10||m>10){
		return 0;
	}
	int num=(n)*(m);
	int fen[num+5];
	for(int i=0;i<num;i++){
		cin>>fen[i];
		if(fen[i]>100){
			return 0;
		}
	}
	int numb=0;
	int R=fen[0];
	sort(fen,fen+num,cmp);
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				a[i][j]=fen[numb];
				numb++;
				if(a[i][j]==R){
					cout <<i+1<<" "<<j+1;
				}
			}
		}
		else{
			for(int j=n;j>0;j--){
				a[i][j]=fen[numb];
				numb++;
				if(a[i][j]==R){
					cout <<i+1<<" "<<j+1;
				}
			}
		}
	}
	return 0;
}
