#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int score[102];memset(score,0,sizeof(score));
	int seat[12][12];memset(seat,0,sizeof(seat));
	for(int i=1; i<=m*n; ++i) {
		cin>>score[i];
	}
	int r_score=score[1];
	sort(score+1,score+n*m+1,cmp);
	for(int i1=1; i1<=m; ++i1) {
		for(int j1=((i1%2==0)?n:1); ((i1%2==0)?(j1>=1):(j1<=n)); (i1%2==0?--j1:++j1)) {
			if(i1%2!=0)seat[j1][i1]=score[n*(1-1)+j1];
			else seat[j1][i1]=score[i1+n*(i1-1)];
		}
	}
	for(int i2=1; i2<=m; ++i2) {
		for(int j2=1; j2<=n; ++j2) {
			if(seat[j2][i2]==r_score) {
				cout<<j2<<' '<<i2;
				break;
			}
		}
	}
	return 0;
}
