#include <bits/stdc++.h>
using namespace std;
int n,m;
int score[200],my_score,my_rank=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>score[i];
	}
	my_score=score[1];
	for(int i=2;i<=num;i++){
		if(score[i]>my_score){
			my_rank++;
		}
	}
	int x=(my_rank-1)/n+1,y=my_rank-n*(x-1);
	if(y==0){
		y=n;
	}
	int ans_x=x,ans_y;
	if(x%2==0){
		ans_y=n-y+1;
	}
	else{
		ans_y=y;
	}
	cout<<ans_x<<" "<<ans_y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
