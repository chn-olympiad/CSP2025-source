//SN-J01010,ZHAOWEIZE,25.11.1;
#include<bits/stdc++.h>
using namespace std;
int hang,lie,sc1;
int score[200];

bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>hang>>lie;
	//read
	for(int i=1;i<=hang*lie;i++){
		cin>>score[i];
	}
	//sc1:r's score
	sc1=score[1];
	sort(score+1,score+hang*lie+1,cmp);
	int scseat=0;
	//check r's seat num
	for(int i=1;i<=hang*lie;i++){
		if(score[i]==sc1)scseat=i;
	}

	//r's seat
	int sclie=scseat/hang;
	int schangtmp=scseat%hang;
	int schang=0;
	if(schangtmp!=0)sclie+=1;
	if(schangtmp==0){
		if(sclie%2==1)schang=hang;
		if(sclie%2==0)schang=1;
	}
	else{
		if(sclie%2==0)schang=hang-schangtmp+1;
		if(sclie%2==1)schang=schangtmp;
		
	}
	cout<<sclie<<" "<<schang;
	
	return 0;
} 
