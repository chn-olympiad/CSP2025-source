#include<bits/stdc++.h>
using namespace std;
struct st{
	int score;
	int pai;
	bool r=false;
};
bool cmp(st x1,st x2){
	return x1.score>x2.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	st stu[200];
	stu[1].r=true;
	for(int i=1;i<=n*m;i++){
		cin>>stu[i].score;
	}
	sort(stu+1,stu+(n*m)+1,cmp);
	int k=0;
	for(int i=1;i<=n*m;i++){
		stu[i].pai=i;
		if(stu[i].r==true){
			k=i;
		}
	}
	int num=0;
	int sx=0;
	for(int i=1;i<=m;i++){
		if(sx%2==0){
			for(int j=1;j<=n;j++){
				num++;
				if(num==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else if(sx%2==1){
			for(int j=n;j>=1;j--){
				num++;
				if(num==k){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		sx++;
	}
	return 0;
}
