#include<bits/stdc++.h>
using namespace std;
const int N=1007;
struct people{
	int score,w;//wei
}sc[N];//score
int cmp(people a,people b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=(n*m);i++){
		scanf("%d",&sc[i].score);
		sc[i].w=i;
	}
	sort(sc+1,sc+(n*m)+1,cmp);
	int h=1,l=1;//hang,lie
	for(int i=1;i<=(n*m);i++){
		if(sc[i].w==1){
			printf("%d %d",l,h);
			break;
		}
		if(l%2==1){
			if(h==n){
				l++;
			}else{
				h++;
			}
		}else{
			if(h==1){
				l++;
			}else{
				h--;
			}
		}
	}
	return 0;
}
