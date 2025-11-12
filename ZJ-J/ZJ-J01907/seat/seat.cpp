#include<bits/stdc++.h>
using namespace std;
struct stu{
	int score;
	int id;
};
stu a[105];
int seat[105][105];
int cmp(stu x,stu y){
	if(x.score>y.score)return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i].score;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int h=1,l=1;
	for(int i=1;i<=n*m;i++){
		seat[h][l]=a[i].id;
		if(l%2!=0){
			if(h==m)l++;
			else h++;
		}else{
			if(h==1)l++;
			else h--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==1){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}
