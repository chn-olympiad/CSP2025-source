#include<bits/stdc++.h>
using namespace std;
const int NUM=10000;
int n,m,sum=1;
struct seat{
	int num;
	int colour;
}a[15][15],b[NUM];
bool cmp(seat x,seat y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int ANS=n*m;
	for(int i=1;i<=ANS;i++){
		cin>>b[i].num;
	}
	b[1].colour=1;
	sort(b+1,b+ANS+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				a[j][i].num=b[sum].num;
				a[j][i].colour=b[sum].colour;
				sum++;
			}
		}else{
			for(int j=m;j>=1;j--){
				a[j][i].num=b[sum].num;
				a[j][i].colour=b[sum].colour;
				sum++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j].colour==1){
				cout<<j<<" "<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
