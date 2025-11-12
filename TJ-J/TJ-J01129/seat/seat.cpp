#include<bits/stdc++.h>
using namespace std;
int nnn,mmm;
int aaa[12][12];
int bbb[120],lll=1;
int ccc[12][12];
int ffirst;
int xxx,yyy;
bool cmp(int x,int y){
	return  x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>nnn>>mmm;
	for(int i=1;i<=nnn;i++){
		for(int j=1;j<=mmm;j++){
			cin>>aaa[i][j];
			bbb[lll++]=aaa[i][j];
			if(i==1&&j==1)
				ffirst=aaa[i][j];
		}
	}
	sort(bbb+1,bbb+1+lll,cmp); 
	for(int kk=1;kk<=lll;kk++){
		if(kk<=nnn){
			ccc[1][kk]=bbb[kk];
			continue;
		}
		if((kk-1)%nnn==0 && (kk-1)/nnn%2==1){
			ccc[(kk-1)/nnn+1][nnn]=bbb[kk];
			continue;
		}
		
		else if((kk-1)%nnn==0 && (kk-1)/nnn%2==0 ){
			ccc[(kk-1)/nnn+1][1]=bbb[kk];
			continue;
		}
		if(kk%nnn==0 && (kk/nnn)%2==0){
			ccc[kk/nnn][1]=bbb[kk];
			continue;
		}
		else if(kk%nnn==0 && (kk/nnn)%2==1){
			ccc[kk/nnn][nnn]=bbb[kk];
			continue;
		}
		ccc[kk/nnn+1][kk%nnn]=bbb[kk];
		
		
	}
	for(int i=1;i<=nnn;i++){
		for(int j=1;j<=mmm;j++){
			if(ccc[i][j]==ffirst){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
} 
