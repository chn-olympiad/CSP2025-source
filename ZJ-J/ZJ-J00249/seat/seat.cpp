#include <bits/stdc++.h>
using namespace std;
long long score[1005]={0};
long long seat[50][50]={0};
long long n,m;
int x,y;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>score[i];
	}
	int pos_score=score[1];
	sort(score+1,score+n*m+1,cmp);
	int pos;
	for (int i=1;i<=n*m;i++){
		if (score[i]==pos_score){
			pos=i;
			break;
		}
	}
	x=pos/n;
	y=pos%n;
	if (y!=0){
		x++;
	}
	if (x%2==1){
		if (y==0){
			y=n;
		}else{
			y=y;
		}
	}else{
		if (y==0){
			y=1;
		}else if(y==1){
			y=n;
		}else{
			y=n-y+1;
		}
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
