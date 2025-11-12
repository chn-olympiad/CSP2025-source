#include <bits/stdc++.h>
using namespace std;
int n,m,score[105],Rscore,seatid,seatnum,seatn,seatm;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	seatnum = n*m;
	scanf("%d",&Rscore);
	score[1] = Rscore;
	for(int i = 2;i <= seatnum;i++) scanf("%d",&score[i]);
	sort(score+1,score+seatnum+1);
	for(int i = 1;i <= seatnum;i++){
		if(Rscore == score[i]){
			seatid = seatnum-i+1;
			break;
		}
	}
	seatm = (seatid+n-1)/n;
	if(seatm%2) seatn = seatid-(seatm-1)*n;
	else seatn = n+1-(seatid-(seatm-1)*n);
	printf("%d %d",seatm,seatn);
	return 0;
}
