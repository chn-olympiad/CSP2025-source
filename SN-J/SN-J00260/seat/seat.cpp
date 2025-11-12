#include<bits/stdc++.h>
using namespace std;
int score[100],x,y,ansx,ansy,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	for(int i=0;i<x*y;i++){
		cin>>score[i];
		if(i==0){
			num=score[0];
		}
		for(int j=0;j<i;j++){
			if(score[j]<score[i]){
				swap(score[j],score[i]);
			}
		}
	}
	for(int i=0;i<x*y;i++){
		if(score[i]==num){
			ansx=i/x+1;
			if(ansx%2==0){
				ansy=y-(i+1)%y+1;
				if(ansy-1==y){
					ansy=1;
				}
			}else{
				ansy=(i+1)%y;
				if(ansy==0){
					ansy=y;
				}
			}
			
			cout<<ansx<<" "<<ansy;
		}
	}
	return 0;
}
