#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=1,r=1,s,p=0;
	cin>>n>>m;
	int score[n*m];
	for (int i=0;i<sizeof(score)/4;i++){
		cin>>score[i];
	}
	s=score[0];
	sort(score,score+n*m,cmp);
	while(true){
		if(score[p]==s) break;
		else if(c%2==1){
			if(r==n) c++;
			else r++;
		}else if(c%2==0){
			if(r==1) c++;
			else r--;
		}
		p++;
	}
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
