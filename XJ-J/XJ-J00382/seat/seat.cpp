#include <bits/stdc++.h>
using namespace std;
int n,m,score[110],nds;
bool cmp(int q,int h){
	return q > h;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) cin >> score[i];
	int xs = score[1];
	sort(score+1,score+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		if(score[i] == xs){
			nds = i;
			break;
		}
	}
	int ans_c = -1;
	int ans_r = -1;
	while(ans_c * n < nds) ans_c ++;
	ans_r = nds % n;
	if(ans_c % 2 == 0){
		if(ans_r == 0) ans_r = n;
		ans_r = n - (ans_r - 1);
	}else{
		if(ans_r == 0) ans_r = n;
	} 
	
	printf("%d %d",ans_c,ans_r);
	return 0;
}
