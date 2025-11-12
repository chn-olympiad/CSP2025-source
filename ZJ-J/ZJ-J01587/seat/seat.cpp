#include<bits/stdc++.h>
using namespace std;
int c,r;
int a[105]={};
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>c>>r;
	int cnt=0;
	for(int i=1;i<=c;++i){
		for(int j=1;j<=r;++j){
			cnt++;
			cin>>a[cnt];
		}
	}	
	int score=a[1],weizhi;
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;++i){
		if(score==a[i]){
			weizhi=i;
		}
	}
	int x=0,y=0;
	if(weizhi%c!=0){
		y++;
	}
	y+=weizhi/c;
	if(weizhi%c==0){
		if(y%2==0){
			x=1;
		}
		else x=c;
	}
	else{
		if(y%2==0){
		x=c+1-weizhi%c;
	}
	else x=weizhi%c;
	}
	cout<<y<<" "<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

